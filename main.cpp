#include <SFML/Graphics.hpp>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int SIZE_X = 160;
const int SIZE_Y = 120;

const int CELL_SIZE_X = SCREEN_WIDTH  / SIZE_X;
const int CELL_SIZE_Y = SCREEN_HEIGHT / SIZE_Y;

bool isPressed = false;
short currentTool = 1;

struct Cell;
Cell cells[SIZE_Y][SIZE_X];

struct Cell 
{
    short id;
    sf::Color color;
};

void updateCells() {
    for (int i=SIZE_Y-1; i>-1; i--) {
        for (int j=0; j < SIZE_X; j++) {
            //sand
            if (cells[i][j].id == 1 && i != SIZE_Y-1) {
                //move it down

                if (cells[i][j].id == 1 && cells[i+1][j].id == 0) {
                    cells[i][j].id = 0;
                    cells[i+1][j].id = 1;
                }

                else if (cells[i+1][j].id == 1 && j>0 && cells[i+1][j-1].id == 0) {
                    cells[i][j].id = 0;
                    cells[i+1][j-1].id = 1;
                }

                else if (cells[i+1][j].id == 1 && j+1<SIZE_X && cells[i+1][j+1].id == 0) {
                    cells[i][j].id = 0;
                    cells[i+1][j+1].id = 1;
                }                
            }
        }
    }
}

void drawCells(sf::RenderWindow *w) {
    for (int i=0; i < SIZE_Y; i++) {
        for (int j=0; j < SIZE_X; j++) {
            if (cells[i][j].id  > 0) {
                    sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE_X, CELL_SIZE_X));
                    rectangle.setPosition(CELL_SIZE_X*j, CELL_SIZE_Y*i);
                    if (cells[i][j].id == 1) rectangle.setFillColor(sf::Color(194, 178, 128));
                    else if (cells[i][j].id == 2) rectangle.setFillColor(sf::Color(0, 0, 255));
                    w->draw(rectangle); 
            }
        }
    } 
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sand is cool...");
    window.setFramerateLimit(1444);

    Cell empty = {0, sf::Color(0,0,0)};
    for (int i=0; i<SIZE_Y; i++) { 
        for (int j=0; j<SIZE_X; j++) {
            cells[i][j] = empty;
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i position = sf::Mouse::getPosition(window);
            int x = position.x/CELL_SIZE_X;
            int y = position.y/CELL_SIZE_Y;
            cells[y][x] = {currentTool, sf::Color::Black};
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            currentTool = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            currentTool = 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
            currentTool = 0;
        }
        

        updateCells();
        drawCells(&window);

        window.display();
    }

    return 0;
}
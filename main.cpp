#include <iostream>
#include "cells.h"

bool isPressed = false;
short currentTool = 1;

Cell cells[SIZE_Y][SIZE_X];

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sand is cool...");
    window.setFramerateLimit(144);

    Cell empty = Cell{0, sf::Color(0,0,0)};
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

        updateCells(cells, SIZE_X, SIZE_Y);
        drawCells(cells, SIZE_X, SIZE_Y, &window);

        window.display();
    }

    return 0;
}

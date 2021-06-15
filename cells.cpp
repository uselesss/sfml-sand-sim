#include "cells.h"


void updateCells(Cell cells[SIZE_Y][SIZE_X], int SIZE_X, int SIZE_Y) {

    for (int i = SIZE_Y - 1; i > -1; --i) {
        for (int j = 0; j < SIZE_X; ++j) {
            //sand
            if (cells[i][j].id == 1 && i != SIZE_Y-1) {
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

void drawCells(Cell cells[SIZE_Y][SIZE_X], int SIZE_X, int SIZE_Y, sf::RenderWindow *w) {

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

#pragma once
#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int SIZE_X = 160;
const int SIZE_Y = 120;

const int CELL_SIZE_X = SCREEN_WIDTH  / SIZE_X;
const int CELL_SIZE_Y = SCREEN_HEIGHT / SIZE_Y;

struct Cell {
    short id;
    sf::Color color;
};

void updateCells(Cell cells[SIZE_Y][SIZE_X], int SIZE_X, int SIZE_Y);
void drawCells(Cell cells[SIZE_Y][SIZE_X], int SIZE_X, int SIZE_Y, sf::RenderWindow *w);
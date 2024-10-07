//
// Created by brenl on 25/09/2024.
//

#include <iostream>
#include "cell.h"
#include <random>

// Random number generator
inline std::random_device rd;
inline std::mt19937 gen(rd());
inline std::bernoulli_distribution distrib(0.4);


// Constructor
Cell::Cell(int row,int col) {
    DefineMines();
    changeAppearance();
    cellNumber = 0;
    pos = std::make_pair(row, col);
}

// Randomly assign a mine to the Cell
bool Cell::DefineMines() {
    mine = distrib(gen);
    return mine;
}

// Change the appearance of the Cell
void Cell::changeAppearance() {
    if (hidden) {
        appearance = "#";
    } else {
        if (mine) {
            appearance = "*";
        } else {
            appearance = std::to_string(cellNumber);
        }
    }
}


// getter for the cellNumber
int Cell::getCellNumber() const {
    return cellNumber;
}

// Increase the cell number property by 1
void Cell::increaseCellNumber() {
    cellNumber++;
    changeAppearance();
}

void Cell::disarmMine() {
    mine = false;
}
// Reveal the cell chosen by the player, changing the appearance by changing the hidden attribute
void Cell::revealCell() {
    revealed = true;
    hidden = false;
    changeAppearance();
}

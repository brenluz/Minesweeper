//
// Created by brenl on 26/09/2024.
//

#include "board.h"
#include <iostream>

board::board(const int size) {
    this->size = size;
    std::cout << "Creating board of size " << size << std::endl;
    createBoard();
    std::cout << "Board created" << std::endl;
    defineCellNumbers();
}

void board::createBoard() {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            list.emplace_back(i, j);
        }
    }
}

void board::printBoard() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << list[i*size + j].appearance;
        }
        std::cout << std::endl;
    }
}

void board::defineCellNumbers() const {
    std::vector<Cell> adjacentCells;
    for (int i = 0; i < list.size(); i++) {
        for(int j = 0; j < list.size(); j+=size) {
            if(i == j) {
                adjacentCells.emplace_back(list[i+1]);
                adjacentCells.emplace_back(list[i-size+1]);
                adjacentCells.emplace_back(list[i+size+1]);
            }
        }
        for (int j = 1; j < list.size()-size; j+=size) {
            if(i == j) {
                adjacentCells.emplace_back(list[i-1]);
                adjacentCells.emplace_back(list[i-size-1]);
                adjacentCells.emplace_back(list[i+size-1]);
            }
        }
        if(i > size) {
            adjacentCells.emplace_back(list[i-size]);
        }
        if(i < list.size()-size) {
            adjacentCells.emplace_back(list[i+size]);
        }
    }
    for (const auto& currentCell : list) {
        if(currentCell.mine) {
            for (auto & adjacentCell : adjacentCells) {
                adjacentCell.increaseCellNumber();
            }
        }
    }
}


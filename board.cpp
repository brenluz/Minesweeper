//
// Created by Brenl on 26/09/2024.
//

#include "board.h"

#include <functional>
#include <iostream>
// Constructor
board::board(const int size) {
    this->size = size;
    std::cout << "Creating board of size " << size << std::endl;
    createBoard();
    std::cout << "Board created" << std::endl;
    defineCellNumbers();
    std::cout << "Cell numbers defined" << std::endl;
}

// Create the board
void board::createBoard() {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            list.emplace_back(i, j);
        }
    }
}

// Print the board
void board::printBoard() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << list[i*size + j].appearance;
        }
        std::cout << std::endl;
    }
}

void board::revealCell(const int row, const int col) {
    list[row*size+col].revealCell();
    }

// Define os numeros das celulas verificando se as celulas adjacentes sao minas
void board::defineCellNumbers() {
    changeAllAdjacent(list[], &Cell::increaseCellNumber);
}

void board::changeAllAdjacent(const bool cond, void (Cell::*method)()) {
    for (int i = 0; i < list.size(); i++) {
        if(cond) {
            // calculando adjacentes para direita
            if(i % size != size-1) { // direita
                list[1+i].*method();
                if(i > size) { // direita em cima
                    list[i-size+1].*method();
                }
                if(i < list.size() - size) { // direita em baixo
                    list[i+size+1].*method();
                }
            }
            // calculando adjacentes para esquerda
            if(i % size != 0) { // esquerda
                list[i-1].*method();
                if(i > size) { // esquerda em cima
                    list[i-size-1].*method();
                }
                if(i < list.size() - size) { // esquerda em baixo
                    list[i+size-1].*method();
                }
            }
            //cima e baixo
            if(i > size) { // cima
                list[i-size].*method();
            }
            if(i < list.size() - size) { // baixo
                list[i+size].*method();
            }
        }
    }
}
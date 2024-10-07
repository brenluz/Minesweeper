//
// Created by brenl on 26/09/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Cell.h"


class board {
    int size;
    void changeAllAdjacent(bool cond, void (Cell::*method)());
    void createBoard();
    void defineCellNumbers();

    // static void raiseAdjacent(int mineIndex);
public:
    void revealCell(int row, int col);
    std::vector<Cell> list;
    explicit board(int size);
    void printBoard() const;
};



#endif //BOARD_H

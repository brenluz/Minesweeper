//
// Created by brenl on 25/09/2024.
//

#include "cell.h"
#include <random>


inline std::random_device rd;
inline std::mt19937 gen(rd());
inline std::bernoulli_distribution distrib(0.5);

cell::cell(int row,int col) {
    isMine();
    changeAppearance(hidden, mine);
    cellNumber = 0;
    pos = std::make_pair(row, col);
}

bool cell::isMine() {
    mine = distrib(gen);
    return mine;
}

void cell::changeAppearance(const bool _hidden, const bool _mine) {
    if (_hidden) {
        appearance = "#";
    } else {
        if (_mine) {
            appearance = "*";
        } else {
            appearance = std::to_string(cellNumber);
        }
    }
}

int adjacentCheck(const std::pair<int,int>& cur, const std::pair<int,int>& prev, bool mine, int number);

void cell::CellNumber(const std::vector<cell>& board, const std::pair<int,int>& pos) {
    for (int i = 1; i < board.size(); i++) {
        const bool mine = board[i].mine;
        cellNumber = adjacentCheck(pos, board[i].pos, mine, cellNumber);
    }
}

int horizontalCheck(const std::pair<int,int> &cur, const std::pair<int,int> &prev, bool mine, int number);
int verticalCheck(const std::pair<int,int> &cur, const std::pair<int,int> &prev, bool mine, int number);

int adjacentCheck(const std::pair<int,int> &cur, const std::pair<int,int> &prev, const bool mine, int number) {
    horizontalCheck(cur, prev, mine, number);
    verticalCheck(cur, prev, mine, number);
    return number;
}

int horizontalCheck(const std::pair<int,int> &cur, const std::pair<int,int> &prev, const bool mine, int number) {
    if (cur.second == prev.second) {
        if (cur.first == prev.first + 1) {
            if(mine) {
                number++;
            }
        }
    }
    if(cur.second == prev.second) {
        if(cur.first == prev.first - 1) {
            if(mine) {
                number++;
            }
        }
    }
    return number;
}

int verticalCheck(const std::pair<int, int> &cur, const std::pair<int, int> &prev, const bool mine, int number) {
    if (cur.first == prev.first) {
        if (cur.second == prev.second + 1) {
            if(mine) {
                number++;
            }
        }
    }
    if(cur.first == prev.first) {
        if(cur.second == prev.second - 1) {
            if(mine) {
                number++;
            }
        }
    }
    return number;
}

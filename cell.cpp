//
// Created by brenl on 25/09/2024.
//

#include "cell.h"
#include <random>


inline std::random_device rd;
inline std::mt19937 gen(rd());
inline std::bernoulli_distribution distrib(0.5);

void cell::isMine() {
    mine = distrib(gen);
}

void cell::changeAppearance(const bool _hidden, const bool _mine) {
    if (_hidden) {
        appearance = "#";
    } else {
        if (_mine) {
            appearance = "*";
        } else {
            appearance = std::to_string(adjacentMines);
        }
    }
}

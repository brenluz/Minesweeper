#include <iostream>
#include <vector>
#include "cell.h"

int main() {
    int size;
    int count = 0;
    std::cout << "Enter the size of the board:";
    std::cin >> size;
    std::vector <cell> board;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            board.emplace_back(i, j);
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << board[count].appearance;
            count++;
        }
        std::cout << std::endl;
    }
    return 0;
}

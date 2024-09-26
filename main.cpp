#include <iostream>
#include <vector>
#include "cell.h"

void printBoard(int count, int size, const std::vector<cell> &board);

int main() {
    int size;
    // ReSharper disable once CppLocalVariableMayBeConst
    int count = 0;
    std::cout << "Enter the size of the board:";
    std::cin >> size;
    std::vector <cell> board;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            board.emplace_back(i, j);
        }
    }
    printBoard(count, size, board);
    int x = 0,y = 0;
    cell currentCell = board[x*size + y];
    while(currentCell.mine == false) {
        std::cin >> x >> y;
        board[x*size + y].changeAppearance(false);
        printBoard(count, size, board);
        currentCell = board[x*size + y];
    }
    std::cout << "Game Over";
    return 0;
}

void printBoard(int count, const int size, const std::vector<cell> &board) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << board[count].appearance;
            count++;
        }
        std::cout << std::endl;
    }
}
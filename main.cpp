#include <iostream>
#include "board.h"
#include "cell.h"
bool play();

int main() {
    int size;
    while(play()) {
        std::cout << "Enter the size of the board:";
        std::cin >> size;
        board game(size);
        game.printBoard();
        int row, col;
        std::cout << "enter the first cell" << std::endl;
        std::cin >> row >> col;
        Cell currentCell = game.list[row*size+col];
        while(currentCell.mine == false) {
            game.list[row*size+col].changeAppearance(false);
            game.printBoard();
            std::cout << "enter the next cell" << std::endl;
            std::cin >> row >> col;
            currentCell = game.list[row*size+col];
        }
        game.list[row*size+col].changeAppearance(false);
        game.printBoard();
        std::cout << "You hit a mine! Game Over" << std::endl;
    }
    return 0;
}

// ReSharper disable once CppNotAllPathsReturnValue
auto play() -> bool{
    std::cout << "Do you want to play? (y/n):";
    char answer;
    std::cin >> answer;
    if (answer == 'n' or answer =='N') {
        return false;
    }
    if(answer == 'y' or answer == 'Y') {
        return true;
    }
    std::cout << "Invalid input. Turning off." << std::endl;
    return false;
}

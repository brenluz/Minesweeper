//
// Created by brenl on 25/09/2024.
//

#ifndef CELL_H
#define CELL_H

#include <string>
#include <vector>


class Cell {
    int cellNumber = 0;
    bool hidden = true;
    bool DefineMines();
    bool revealed = true;

public:
    explicit Cell(int row, int col);

    std::string appearance;
    bool mine = false;
    std::pair<int, int> pos;
    void disarmMine();
    void increaseCellNumber();
    void changeAppearance();
    void revealCell();

    [[nodiscard]] int getCellNumber() const;

};


#endif //CELL_H

//
// Created by brenl on 25/09/2024.
//

#ifndef CELL_H
#define CELL_H

#include <string>
#include <vector>


class Cell {
    int cellNumber;
    bool hidden = true;
    bool DefineMines();

public:
    explicit Cell(int row, int col);

    std::string appearance;
    bool mine = false;
    std::pair<int, int> pos;
    void increaseCellNumber();
    void changeAppearance(bool hidden);

    [[nodiscard]] int getCellNumber() const;

};


#endif //CELL_H

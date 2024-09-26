//
// Created by brenl on 25/09/2024.
//

#ifndef CELL_H
#define CELL_H

#include <string>
#include <vector>


class cell {
    int cellNumber;
    bool hidden = true;
    void CellNumber(const std::vector<cell>&, const std::pair<int, int> &pos);
    bool isMine();
    std::pair<int, int> pos;
public:
    std::string appearance;
    explicit cell(int row, int col);
    void changeAppearance(bool hidden);
    bool mine = false;
    [[nodiscard]] int getCellNumber() const;
};


#endif //CELL_H

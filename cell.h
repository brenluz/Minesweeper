//
// Created by brenl on 25/09/2024.
//

#ifndef CELL_H
#define CELL_H

#include <string>



class cell {
    bool hidden = true;
    bool mine = false;
    int adjacentMines;
    cell() {
        isMine();
        adjacentMines = 0;
    }
public:
    std::string appearance;
    void isMine();
    void changeAppearance(bool _hidden, bool _mine);
};


#endif //CELL_H

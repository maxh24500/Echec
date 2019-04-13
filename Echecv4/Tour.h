#pragma once

#include "Piece.h"

class Tour : public Piece {
public:
    Tour();
    Tour(int id, int positionX, int positionY, bool blanc);
    void mouv(int cas, int nbCase);
    virtual bool deplacement(int X, int Y);
};
#pragma once

#include "Piece.h"

class Reine : public Piece{
public:
    Reine(int id, int positionX, int positionY, bool blanc);
    void mouv(int cas, int nbCase);
    virtual bool deplacement(int X, int Y);
};

#pragma once

#include "Piece.h"

class Roi : public Piece{
public:
    Roi(int id, int positionX, int positionY, bool blanc);
    void mouv(int cas);
    virtual bool deplacement(int X, int Y, Piece *unTableau);
};
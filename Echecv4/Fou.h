#pragma once

#include "Piece.h"

class Fou : public Piece {
public:
    Fou(int id, int positionX, int positionY, bool blanc);
    virtual bool deplacement(int X, int Y, Piece *unTableau);
};
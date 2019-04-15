#pragma once

#include "Piece.h"

class Tour : public Piece {
private:
	
public:
    Tour();
    Tour(int id, int positionX, int positionY, bool blanc);
    virtual bool deplacement(int X, int Y, Piece *unTableau);
};
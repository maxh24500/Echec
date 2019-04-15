#pragma once

#include "Piece.h"

class Roi : public Piece{
private:
	
public:
    Roi(int id, int positionX, int positionY, bool blanc);
    virtual bool deplacement(int X, int Y, Piece *unTableau);
};
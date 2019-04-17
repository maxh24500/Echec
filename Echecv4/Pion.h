#pragma once
#include "Piece.h"

class Pion : public Piece {
private:
	
public:
    Pion(int id, int positionX, int positionY, bool blanc);
	virtual bool deplacement(int X, int Y, Piece *unTableau);
};
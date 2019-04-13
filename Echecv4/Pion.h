#pragma once

#include "Piece.h"

class Pion : public Piece {
private:
	int nbTour = 0;
public:
    Pion(int id, int positionX, int positionY, bool blanc);
    void mouv(int cas);
	virtual bool deplacement(int X, int Y);
};
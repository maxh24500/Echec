#pragma once
#include "Piece.h"
#include "Pion.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Tour.h"
#include "Roi.h"
#include "Reine.h"

class Jeu
{
	Piece* appelTableau;
public:
	Jeu();
	~Jeu();
	std::string pieceAt(int X, int Y);
	bool deplacement(int fromX,int fromY, int toX, int toY);
	void lancerJeu();
};
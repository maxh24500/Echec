#pragma once

#include "Piece.h"

class Roi : public Piece {
private:

public:
	Roi(int id, int positionX, int positionY, bool blanc);
	virtual bool deplacement(int X, int Y, Piece *unTableau);
	bool calculEchec(Piece *appelPlateau, bool couleurJoueur);
	bool calculEchecEtMat(Piece *appelPlateau, bool couleurJoueur);
	int testCavalier(int x, int y, Piece *appelPlateau, bool couleurJoueur);
	int testTour(int x, int y, Piece *appelPlateau, bool couleurJoueur);
	int testFou(int x, int y, Piece *appelPlateau, bool couleurJoueur);
	int testPion(int x, int y, Piece *appelPlateau, bool couleurJoueur);
	void msgEchec(Piece *appelPlateau,bool couleurJoueur);
};
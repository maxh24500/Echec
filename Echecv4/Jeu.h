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
    bool finPartie;
    bool Blanc;
    Piece* laPiece1;
    Piece* laPiece2;
    Piece* caseVide;

    bool enJeu;
    bool Joueur1;
    bool whiteWins;
    bool blackWins;

public:
	Jeu();
	~Jeu();
	std::string pieceAt(int X, int Y);
	bool deplacement(int fromX,int fromY, int toX, int toY);
    bool canPlay(int X, int Y);
	void lancerJeu();

    bool isFinPartie();
    bool isWhiteWins();
    bool isBlackwins();
};

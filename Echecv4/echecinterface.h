#ifndef ECHECINTERFACE_H
#define ECHECINTERFACE_H

#include "Piece.h"
#include "Pion.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Roi.h"
#include "Reine.h"


class EchecInterface
{
private:
    Piece *appelTableau;
    Piece *caseVide;
    bool finPartie = false;
    bool joueurBlanc = true;

public:
    EchecInterface();
    void SetupBoard();
    Piece *getPiece(int positionX, int positionY);
    bool canTake(Piece *thisPiece, int positionX, int positionY);
    bool movePiece(Piece *thisPiece, int positionX, int positionY);
    bool isWhitePlayer();
    bool switchPlayer();
};

#endif // ECHECINTERFACE_H

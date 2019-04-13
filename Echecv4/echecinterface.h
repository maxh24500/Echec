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
public:
    EchecInterface();
    void SetupBoard();
    Piece *getPiece(int positionX, int positionY);
};

#endif // ECHECINTERFACE_H
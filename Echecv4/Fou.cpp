#include "pch.h"
#include "Fou.h"

Fou::Fou(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;

    if (!blanc){
        this->_nom = "fou_n";
    } else {
        this->_nom = "fou_b";
    }
}

void Fou::mouv(int cas, int nbCase){

    int positionX = this->_position.first;
    int positionY = this->_position.second;

    pair <int, int> nouvellePosition;

    switch (cas) {

        case 1 :
            nouvellePosition.first = positionX - nbCase;
            nouvellePosition.second = positionY + nbCase;
            break;

        case 2 :
            nouvellePosition.first = positionX + nbCase;
            nouvellePosition.second = positionY + nbCase;
            break;

        case 3 :
            nouvellePosition.first = positionX + nbCase;
            nouvellePosition.second = positionY - nbCase;
            break;

        case 4 :
            nouvellePosition.first = positionX - nbCase;
            nouvellePosition.second = positionY - nbCase;
            break;
    }
    this->setPosition(nouvellePosition);
}

bool Fou::deplacement(int X, int Y)
{
    int total1;
    int total2;
    total1 = X - this->_position.first;
    total2 = Y - this->_position.second;
    if (total1 < 0)
    {
        total1 = total1 * -1;
    }
    if (total2 < 0)
    {
        total2 = total2 * -1;
    }

    if (total1 == total2)
    {
        this->_position.first = X;
        this->_position.second = Y;
        return true;
    }
    else
    {
        return false;
    }

}

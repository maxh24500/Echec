#include "pch.h"
#include "Tour.h"

Tour::Tour()
{
}

Tour::Tour(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;

    if (!blanc){
        this->_nom = "tn ";
        this->_type = pieceTourNoir;
    } else {
        this->_nom = "tn ";
        this->_type = pieceTourBlanc;
    }
}

void Tour::mouv(int cas, int nbCase){

    int positionX = this->_position.first;
    int positionY = this->_position.second;

    pair <int, int> nouvellePosition;

    switch (cas) {

        case 1 :
            nouvellePosition.first = positionX;
            nouvellePosition.second = positionY + nbCase;
            break;

        case 2 :
            nouvellePosition.first = positionX + nbCase;
            nouvellePosition.second = positionY;
            break;

        case 3 :
            nouvellePosition.first = positionX;
            nouvellePosition.second = positionY - nbCase;
            break;

        case 4 :
            nouvellePosition.first = positionX - nbCase;
            nouvellePosition.second = positionY;
            break;
    }
    this->setPosition(nouvellePosition);
}

bool Tour::deplacement(int X, int Y)
{
    if (X != this->_position.first && Y != this->_position.second)
    {
        cout << "Erreur dans le mouvement de la piece, reessayez : "<<endl;
        return false;

    }
    else if (X == this->_position.first && Y == this->_position.second)
    {
        cout << "La pi�ce n'a pas boug� ! reessayez : " << endl;
        return false;
    }
    else if (X > this->_position.first && Y == this->_position.second)
    {
        this->_position.first = X;
        return true;

    }
    else if (X == this->_position.first && Y > this->_position.second)
    {
        this->_position.second = Y;
        return true;
    }
    else if (X == this->_position.first && Y < this->_position.second)
    {
        this->_position.second = Y;
        return true;
    }
    else if (X < this->_position.first && Y == this->_position.second)
    {
        this->_position.first = X;
        return true;
    }

}

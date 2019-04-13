#include "pch.h"
#include "Pion.h"

Pion::Pion(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;

    if (!blanc){
        this->_type = piecePionNoir;
        this->_nom = "pio_n";
    } else {
        this->_type = piecePionBlanc;
        this->_nom = "pio_b";
    }
}

void Pion::mouv(int cas){
    int positionX = this->_position.first;
    int positionY = this->_position.second;

    pair <int, int> nouvellePosition;

    switch (cas) {

        case 1 :
            nouvellePosition.first = positionX + 1;
            nouvellePosition.second = positionY;
            break;

        case 2 :
            nouvellePosition.first = positionX + 2;
            nouvellePosition.second = positionY;
            break;

        case 3 :
            nouvellePosition.first = positionX + 1;
            nouvellePosition.second = positionY + 1;
            break;

        case 4 :
            nouvellePosition.first = positionX + 1;
            nouvellePosition.second = positionY - 1;
            break;
    }
    this->setPosition(nouvellePosition);
}


bool Pion::deplacement(int X, int Y) {
		if (X == this->_position.first + 1 && Y == this->_position.second)
		{
			this->_position.first = X;
			this->_position.second = Y;
			this->nbTour++;
			return true;

		}
		else if (this->nbTour == 0 && X == this->_position.first + 2 && Y == this->_position.second)
		{
			this->_position.first = X;
			this->_position.second = Y;
			this->nbTour++;
			return true;

		}
		else
		{
			cout << "Erreur de mouvement, reessayez" << endl;
			return false;
		}
	
}
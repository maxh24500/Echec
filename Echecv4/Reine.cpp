#include "pch.h"
#include "Reine.h"

Reine::Reine(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;

    if (!blanc){
        this->_nom = "rei_n";
        this->_type = pieceReineNoir;
    } else {
        this->_nom = "rei_b";
        this->_type = pieceReineBlanc;
    }
}

void Reine::mouv(int cas, int nbCase){

    int positionX = this->_position.first;
    int positionY = this->_position.second;

    pair <int, int> nouvellePosition;

    switch (1) {

        case 1 :
            nouvellePosition.first = positionX - nbCase;
            nouvellePosition.second = positionY + nbCase;
            break;

        case 2 :
            nouvellePosition.first = positionX;
            nouvellePosition.second = positionY + nbCase;
            break;

        case 3 :
            nouvellePosition.first = positionX + nbCase;
            nouvellePosition.second = positionY + nbCase;
            break;

        case 4 :
            nouvellePosition.first = positionX + nbCase;
            nouvellePosition.second = positionY;
            break;

        case 5 :
            nouvellePosition.first = positionX + nbCase;
            nouvellePosition.second = positionY - nbCase;
            break;

        case 6 :
            nouvellePosition.first = positionX;
            nouvellePosition.second = positionY - nbCase;
            break;

        case 7 :
            nouvellePosition.first = positionX - nbCase;
            nouvellePosition.second = positionY - nbCase;
            break;

        case 8 :
            nouvellePosition.first = positionX - 1;
            nouvellePosition.second = positionY;
            break;
    }
    this->setPosition(nouvellePosition);
}

bool Reine::deplacement(int X, int Y) {
	
		//MOUVEMENT DU FOU
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

		//MOUVEMENT DE LA TOUR
		if (X > this->_position.first && Y == this->_position.second)
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
		else
		{
			cout << "Erreur de mouvement, reessayez" << endl;
			return false;
		}
	
}

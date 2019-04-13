#include "pch.h"
#include "Roi.h"

Roi::Roi(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;

    if (!blanc){
        this->_nom = "roi_n";
    } else {
        this->_nom = "roi_b";
    }
}

void Roi::mouv(int cas){

    int positionX = this->_position.first;
    int positionY = this->_position.second;

    pair <int, int> nouvellePosition;

    switch (1) {

        case 1 :
            nouvellePosition.first = positionX - 1;
            nouvellePosition.second = positionY + 1;
            break;

        case 2 :
            nouvellePosition.first = positionX;
            nouvellePosition.second = positionY + 1;
            break;

        case 3 :
            nouvellePosition.first = positionX + 1;
            nouvellePosition.second = positionY + 1;
            break;

        case 4 :
            nouvellePosition.first = positionX + 1;
            nouvellePosition.second = positionY;
            break;

        case 5 :
            nouvellePosition.first = positionX + 1;
            nouvellePosition.second = positionY - 1;
            break;

        case 6 :
            nouvellePosition.first = positionX;
            nouvellePosition.second = positionY - 1;
            break;

        case 7 :
            nouvellePosition.first = positionX - 1;
            nouvellePosition.second = positionY - 1;
            break;

        case 8 :
            nouvellePosition.first = positionX - 1;
            nouvellePosition.second = positionY;
            break;
    }
    this->setPosition(nouvellePosition);
}

bool Roi::deplacement(int X, int Y){
	
		if (X > this->_position.first + 1 || Y > this->_position.second + 1 || X < this->_position.first - 1 || Y < this->_position.second - 1)
		{
			cout << "Erreur de mouvement, reessayez" << endl;
			return false;
		}
		else
		{
			this->_position.first = X;
			this->_position.second = Y;
			return true;
		}
	

}
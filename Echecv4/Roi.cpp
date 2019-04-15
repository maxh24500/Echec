#include "pch.h"
#include "Roi.h"

Roi::Roi(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;

    if (!blanc){
        this->_nom = "R_n";
    } else {
        this->_nom = "R_b";
    }
}

bool Roi::deplacement(int X, int Y, Piece *unTableau)
{
	
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
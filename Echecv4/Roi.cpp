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
	//PETIT ROQUE
	if (X == this->_position.first && Y == this->_position.second + 2 && this->nbTour == 0)
	{
		
		if (unTableau->listePiece[X][Y + 1]->getEstTour() == true && unTableau->listePiece[X][Y + 1]->getNbTour() == 0)
		{
			
			if (unTableau->listePiece[X][Y - 1]->getEstBlanc() == true || unTableau->listePiece[X][Y - 1]->getEstBlanc() == false)
			{
				
				return false;
			}
			else
			{
				this->_position.second = Y;
				unTableau->listePiece[X][Y + 1]->setPosition(X, Y - 1);
				unTableau->listePiece[X][Y - 1] = unTableau->listePiece[X][Y + 1];
				Piece *caseVide = new Piece();
				caseVide->setEnJeu(false);
				unTableau->listePiece[X][Y + 1] = caseVide;
				this->nbTour++;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	//GRAND ROQUE
	else if (X == this->_position.first && Y == this->_position.second - 3 && this->nbTour == 0)
	{

		if (unTableau->listePiece[X][Y - 1]->getEstTour() == true && unTableau->listePiece[X][Y - 1]->getNbTour() == 0)
		{

			if (unTableau->listePiece[X][Y + 1]->getEstBlanc() == true || unTableau->listePiece[X][Y + 1]->getEstBlanc() == false)
			{

				return false;
			}
			else if (unTableau->listePiece[X][Y + 2]->getEstBlanc() == true || unTableau->listePiece[X][Y + 2]->getEstBlanc() == false)
			{
				return false;
			}
			else
			{
				this->_position.second = Y;
				unTableau->listePiece[X][Y - 1]->setPosition(X, Y + 1);
				unTableau->listePiece[X][Y + 1] = unTableau->listePiece[X][Y - 1];
				Piece *caseVide = new Piece();
				caseVide->setEnJeu(false);
				unTableau->listePiece[X][Y - 1] = caseVide;
				this->nbTour++;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	//MOUVEMENT NORMAL
	else if (X > this->_position.first + 1 || Y > this->_position.second + 1 || X < this->_position.first - 1 || Y < this->_position.second - 1)
	{
		cout << "Erreur de mouvement, reessayez" << endl;
		return false;
	}
	else
	{
		this->_position.first = X;
		this->_position.second = Y;
		this->nbTour++;
		return true;
	}
	

}
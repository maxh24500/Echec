#include "pch.h"
#include "Pion.h"
#include "Piece.h"
#include "Cavalier.h"



Pion::Pion(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;

    if (!blanc){
        this->_nom = "p_n";
    } else {
        this->_nom = "p_b";
    }
}
bool Pion::deplacement(int X, int Y, Piece *unTableau) 
{
	Piece *Pieceverif = new Piece();
	if (this->getEstBlanc() == true)
	{
		if (X == this->_position.first + 1 && Y == this->_position.second)
		{
			if (unTableau->listePiece[X][Y]->getEstBlanc() == true || unTableau->listePiece[X][Y]->getEstBlanc() == false)
			{
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
		else if (this->nbTour == 0 && X == this->_position.first + 2 && Y == this->_position.second)
		{
			if (unTableau->listePiece[X - 1][Y]->getEstBlanc() == true || unTableau->listePiece[X - 1][Y]->getEstBlanc() == false)
			{
				return false;
			}
			else
			{
				if (unTableau->listePiece[X][Y]->getEstBlanc() == true || unTableau->listePiece[X][Y]->getEstBlanc() == false)
				{
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

		}
		else if (X == this->_position.first + 1 && Y == this->_position.second + 1 || X == this->_position.first + 1 && Y == this->_position.second - 1)
		{
			
			Pieceverif = unTableau->listePiece[X][Y];
			if (Pieceverif->getEstBlanc() == false)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			cout << "Erreur de mouvement, reessayez" << endl;
			return false;
		}
	}
	else
	{
		if (X == this->_position.first - 1 && Y == this->_position.second)
		{
			if (unTableau->listePiece[X][Y]->getEstBlanc() == true || unTableau->listePiece[X][Y]->getEstBlanc() == false)
			{
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
		else if (this->nbTour == 0 && X == this->_position.first - 2 && Y == this->_position.second)
		{
			if (unTableau->listePiece[X + 1][Y]->getEstBlanc() == true || unTableau->listePiece[X + 1][Y]->getEstBlanc() == false)
			{
				return false;
			}
			else
			{
				if (unTableau->listePiece[X][Y]->getEstBlanc() == true || unTableau->listePiece[X][Y]->getEstBlanc() == false)
				{
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
		}
		else if (X == this->_position.first - 1 && Y == this->_position.second - 1 || X == this->_position.first - 1 && Y == this->_position.second + 1)
		{
			Pieceverif = unTableau->listePiece[X][Y];
			if (Pieceverif->getEstBlanc() == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			cout << "Erreur de mouvement, reessayez" << endl;
			return false;
		}
	}
}
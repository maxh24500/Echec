#include "pch.h"
#include "Pion.h"
#include "Piece.h"
#include "Cavalier.h"
#include "Reine.h"



Pion::Pion(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;
	this->_type = "pion";

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
		//+1 pas
		if (X == this->_position.first + 1 && Y == this->_position.second)
		{
			
			if (unTableau->listePiece[X][Y]->getEnJeu() == true)
			{
				return false;
			}
			else
			{
				this->_position.first = X;
				this->_position.second = Y;
				this->nbTour++;
				bool doublePas = false;;
				this->setDoublePas(doublePas);
				return true;
			}
		}
		//+2 pas
		
		else if (this->nbTour == 0 && X == this->_position.first + 2 && Y == this->_position.second)
		{
			if (unTableau->listePiece[X - 1][Y]->getEnJeu() == true)
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
					bool doublePas = true;
					this->setDoublePas(doublePas);
					return true;
				}
			}

		}
		//DIAGONALE
		else if (X == this->_position.first + 1 && Y == this->_position.second + 1 || X == this->_position.first + 1 && Y == this->_position.second - 1)
		{
			
			//GESTION DE LA PRISE EN PASSANT
			if (X == this->_position.first + 1 && Y == this->_position.second + 1 && unTableau->listePiece[X - 1][Y]->getType() == "pion")
			{
				
				if (unTableau->listePiece[X - 1][Y]->getDoublePas() == true && unTableau->listePiece[X - 1][Y]->getEstBlanc() == false)
				{
				
					Piece *caseVide = new Piece();
					caseVide->setEnJeu(false);
					unTableau->listePiece[X - 1][Y] = caseVide;
					this->_position.first = X;
					this->_position.second = Y;
					this->nbTour++;
					bool doublePas = false;
					this->setDoublePas(doublePas);
					return true;
				}
			}
			//GESTION DE LA PRISE EN PASSANT
			else if (X == this->_position.first + 1 && Y == this->_position.second - 1 && unTableau->listePiece[X - 1][Y]->getType() == "pion" && unTableau->listePiece[X - 1][Y]->getEstBlanc() == false)
			{
				if (unTableau->listePiece[X - 1][Y]->getDoublePas() == true)
				{
					Piece *caseVide = new Piece();
					caseVide->setEnJeu(false);
					unTableau->listePiece[X - 1][Y] = caseVide;
					this->_position.first = X;
					this->_position.second = Y;
					this->nbTour++;
					bool doublePas = false;
					this->setDoublePas(doublePas);
					return true;
				}
			}
			//DIAGONALE
			Pieceverif = unTableau->listePiece[X][Y];
			if (Pieceverif->getEstBlanc() == false)
			{
				this->_position.first = X;
				this->_position.second = Y;
				this->nbTour++;
				bool doublePas = false;
				this->setDoublePas(doublePas);
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
	//NOIR
	else
	{
		//+1 pas
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
				this->setDoublePas(false);
				return true;
			}

		}
		//+2 pas
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
					this->setDoublePas(true);
					return true;
				}
			}
		}
		//DIAGONALE
		else if (X == this->_position.first - 1 && Y == this->_position.second - 1 || X == this->_position.first - 1 && Y == this->_position.second + 1)
		{
			//GESTION DE LA PRISE EN PASSANT
			if (X == this->_position.first - 1 && Y == this->_position.second + 1 && unTableau->listePiece[X + 1][Y]->getType() == "pion")
			{
				if (unTableau->listePiece[X + 1][Y]->getDoublePas() == true && unTableau->listePiece[X - 1][Y]->getEstBlanc() == true)
				{
					Piece *caseVide = new Piece();
					caseVide->setEnJeu(false);
					unTableau->listePiece[X + 1][Y] = caseVide;
					this->_position.first = X;
					this->_position.second = Y;
					this->nbTour++;
					this->setDoublePas(false);
					return true;
				}
			}
			//GESTION DE LA PRISE EN PASSANT
			else if (X == this->_position.first - 1 && Y == this->_position.second - 1 && unTableau->listePiece[X + 1][Y]->getType() == "pion")
			{
				if (unTableau->listePiece[X + 1][Y]->getDoublePas() == true && unTableau->listePiece[X - 1][Y]->getEstBlanc() == true)
				{
					Piece *caseVide = new Piece();
					caseVide->setEnJeu(false);
					unTableau->listePiece[X + 1][Y] = caseVide;
					this->_position.first = X;
					this->_position.second = Y;
					this->nbTour++;
					this->setDoublePas(false);
					return true;
				}
			}
			Pieceverif = unTableau->listePiece[X][Y];
			if (Pieceverif->getEstBlanc() == true)
			{
				this->_position.first = X;
				this->_position.second = Y;
				this->nbTour++;
				this->setDoublePas(false);
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
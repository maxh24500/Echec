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
	this->_estTour = true;

    if (!blanc){
        this->_nom = "t_n";
    } else {
        this->_nom = "t_b";
    }
}

bool Tour::deplacement(int X, int Y, Piece *unTableau)
{
    if (X != this->_position.first && Y != this->_position.second)
    {
        return false;

    }
    else if (X == this->_position.first && Y == this->_position.second)
    {
        return false;
    }
    else if (X > this->_position.first && Y == this->_position.second)
    {
		for (int i = X - 1; i > this->_position.first; i--)
		{
			if (unTableau->listePiece[i][Y]->getEstBlanc() == true || unTableau->listePiece[i][Y]->getEstBlanc() == false)
			{
				return false;
			}
		}
        this->_position.first = X;
		this->nbTour++;
        return true;

    }
    else if (X == this->_position.first && Y > this->_position.second)
    {
		for (int i = Y - 1; i > this->_position.second; i--)
		{
			if (unTableau->listePiece[X][i]->getEstBlanc() == true || unTableau->listePiece[X][i]->getEstBlanc() == false)
			{
				return false;
			}
		}
        this->_position.second = Y;
		this->nbTour++;
        return true;
    }
    else if (X == this->_position.first && Y < this->_position.second)
    {
		for (int i = Y + 1; i < this->_position.second; i++)
		{
			if (unTableau->listePiece[X][i]->getEstBlanc() == true || unTableau->listePiece[X][i]->getEstBlanc() == false)
			{
				return false;
			}
		}
        this->_position.second = Y;
		this->nbTour++;
        return true;
    }
    else if (X < this->_position.first && Y == this->_position.second)
    {
		for (int i = X + 1; i < this->_position.first; i++)
		{
			if (unTableau->listePiece[i][Y]->getEstBlanc() == true || unTableau->listePiece[i][Y]->getEstBlanc() == false)
			{
				return false;
			}
		}
        this->_position.first = X;
		this->nbTour++;
        return true;
    }

}

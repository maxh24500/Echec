#include "pch.h"
#include "Reine.h"

Reine::Reine(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;
	this->_type = "reine";

    if (!blanc){
        this->_nom = "r_n";
    } else {
        this->_nom = "r_b";
    }
}


bool Reine::deplacement(int X, int Y, Piece *unTableau) 
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
		//- et -
		if (X < this->_position.first && Y < this->_position.second)
		{
			int j = Y + 1;
			for (int i = X + 1; i < this->_position.first; i++)
			{

				if (unTableau->listePiece[i][j]->getEnJeu() == true)
				{
					return false;
				}

				if (j < this->_position.second)
				{
					j++;
				}
			}
			this->_position.first = X;
			this->_position.second = Y;
			return true;

		}

		//+ et -
		else if (X > this->_position.first && Y < this->_position.second)
		{
			int j = Y + 1;
			for (int i = X - 1; i > this->_position.first; i--)
			{

				if (unTableau->listePiece[i][j]->getEnJeu() == true)
				{
					return false;
				}

				if (j < this->_position.second)
				{
					j++;
				}
			}
			this->_position.first = X;
			this->_position.second = Y;
			return true;
		}
		//- et +
		else if (X < this->_position.first && Y > this->_position.second)
		{
			int j = Y - 1;
			for (int i = X + 1; i < this->_position.first; i++)
			{

				if (unTableau->listePiece[i][j]->getEnJeu() == true)
				{
					return false;
				}

				if (j > this->_position.second)
				{
					j--;
				}
			}
			this->_position.first = X;
			this->_position.second = Y;
			return true;

		}
		//+ et +
		else if (X > this->_position.first && Y > this->_position.second)
		{
			int j = Y - 1;
			for (int i = X - 1; i > this->_position.first; i--)
			{

				if (unTableau->listePiece[i][j]->getEnJeu() == true)
				{
					return false;
				}

				if (j > this->_position.second)
				{
					j--;
				}
			}
			this->_position.first = X;
			this->_position.second = Y;
			return true;
		}
	}
		//MOUVEMENT DE LA TOUR
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
		return true;
	}
	
}


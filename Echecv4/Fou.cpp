#include "pch.h"
#include "Fou.h"

Fou::Fou(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;
	this->_type = "fou";

    if (!blanc){
        this->_nom = "f_n";
    } else {
        this->_nom = "f_b";
    }
}


bool Fou::deplacement(int X, int Y, Piece *unTableau)
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
			for (int i = X-1; i > this->_position.first; i--)
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
    else
    {
        return false;
    }
}

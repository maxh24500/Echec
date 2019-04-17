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
		
		if (unTableau->listePiece[X][Y + 1]->getType()=="tour" && unTableau->listePiece[X][Y + 1]->getNbTour() == 0)
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

		if (unTableau->listePiece[X][Y - 1]->getType() == "tour" && unTableau->listePiece[X][Y - 1]->getNbTour() == 0)
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

void Roi::msgEchec(Piece* appelPlateau, bool couleurJoueur)
{
	return;\
	bool echecMat = this->calculEchecEtMat(appelPlateau, couleurJoueur);
	if (echecMat == true)
	{
		cout << "Echec et Mat !" << endl;
	}
	else if (this->calculEchec(appelPlateau, couleurJoueur) == true)
	{
		cout << "Echec !" << endl;
	}
}

bool Roi::calculEchec(Piece *appelPlateau, bool couleurJoueur) {
	int x = this->getPositionX();
	int y = this->getPositionY();
	bool echec = false;

	int i = this->testCavalier(x, y, appelPlateau, couleurJoueur);
	int j = this->testTour(x, y, appelPlateau, couleurJoueur);
	int k = this->testFou(x, y, appelPlateau, couleurJoueur);
	int l = this->testPion(x, y, appelPlateau, couleurJoueur);

	if (i >= 1 || j >= 1 || k >=1 || l >=1)
	{
		echec = true;
	}
	return echec;
}

bool Roi::calculEchecEtMat(Piece *appelPlateau, bool couleurJoueur) {
	int x = this->getPositionX();
	int y = this->getPositionY();
	bool echecEtMat = false;
	int m = 0;

	for (int i = 1; i < 8; ++i)
	{
		int cas = i;
		switch (cas)
		{
			case 1:
				y = y - 1;
				x = x + 1;
				break;

			case 2:
				x = x + 1;
				break;

			case 3:
				y = y + 1;
				x = x + 1;
				break;

			case 4:
				x = this->getPositionX();
				y = y + 1;
				break;

			case 5:
				y = y + 1;
				x = x - 1;
				break;

			case 6:
				x = x - 1;
				y = this->getPositionY();
				break;

			case 7:
				y = y - 1;
				x = x - 1;
				break;

			case 8:
				y = y - 1;
				break;	
		}
		if (x < 0 || x > 7 || y < 0 || y > 7) {
			break;
		}

		int n = this->testCavalier(x, y, appelPlateau, couleurJoueur);
		int j = this->testTour(x, y, appelPlateau, couleurJoueur);
		int k = this->testFou(x, y, appelPlateau, couleurJoueur);
		int l = this->testPion(x, y, appelPlateau, couleurJoueur);

		if (n >= 1 || j >= 1 || k >= 1 || l >= 1)
		{
			m++;
		}
	}

	if (m == 8)
	{
		echecEtMat = true;
	}
	return echecEtMat;
}

int Roi::testCavalier(int x, int y, Piece *appelPlateau, bool couleurJoueur) {
	int j = 0;

	for (int i = 1; i < 8; ++i)
	{
		int cas = i;
		switch (cas)
		{
			case 1:
				y = y - 1;
				x = x + 2;
				break;

			case 2:
				y = y + 1;
				x = x + 2;
				break;

			case 3:
				y = y - 1;
				x = x - 2;
				break;

			case 4:
				y = y + 1;
				x = x - 2;
				break;

			case 5:
				y = y + 2;
				x = x - 1;
				break;

			case 6:
				y = y + 2;
				x = x + 1;
				break;

			case 7:
				y = y - 2;
				x = x - 1;
				break;

			case 8:
				y = y - 2;
				x = x + 1;
				break;
			
		}

		Piece* unePiece = new Piece();
		unePiece = appelPlateau->listePiece[x][y];

		if (!(x < 0 || x > 7 || y < 0 || y > 7))
			{
			if (unePiece->getType() == "cavalier" && unePiece->getEstBlanc() != couleurJoueur) {
				j++;
			}
		}
	}
		return j;
}

int Roi::testTour(int x, int y, Piece *appelPlateau, bool couleurJoueur)
{
	int k = 0;
	for (int i = 1; i < 5; ++i)
	{
		for (int j = 1; j < 8; ++j)
		{		
			int cas = i;
			switch (cas)
			{
				case 1:
					y = y - j;
					x = x;
					break;

				case 2:
					y = y + j;
					x = x;
					break;

				case 3:
					y = y;
					x = x - j;
					break;

				case 4:
					y = y;
					x = x + j;
					break;
			}
			if (x < 0 || x > 7 || y < 0 || y > 7)
			{
				break;
			}
		}
		if (x < 0 || x > 7 || y < 0 || y > 7)
		{
			return false;
		}
		Piece* unePiece = new Piece();
		unePiece = appelPlateau->listePiece[x][y];

		if ((unePiece->getType() == "tour" || unePiece->getType() == "reine" ) && unePiece->getEstBlanc() != couleurJoueur)
		{
			k++;
		}
		
	}
	return k;
}

int Roi::testFou(int x, int y, Piece *appelPlateau, bool couleurJoueur)
{
	int k = 0;

	for (int i = 1; i < 5; ++i)
	{
		for (int j = 1; j < 8; ++j)
		{
			int cas = i;
			switch (cas)
			{
				case 1:
					y = y - j;
					x = x - j;
					break;

				case 2:
					y = y + j;
					x = x + j;
					break;

				case 3:
					y = y + j;
					x = x - j;
					break;

				case 4:
					y = y - j;
					x = x + j;
					break;
			}

			if (x < 0 || x > 7 || y < 0 || y > 7)
			{
				break;
			}
			
		}
		if (x < 0 || x > 7 || y < 0 || y > 7)
		{
			return false;
		}
		Piece* unePiece = new Piece();
		unePiece = appelPlateau->listePiece[x][y];

		if ((unePiece->getType() == "fou" || unePiece->getType() == "reine" ) && unePiece->getEstBlanc() != couleurJoueur)
		{
			k++;
		}
		
	}
	return k;
}

int Roi::testPion(int x, int y, Piece *appelPlateau, bool couleurJoueur)
{
	int j = 0;

	if (couleurJoueur == true)
	{
		x = x - 1;
	} else {
		x = x + 1;
	}
	for (int i = 1; i < 3; ++i)
	{
		int cas = i;
		switch (cas)
		{
			case 1:
				y = y + 1;
				break;
			case 2:
				y = y - 1;
				break;
		}

		Piece* unePiece = new Piece();
		unePiece = appelPlateau->listePiece[x][y];

	if (unePiece->getType() == "pion" && unePiece->getEstBlanc() != couleurJoueur)
		{
			j++;
		}
	}
	return j;
}



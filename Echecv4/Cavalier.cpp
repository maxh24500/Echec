#include "pch.h"
#include "Cavalier.h"

Cavalier::Cavalier(int id, int positionX, int positionY, bool blanc):Piece(id, positionX, positionY, blanc){
    this->_id = id;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_blanc = blanc;
    this->_enJeu = true;

    if (!blanc){
        this->_nom = "c_n";
    } else {
        this->_nom = "c_b";
    }
}

bool Cavalier::deplacement(int X, int Y, Piece *unTableau)
{
    if (X == this->_position.first - 2 && Y == this->_position.second + 1)
    {
        this->_position.first = X;
        this->_position.second = Y;
        return true;

    }
    else if (X == this->_position.first - 1 && Y == this->_position.second + 2)
    {
        this->_position.first = X;
        this->_position.second = Y;
        return true;
    }
    else if (X == this->_position.first + 1 && Y == this->_position.second + 2)
    {
        this->_position.first = X;
        this->_position.second = Y;
        return true;

    }
    else if (X == this->_position.first + 2 && Y == this->_position.second + 1)
    {
        this->_position.first = X;
        this->_position.second = Y;
        return true;
    }
    else if (X == this->_position.first + 2 && Y == this->_position.second - 1)
    {
        this->_position.first = X;
        this->_position.second = Y;
        return true;
    }
    else if (X == this->_position.first + 1 && Y == this->_position.second - 2)
    {
        this->_position.first = X;
        this->_position.second = Y;
        return true;
    }
    else if (X == this->_position.first - 1 && Y == this->_position.second - 2)
    {
        this->_position.first = X;
        this->_position.second = Y;
        return true;
    }
    else if (X == this->_position.first - 2 && Y == this->_position.second - 1)
    {
        this->_position.first = X;
        this->_position.second = Y;
        return true;
    }
    else
    {
        cout << "Erreur : mauvais mouvement, reessayez" << endl;
        return false;
    }
}


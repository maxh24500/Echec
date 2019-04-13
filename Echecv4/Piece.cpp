#include "pch.h"
#include "Piece.h"
#include <iostream>

Piece::Piece(){

}
Piece::Piece(int id, int positionX, int positionY, bool blanc)
{
}
Piece::Piece(int id, bool blanc, bool enJeu, int positionX, int positionY){
    this->_id = id;
    this->_blanc = blanc;
    this->_position.first = positionX;
    this->_position.second = positionY;
    this->_enJeu = enJeu;
}
Piece::~Piece(){

}

bool Piece::deplacement(int X, int Y)
{
	return false;
}

int Piece::getId(){
    return this->_id;
}
void Piece::setId(int nouvelleValeur){
    this->_id = nouvelleValeur;
}

int Piece::getPositionX(){
    return this->_position.first;
}
int Piece::getPositionY(){
    return this->_position.second;
}
void Piece::setPosition(pair <int, int> nouvellePosition){
    this->_position = nouvellePosition;
}

bool Piece::getEstBlanc(){
    return this->_blanc;
}
void Piece::setEstBlanc(bool nouvelleValeur){
    this->_blanc = nouvelleValeur;
}

bool Piece::getEnJeu(){
    return this->_enJeu;
}
void Piece::setEnJeu(bool nouvelleValeur){
    this->_enJeu = nouvelleValeur;
}

string Piece::getNom(){
        return this->_nom;
}

void Piece::setNom(string nouvelleValeur){
    this->_nom = nouvelleValeur;
}

string Piece::afficherNom() {

    if ( this->getEnJeu() == false) {
        return "   ";
    } else {
        return this->getNom();
    }
}


void Piece::addPiece(){

}

void Piece::showPiece() {

}

void Piece::lirePiece(){
    cout<< "La piece est une " << this->_nom << " placee sur la case " << this->_position.first << ", " << this->_position.second << endl;
}

string Piece::cellToPlat(pair <int, int> cellule) {
    string position;

    int row = cellule.first;
    int col = cellule.second;

    if (row == 0) {
        if (col == 0) {
            position = "A8";
        }
        else if (col == 1) {
            position = "B8";
        }
        else if (col == 2) {
            position = "C8";
        }
        else if (col == 3) {
            position = "D8";
        }
        else if (col == 4) {
            position = "E8";
        }
        else if (col == 5) {
            position = "F8";
        }
        else if (col == 6) {
            position = "G8";
        }
        else if (col == 7) {
            position = "H8";
        }
    }
    else if (row == 1) {
        if (col == 0) {
            position = "A7";
        }
        else if (col == 1) {
            position = "B7";
        }
        else if (col == 2) {
            position = "C7";
        }
        else if (col == 3) {
            position = "D7";
        }
        else if (col == 4) {
            position = "E7";
        }
        else if (col == 5) {
            position = "F7";
        }
        else if (col == 6) {
            position = "G7";
        }
        else if (col == 7) {
            position = "H7";
        }
    }
    else if (row == 2) {
        if (col == 0) {
            position = "A6";
        }
        else if (col == 1) {
            position = "B6";
        }
        else if (col == 2) {
            position = "C6";
        }
        else if (col == 3) {
            position = "D6";
        }
        else if (col == 4) {
            position = "E6";
        }
        else if (col == 5) {
            position = "F6";
        }
        else if (col == 6) {
            position = "G6";
        }
        else if (col == 7) {
            position = "H6";
        }
    }
    else if (row == 3) {
        if (col == 0) {
            position = "A5";
        }
        else if (col == 1) {
            position = "B5";
        }
        else if (col == 2) {
            position = "C5";
        }
        else if (col == 3) {
            position = "D5";
        }
        else if (col == 4) {
            position = "E5";
        }
        else if (col == 5) {
            position = "F5";
        }
        else if (col == 6) {
            position = "G5";
        }
        else if (col == 7) {
            position = "H5";
        }
    }
    else if (row == 4) {
        if (col == 0) {
            position = "A4";
        }
        else if (col == 1) {
            position = "B4";
        }
        else if (col == 2) {
            position = "C4";
        }
        else if (col == 3) {
            position = "D4";
        }
        else if (col == 4) {
            position = "E4";
        }
        else if (col == 5) {
            position = "F4";
        }
        else if (col == 6) {
            position = "G4";
        }
        else if (col == 7) {
            position = "H4";
        }
    }
    else if (row == 5) {
        if (col == 0) {
            position = "A3";
        }
        else if (col == 1) {
            position = "B3";
        }
        else if (col == 2) {
            position = "C3";
        }
        else if (col == 3) {
            position = "D3";
        }
        else if (col == 4) {
            position = "E3";
        }
        else if (col == 5) {
            position = "F3";
        }
        else if (col == 6) {
            position = "G3";
        }
        else if (col == 7) {
            position = "H3";
        }
    }
    else if (row == 6) {
        if (col == 0) {
            position = "A2";
        }
        else if (col == 1) {
            position = "B2";
        }
        else if (col == 2) {
            position = "C2";
        }
        else if (col == 3) {
            position = "D2";
        }
        else if (col == 4) {
            position = "E2";
        }
        else if (col == 5) {
            position = "F2";
        }
        else if (col == 6) {
            position = "G2";
        }
        else if (col == 7) {
            position = "H2";
        }
    }
    else if (row == 7) {
        if (col == 0) {
            position = "A1";
        }
        else if (col == 1) {
            position = "B1";
        }
        else if (col == 2) {
            position = "C1";
        }
        else if (col == 3) {
            position = "D1";
        }
        else if (col == 4) {
            position = "E1";
        }
        else if (col == 5) {
            position = "F1";
        }
        else if (col == 6) {
            position = "G1";
        }
        else if (col == 7) {
            position = "H1";
        }
    }
    return position;
}

pair <int, int> Piece::platToCell(string position) {
    pair<int, int> cellule;

    if (position == "A8" || position == "a8") {
        cellule.first = 7;
        cellule.second = 0;
    }
    else if (position == "B8" || position == "b8") {
        cellule.first = 7;
        cellule.second = 1;
    }
    else if (position == "C8" || position == "c8") {
        cellule.first = 7;
        cellule.second = 2;
    }
    else if (position == "D8" || position == "d8") {
        cellule.first = 7;
        cellule.second = 3;
    }
    else if (position == "E8" || position == "e8") {
        cellule.first = 7;
        cellule.second = 4;
    }
    else if (position == "F8" || position == "f8") {
        cellule.first = 7;
        cellule.second = 5;
    }
    else if (position == "G8" || position == "g8") {
        cellule.first = 7;
        cellule.second = 6;
    }
    else if (position == "H8" || position == "h8") {
        cellule.first = 7;
        cellule.second = 7;
    }
    else if (position == "A7" || position == "a7") {
        cellule.first = 6;
        cellule.second = 0;
    }
    else if (position == "B7" || position == "b7") {
        cellule.first = 6;
        cellule.second = 1;
    }
    else if (position == "C7" || position == "c7") {
        cellule.first = 6;
        cellule.second = 2;
    }
    else if (position == "D7" || position == "d7") {
        cellule.first = 6;
        cellule.second = 3;
    }
    else if (position == "E7" || position == "e7") {
        cellule.first = 6;
        cellule.second = 4;
    }
    else if (position == "F7" || position == "f7") {
        cellule.first = 6;
        cellule.second = 5;
    }
    else if (position == "G7" || position == "g7") {
        cellule.first = 6;
        cellule.second = 6;
    }
    else if (position == "H7" || position == "h7") {
        cellule.first = 6;
        cellule.second = 7;
    }
    else if (position == "A6" || position == "a6") {
        cellule.first = 5;
        cellule.second = 0;
    }
    else if (position == "B6" || position == "b6") {
        cellule.first = 5;
        cellule.second = 1;
    }
    else if (position == "C6" || position == "c6") {
        cellule.first = 5;
        cellule.second = 2;
    }
    else if (position == "D6" || position == "d6") {
        cellule.first = 5;
        cellule.second = 3;
    }
    else if (position == "E6" || position == "e6") {
        cellule.first = 5;
        cellule.second = 4;
    }
    else if (position == "F6" || position == "f6") {
        cellule.first = 5;
        cellule.second = 5;
    }
    else if (position == "G6" || position == "g6") {
        cellule.first = 5;
        cellule.second = 6;
    }
    else if (position == "H6" || position == "h6") {
        cellule.first = 5;
        cellule.second = 7;
    }
    else if (position == "A5" || position == "a5") {
        cellule.first = 4;
        cellule.second = 0;
    }
    else if (position == "B5" || position == "b5") {
        cellule.first = 4;
        cellule.second = 1;
    }
    else if (position == "C5" || position == "c5") {
        cellule.first = 4;
        cellule.second = 2;
    }
    else if (position == "D5" || position == "d5") {
        cellule.first = 4;
        cellule.second = 3;
    }
    else if (position == "E5" || position == "e5") {
        cellule.first = 4;
        cellule.second = 4;
    }
    else if (position == "F5" || position == "f5") {
        cellule.first = 4;
        cellule.second = 5;
    }
    else if (position == "G5" || position == "g5") {
        cellule.first = 4;
        cellule.second = 6;
    }
    else if (position == "H5" || position == "h5") {
        cellule.first = 4;
        cellule.second = 7;
    }
    else if (position == "A4" || position == "a4") {
        cellule.first = 3;
        cellule.second = 0;
    }
    else if (position == "B4" || position == "b4") {
        cellule.first = 3;
        cellule.second = 1;
    }
    else if (position == "C4" || position == "c4") {
        cellule.first = 3;
        cellule.second = 2;
    }
    else if (position == "D4" || position == "d4") {
        cellule.first = 3;
        cellule.second = 3;
    }
    else if (position == "E4" || position == "e4") {
        cellule.first = 3;
        cellule.second = 4;
    }
    else if (position == "F4" || position == "f4") {
        cellule.first = 3;
        cellule.second = 5;
    }
    else if (position == "G4" || position == "g4") {
        cellule.first = 3;
        cellule.second = 6;
    }
    else if (position == "H4" || position == "h4") {
        cellule.first = 3;
        cellule.second = 7;
    }
    else if (position == "A3" || position == "a3") {
        cellule.first = 2;
        cellule.second = 0;
    }
    else if (position == "B3" || position == "b3") {
        cellule.first = 2;
        cellule.second = 1;
    }
    else if (position == "C3" || position == "c3") {
        cellule.first = 2;
        cellule.second = 2;
    }
    else if (position == "D3" || position == "d3") {
        cellule.first = 2;
        cellule.second = 3;
    }
    else if (position == "E3" || position == "e3") {
        cellule.first = 2;
        cellule.second = 4;
    }
    else if (position == "F3" || position == "f3") {
        cellule.first = 2;
        cellule.second = 5;
    }
    else if (position == "G3" || position == "g3") {
        cellule.first = 2;
        cellule.second = 6;
    }
    else if (position == "H3" || position == "h3") {
        cellule.first = 2;
        cellule.second = 7;
    }
    else if (position == "A2" || position == "a2") {
        cellule.first = 1;
        cellule.second = 0;
    }
    else if (position == "B2" || position == "b2") {
        cellule.first = 1;
        cellule.second = 1;
    }
    else if (position == "C2" || position == "c2") {
        cellule.first = 1;
        cellule.second = 2;
    }
    else if (position == "D2" || position == "d2") {
        cellule.first = 1;
        cellule.second = 3;
    }
    else if (position == "E2" || position == "e2") {
        cellule.first = 1;
        cellule.second = 4;
    }
    else if (position == "F2" || position == "f2") {
        cellule.first = 1;
        cellule.second = 5;
    }
    else if (position == "G2" || position == "g2") {
        cellule.first = 1;
        cellule.second = 6;
    }
    else if (position == "H2" || position == "h2") {
        cellule.first = 1;
        cellule.second = 7;
    }
    else if (position == "A1" || position == "a1") {
        cellule.first = 0;
        cellule.second = 0;
    }
    else if (position == "B1" || position == "b1") {
        cellule.first = 0;
        cellule.second = 1;
    }
    else if (position == "C1" || position == "c1") {
        cellule.first = 0;
        cellule.second = 2;
    }
    else if (position == "D1" || position == "d1") {
        cellule.first = 0;
        cellule.second = 3;
    }
    else if (position == "E1" || position == "e1") {
        cellule.first = 0;
        cellule.second = 4;
    }
    else if (position == "F1" || position == "f1") {
        cellule.first = 0;
        cellule.second = 5;
    }
    else if (position == "G1" || position == "g1") {
        cellule.first = 0;
        cellule.second = 6;
    }
    else if (position == "H1" || position == "h1") {
        cellule.first = 0;
        cellule.second = 7;
    }
    return cellule;
}



string Piece::imprimPiece(){
    if (this == NULL) {
        return " . ";
    } else {
        return this->_nom;
    }
}

void Piece::afficherPlateau(){
    cout << "" << endl
         << "              _______________________________" << endl
         << "             |   |   |   |   |   |   |   |   |" << endl
         << "           8 |" << this->listePiece[7][0]->afficherNom() << "|" << this->listePiece[7][1]->afficherNom() << "|" << this->listePiece[7][2]->afficherNom() << "|" << this->listePiece[7][3]->afficherNom() << "|" << this->listePiece[7][4]->afficherNom() << "|" << this->listePiece[7][5]->afficherNom() << "|" << this->listePiece[7][6]->afficherNom() << "|" << this->listePiece[7][7]->afficherNom() << "|" << endl
         << "             |___|___|___|___|___|___|___|___|" << endl
         << "             |   |   |   |   |   |   |   |   |" << endl
         << "           7 |" << this->listePiece[6][0]->afficherNom() << "|" << this->listePiece[6][1]->afficherNom() << "|" << this->listePiece[6][2]->afficherNom() << "|" << this->listePiece[6][3]->afficherNom() << "|" << this->listePiece[6][4]->afficherNom() << "|" << this->listePiece[6][5]->afficherNom() << "|" << this->listePiece[6][6]->afficherNom() << "|" << this->listePiece[6][7]->afficherNom() << "|" << endl
         << "             |___|___|___|___|___|___|___|___|" << endl
         << "             |   |   |   |   |   |   |   |   |" << endl
         << "           6 |" << this->listePiece[5][0]->afficherNom() << "|" << this->listePiece[5][1]->afficherNom() << "|" << this->listePiece[5][2]->afficherNom() << "|" << this->listePiece[5][3]->afficherNom() << "|" << this->listePiece[5][4]->afficherNom() << "|" << this->listePiece[5][5]->afficherNom() << "|" << this->listePiece[5][6]->afficherNom() << "|" << this->listePiece[5][7]->afficherNom() << "|" << endl
         << "             |___|___|___|___|___|___|___|___|" << endl
         << "             |   |   |   |   |   |   |   |   |" << endl
         << "           5 |" << this->listePiece[4][0]->afficherNom() << "|" << this->listePiece[4][1]->afficherNom() << "|" << this->listePiece[4][2]->afficherNom() << "|" << this->listePiece[4][3]->afficherNom() << "|" << this->listePiece[4][4]->afficherNom() << "|" << this->listePiece[4][5]->afficherNom() << "|" << this->listePiece[4][6]->afficherNom() << "|" << this->listePiece[4][7]->afficherNom() << "|" << endl
         << "             |___|___|___|___|___|___|___|___|" << endl
         << "             |   |   |   |   |   |   |   |   |" << endl
         << "           4 |" << this->listePiece[3][0]->afficherNom() << "|" << this->listePiece[3][1]->afficherNom() << "|" << this->listePiece[3][2]->afficherNom() << "|" << this->listePiece[3][3]->afficherNom() << "|" << this->listePiece[3][4]->afficherNom() << "|" << this->listePiece[3][5]->afficherNom() << "|" << this->listePiece[3][6]->afficherNom() << "|" << this->listePiece[3][7]->afficherNom() << "|" << endl
         << "             |___|___|___|___|___|___|___|___|" << endl
         << "             |   |   |   |   |   |   |   |   |" << endl
         << "           3 |" << this->listePiece[2][0]->afficherNom() << "|" << this->listePiece[2][1]->afficherNom() << "|" << this->listePiece[2][2]->afficherNom() << "|" << this->listePiece[2][3]->afficherNom() << "|" << this->listePiece[2][4]->afficherNom() << "|" << this->listePiece[2][5]->afficherNom() << "|" << this->listePiece[2][6]->afficherNom() << "|" << this->listePiece[2][7]->afficherNom() << "|" << endl
         << "             |___|___|___|___|___|___|___|___|" << endl
         << "             |   |   |   |   |   |   |   |   |" << endl
         << "           2 |" << this->listePiece[1][0]->afficherNom() << "|" << this->listePiece[1][1]->afficherNom() << "|" << this->listePiece[1][2]->afficherNom() << "|" << this->listePiece[1][3]->afficherNom() << "|" << this->listePiece[1][4]->afficherNom() << "|" << this->listePiece[1][5]->afficherNom() << "|" << this->listePiece[1][6]->afficherNom() << "|" << this->listePiece[1][7]->afficherNom() << "|" << endl
         << "             |___|___|___|___|___|___|___|___|" << endl
         << "             |   |   |   |   |   |   |   |   |" << endl
         << "           1 |" << this->listePiece[0][0]->afficherNom() << "|" << this->listePiece[0][1]->afficherNom() << "|" << this->listePiece[0][2]->afficherNom() << "|" << this->listePiece[0][3]->afficherNom() << "|" << this->listePiece[0][4]->afficherNom() << "|" << this->listePiece[0][5]->afficherNom() << "|" << this->listePiece[0][6]->afficherNom() << "|" << this->listePiece[0][7]->afficherNom() << "|" << endl
         << "             |___|___|___|___|___|___|___|___|" << endl
         << "               A | B | C | D | E | F | G | H " << endl;
}

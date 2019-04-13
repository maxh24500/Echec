#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef enum _EchecPieceEnum {
    pieceNone,
    pieceTourBlanc,
    pieceRoiBlanc,
    pieceReineBlanc,
    pieceFouBlanc,
    pieceCavalierBlanc,
    pieceRookBlanc,
    piecePionBlanc,
    pieceTourNoir,
    pieceRoiNoir,
    pieceReineNoir,
    pieceFouNoir,
    pieceCavalierNoir,
    pieceRookNoir,
    piecePionNoir,
}EchecPieceEnum;

class Piece {
protected:
    int _id;
    pair <int, int> _position;
    bool _blanc;
    bool _enJeu;
    string _nom;
    EchecPieceEnum _type;

public:
    Piece();
    Piece(int id,int positionX,int positionY,bool blanc);
    Piece(int id, bool blanc, bool enJeu, int positionX, int positionY);
    ~Piece();

    Piece *listePiece[8][8];
	virtual bool deplacement(int X, int Y);
  

    void afficherPlateau();

    int getId();
    void setId(int newValue);

    EchecPieceEnum getType();
    void setType(EchecPieceEnum newValue);

    virtual int getPositionX();
    virtual int getPositionY();
    virtual void setPosition(pair <int, int> newPosition);

    void lirePiece();

    bool getEstBlanc();
    void setEstBlanc(bool newValue);

    bool getEnJeu();
    void setEnJeu(bool newValue);

    string getNom();

    string afficherNom();

    void setNom(string newValue);

    void addPiece();

    void showPiece();

    string cellToPlat(pair <int, int> cellule);
    pair <int, int>platToCell(string position);

    string imprimPiece();

    void mouv(pair<int, int> nouvellePosition) {    this->setPosition(nouvellePosition);    }
};

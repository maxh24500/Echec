#pragma once
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Piece {
	
protected:
    int _id;
    pair <int, int> _position;
    bool _blanc;
    bool _enJeu;
    string _nom;
	string _type;
	int nbTour = 0;
	bool _doublePas = false;

public:
	

    Piece();
    Piece(int id,int positionX,int positionY,bool blanc);
    Piece(int id, bool blanc, bool enJeu, int positionX, int positionY);
    ~Piece();
	
    Piece *listePiece[8][8];
	virtual bool deplacement(int X, int Y, Piece *unTableau);
	void deplacementPlateau(int X,int Y,Piece *unPlateau);
    void afficherPlateau();

	void changePion(Piece *unTableau);

    int getId();
    void setId(int newValue);

    virtual int getPositionX();
    virtual int getPositionY();
    void setPosition(int X,int Y);

    void lirePiece();

    bool getEstBlanc();
    void setEstBlanc(bool newValue);

	int getNbTour();
	string getType();
	bool getDoublePas();
	void setDoublePas(bool doublePas);

    bool getEnJeu();
    void setEnJeu(bool newValue);

    string getNom();

    string afficherNom();

    void setNom(string newValue);

    void addPiece();

    void showPiece();

    string cellToPlat(pair <int, int> cellule);
    pair <int, int>platToCell(string position);
};

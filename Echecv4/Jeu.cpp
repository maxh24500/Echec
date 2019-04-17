#include "Jeu.h"



Jeu::Jeu()
{
}


Jeu::~Jeu()
{
}


void Jeu::lancerJeu() {
	appelTableau = new Piece();
    caseVide = new Piece();
	caseVide->setEnJeu(false);


	Pion* pn1 = new Pion(0, 6, 0, false);
	appelTableau->listePiece[6][0] = pn1;

	Pion* pn2 = new Pion(1, 6, 1, false);
	appelTableau->listePiece[6][1] = pn2;

	Pion* pn3 = new Pion(2, 6, 2, false);
	appelTableau->listePiece[6][2] = pn3;

	Pion* pn4 = new Pion(3, 6, 3, false);
	appelTableau->listePiece[6][3] = pn4;

	Pion* pn5 = new Pion(4, 6, 4, false);
	appelTableau->listePiece[6][4] = pn5;

	Pion* pn6 = new Pion(5, 6, 5, false);
	appelTableau->listePiece[6][5] = pn6;

	Pion* pn7 = new Pion(6, 6, 6, false);
	appelTableau->listePiece[6][6] = pn7;

	Pion* pn8 = new Pion(7, 6, 7, false);
	appelTableau->listePiece[6][7] = pn8;

	Tour* tn1 = new Tour(8, 7, 0, false);
	appelTableau->listePiece[7][0] = tn1;

	Tour* tn2 = new Tour(9, 7, 7, false);
	appelTableau->listePiece[7][7] = tn2;

	Cavalier* cn1 = new Cavalier(10, 7, 1, false);
	appelTableau->listePiece[7][1] = cn1;

	Cavalier* cn2 = new Cavalier(11, 7, 6, false);
	appelTableau->listePiece[7][6] = cn2;

	Fou* fn1 = new Fou(12, 7, 2, false);
	appelTableau->listePiece[7][2] = fn1;

	Fou* fn2 = new Fou(13, 7, 5, false);
	appelTableau->listePiece[7][5] = fn2;

	Roi* R_n = new Roi(14, 7, 4, false);
	appelTableau->listePiece[7][4] = R_n;

	Reine* r_n = new Reine(15, 7, 3, false);
	appelTableau->listePiece[7][3] = r_n;

	Pion* pb1 = new Pion(16, 1, 0, true);
	appelTableau->listePiece[1][0] = pb1;

	Pion* pb2 = new Pion(17, 1, 1, true);
	appelTableau->listePiece[1][1] = pb2;

	Pion* pb3 = new Pion(18, 1, 2, true);
	appelTableau->listePiece[1][2] = pb3;

	Pion* pb4 = new Pion(19, 1, 3, true);
	appelTableau->listePiece[1][3] = pb4;

	Pion* pb5 = new Pion(20, 1, 4, true);
	appelTableau->listePiece[1][4] = pb5;

	Pion* pb6 = new Pion(21, 1, 5, true);
	appelTableau->listePiece[1][5] = pb6;

	Pion* pb7 = new Pion(22, 1, 6, true);
	appelTableau->listePiece[1][6] = pb7;

	Pion* pb8 = new Pion(23, 1, 7, true);
	appelTableau->listePiece[1][7] = pb8;

	Tour* tb1 = new Tour(24, 0, 0, true);
	appelTableau->listePiece[0][0] = tb1;

	Tour* tb2 = new Tour(25, 0, 7, true);
	appelTableau->listePiece[0][7] = tb2;

	Cavalier* cb1 = new Cavalier(26, 0, 1, true);
	appelTableau->listePiece[0][1] = cb1;

	Cavalier* cb2 = new Cavalier(27, 0, 6, true);
	appelTableau->listePiece[0][6] = cb2;

	Fou* fb1 = new Fou(28, 0, 2, true);
	appelTableau->listePiece[0][2] = fb1;

	Fou* fb2 = new Fou(29, 0, 5, true);
	appelTableau->listePiece[0][5] = fb2;

	Roi* R_b = new Roi(30, 0, 4, true);
	appelTableau->listePiece[0][4] = R_b;

	Reine* r_b = new Reine(31, 0, 3, true);
	appelTableau->listePiece[0][3] = r_b;

	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			appelTableau->listePiece[i][j] = caseVide;
		}
	}

    finPartie = false;
    Blanc = true;
    laPiece1 = new Piece();
    laPiece2 = new Piece();

    enJeu = false;
    Joueur1 = true;
#if 0
	while (!finPartie) {
		while (Joueur1 == true)
		{
			//JOUEUR BLANC
			cout << "c'est au tour du joueur Blanc" << endl;
			//AFFICHAGE DU PLATEAU
			appelTableau->afficherPlateau();
//			//VERIF ECHEC
//			R_b->msgEchec(appelTableau, true);
			//SAISIE PIECE A DEPLACER
			cout << "Saisir la case de la piece a deplacer : " << endl;
			cin >> choix;
			//TRANSFORMATION EN CELLULE
			cellBase = laPiece1->platToCell(choix);
			//INITIALISATION DE LA PIECE 1
			laPiece1 = appelTableau->listePiece[cellBase.first][cellBase.second];
			Blanc = laPiece1->getEstBlanc();
			//TANT QUE C'EST UNE PIECE D'UNE AUTRE COULEUR...
			while (Blanc == false || appelTableau->listePiece[cellBase.first][cellBase.second] == caseVide)
			{
				cout << "Erreur, vous ne possedez pas cette piece" << endl;
				appelTableau->afficherPlateau();
				cout << "Saisir la case de la piece a deplacer : " << endl;
				cin >> choix;
				cellBase = laPiece1->platToCell(choix);
				laPiece1 = appelTableau->listePiece[cellBase.first][cellBase.second];
				Blanc = laPiece1->getEstBlanc();
			}
			//CASE D'ARRIVE
			cout << "Saisir la case d'arrivee : " << endl;
			cin >> choix;
			//TRANSFORMATION
			cellArriv = laPiece2->platToCell(choix);
			//INITIALISATION PIECE 2 ARRIVE
			laPiece2 = appelTableau->listePiece[cellArriv.first][cellArriv.second];


			enJeu = laPiece2->getEnJeu();
			//SOIT CASE VIDE SOIT BOUFFE
			if (enJeu == false || laPiece2->getEstBlanc() != Blanc) {
				bool mouvAutorise;
				mouvAutorise = laPiece1->deplacement(cellArriv.first, cellArriv.second, appelTableau);
				//MOUVEMENT DE LA PIECE POSSIBLE
				if (mouvAutorise == true) {
					appelTableau->listePiece[cellBase.first][cellBase.second] = caseVide;
					appelTableau->listePiece[cellArriv.first][cellArriv.second] = laPiece1;
					laPiece1->changePion(appelTableau);
					Joueur1 = false;
				}
				else {
					cout << "Erreur : mouvement non-autorise : ";
				}
			}
			else {
				cout << "Erreur : case selectionnee prise par une de vos pieces : ";
			}
		}

		//JOUEUR NOIR
		while (Joueur1 == false)
		{
			cout << "c'est au tour du joueur Noir" << endl;

			appelTableau->afficherPlateau();

			R_b->msgEchec(appelTableau, false);
			cout << "Saisir la case de la piece a deplacer : " << endl;
			cin >> choix;
			cellBase = laPiece1->platToCell(choix);
			laPiece1 = appelTableau->listePiece[cellBase.first][cellBase.second];
			Blanc = laPiece1->getEstBlanc();

			while (Blanc == true || appelTableau->listePiece[cellBase.first][cellBase.second] == caseVide)
			{
				cout << "Erreur, vous ne possedez pas cette piece" << endl;
				appelTableau->afficherPlateau();
				cout << "Saisir la case de la piece a deplacer : " << endl;
				cin >> choix;
				cellBase = laPiece1->platToCell(choix);
				laPiece1 = appelTableau->listePiece[cellBase.first][cellBase.second];
				Blanc = laPiece1->getEstBlanc();
			}

			cout << "Saisir la case d'arrivee : " << endl;
			cin >> choix;

			cellArriv = laPiece2->platToCell(choix);

			laPiece2 = appelTableau->listePiece[cellArriv.first][cellArriv.second];

			enJeu = false;
			enJeu = laPiece2->getEnJeu();

			if (enJeu == false || laPiece2->getEstBlanc() != Blanc) {
				bool mouvAutorise;
				mouvAutorise = laPiece1->deplacement(cellArriv.first, cellArriv.second, appelTableau);
				if (mouvAutorise == true) {
					appelTableau->listePiece[cellBase.first][cellBase.second] = caseVide;
					appelTableau->listePiece[cellArriv.first][cellArriv.second] = laPiece1;
					laPiece1->changePion(appelTableau);
					Joueur1 = true;
				}
				else {
					cout << "Erreur : mouvement non-autorise : ";
				}
			}
			else {
				cout << "Erreur : case selectionnee prise par une de vos pieces : ";
			}
		}
	}
#endif

}
std::string Jeu::pieceAt(int X, int Y)
{
	if (X < 0 || X>7 || Y < 0 || Y>7)
	{
		return std::string();
	}
	return appelTableau->listePiece[X][Y]->getNom();
}

bool Jeu::canPlay(int X, int Y)
{
    laPiece1 = appelTableau->listePiece[X][Y];

    if (laPiece1==caseVide)
    {
        return false;
    }

    if (Joueur1 == true)
    {
        Blanc = laPiece1->getEstBlanc();
        if (Blanc == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    if (Joueur1 == false)
    {
        Blanc = laPiece1->getEstBlanc();
        if (Blanc == true)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool Jeu::deplacement(int fromX, int fromY, int toX, int toY)

{
    if (!finPartie) {
        if (Joueur1 == true)
        {
            //JOUEUR BLANC
            //INITIALISATION DE LA PIECE 1
            laPiece1 = appelTableau->listePiece[fromX][fromY];
            Blanc = laPiece1->getEstBlanc();
            //TANT QUE C'EST UNE PIECE D'UNE AUTRE COULEUR...
            if (Blanc == false || appelTableau->listePiece[fromX][fromY] == caseVide)
            {
                return false;
            }
            //CASE D'ARRIVE
            //INITIALISATION PIECE 2 ARRIVE
            laPiece2 = appelTableau->listePiece[toX][toY];


            enJeu = laPiece2->getEnJeu();
            //SOIT CASE VIDE SOIT BOUFFE
            if (enJeu == false || laPiece2->getEstBlanc() != Blanc) {
                bool mouvAutorise;
                mouvAutorise = laPiece1->deplacement(toX, toY, appelTableau);
                //MOUVEMENT DE LA PIECE POSSIBLE
                if (mouvAutorise == true) {
                    appelTableau->listePiece[fromX][fromY] = caseVide;
                    appelTableau->listePiece[toX][toY] = laPiece1;
                    laPiece1->changePion(appelTableau);
                    Joueur1 = false;

                    return true;
                }
                else {
                    cout << "Erreur : mouvement non-autorise : ";
                    return false;
                }
            }
            else {
                cout << "Erreur : case selectionnee prise par une de vos pieces : ";
                return false;
            }
        }

        //JOUEUR NOIR
        if (Joueur1 == false)
        {
            laPiece1 = appelTableau->listePiece[fromX][fromY];
            Blanc = laPiece1->getEstBlanc();

            if (Blanc == true || appelTableau->listePiece[fromX][fromY] == caseVide)
            {
                return false;
            }

            laPiece2 = appelTableau->listePiece[toX][toY];

            enJeu = false;
            enJeu = laPiece2->getEnJeu();

            if (enJeu == false || laPiece2->getEstBlanc() != Blanc) {
                bool mouvAutorise;
                mouvAutorise = laPiece1->deplacement(toX, toY, appelTableau);
                if (mouvAutorise == true) {
                    appelTableau->listePiece[fromX][fromY] = caseVide;
                    appelTableau->listePiece[toX][toY] = laPiece1;
                    laPiece1->changePion(appelTableau);
                    Joueur1 = true;
                    return true;
                }
                else {
                    cout << "Erreur : mouvement non-autorise : ";
                    return false;
                }
            }
            else {
                cout << "Erreur : case selectionnee prise par une de vos pieces : ";
                return false;
            }
        }
    }
    return false;
}

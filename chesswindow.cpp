#include "chesswindow.h"
#include "ui_chesswindow.h"

void ChessWindow::UpdateBoard()
{
    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            Piece *p = echec.getPiece(row, col);
            setPiece(row,col, p);
        }
    }
}

ChessWindow::ChessWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChessWindow),
    BlackCastle(QPixmap(":/pieces/BlackCastle.png")),
    BlackHorse(QPixmap(":/pieces/BlackHorse.png")),
    BlackKing(QPixmap(":/pieces/BlackKing.png")),
    BlackPawn(QPixmap(":/pieces/BlackPawn.png")),
    BlackQueen(QPixmap(":/pieces/BlackQueen.png")),
    BlackBishop(QPixmap(":/pieces/BlackBishop.png")),
    WhiteCastle(QPixmap(":/pieces/WhiteCastle.png")),
    WhiteHorse(QPixmap(":/pieces/WhiteHorse.png")),
    WhiteKing(QPixmap(":/pieces/WhiteKing.png")),
    WhitePawn(QPixmap(":/pieces/WhitePawn.png")),
    WhiteQueen(QPixmap(":/pieces/WhiteQueen.png")),
    WhiteBishop(QPixmap(":/pieces/WhiteBishop.png")),
    PieceUnknown(QPixmap(":/pieces/PieceUnknown.png")),
    PieceNone(QPixmap(":/pieces/PieceNone.png"))
{
    ui->setupUi(this);

    echec.SetupBoard();
       blackSquareStyle = getStyleSheetForColour(QColor(Qt::darkGray));
       whiteSquareStyle = getStyleSheetForColour(QColor(Qt::lightGray));

    QPoint bpos(0,0);
    bpos = addSquare(bpos, ui->A_1);
    bpos = addSquare(bpos, ui->A_2);
    bpos = addSquare(bpos, ui->A_3);
    bpos = addSquare(bpos, ui->A_4);
    bpos = addSquare(bpos, ui->A_5);
    bpos = addSquare(bpos, ui->A_6);
    bpos = addSquare(bpos, ui->A_7);
    bpos = addSquare(bpos, ui->A_8);

    bpos = addSquare(bpos, ui->B_1);
    bpos = addSquare(bpos, ui->B_2);
    bpos = addSquare(bpos, ui->B_3);
    bpos = addSquare(bpos, ui->B_4);
    bpos = addSquare(bpos, ui->B_5);
    bpos = addSquare(bpos, ui->B_6);
    bpos = addSquare(bpos, ui->B_7);
    bpos = addSquare(bpos, ui->B_8);

    bpos = addSquare(bpos, ui->C_1);
    bpos = addSquare(bpos, ui->C_2);
    bpos = addSquare(bpos, ui->C_3);
    bpos = addSquare(bpos, ui->C_4);
    bpos = addSquare(bpos, ui->C_5);
    bpos = addSquare(bpos, ui->C_6);
    bpos = addSquare(bpos, ui->C_7);
    bpos = addSquare(bpos, ui->C_8);

    bpos = addSquare(bpos, ui->D_1);
    bpos = addSquare(bpos, ui->D_2);
    bpos = addSquare(bpos, ui->D_3);
    bpos = addSquare(bpos, ui->D_4);
    bpos = addSquare(bpos, ui->D_5);
    bpos = addSquare(bpos, ui->D_6);
    bpos = addSquare(bpos, ui->D_7);
    bpos = addSquare(bpos, ui->D_8);

    bpos = addSquare(bpos, ui->E_1);
    bpos = addSquare(bpos, ui->E_2);
    bpos = addSquare(bpos, ui->E_3);
    bpos = addSquare(bpos, ui->E_4);
    bpos = addSquare(bpos, ui->E_5);
    bpos = addSquare(bpos, ui->E_6);
    bpos = addSquare(bpos, ui->E_7);
    bpos = addSquare(bpos, ui->E_8);

    bpos = addSquare(bpos, ui->F_1);
    bpos = addSquare(bpos, ui->F_2);
    bpos = addSquare(bpos, ui->F_3);
    bpos = addSquare(bpos, ui->F_4);
    bpos = addSquare(bpos, ui->F_5);
    bpos = addSquare(bpos, ui->F_6);
    bpos = addSquare(bpos, ui->F_7);
    bpos = addSquare(bpos, ui->F_8);

    bpos = addSquare(bpos, ui->G_1);
    bpos = addSquare(bpos, ui->G_2);
    bpos = addSquare(bpos, ui->G_3);
    bpos = addSquare(bpos, ui->G_4);
    bpos = addSquare(bpos, ui->G_5);
    bpos = addSquare(bpos, ui->G_6);
    bpos = addSquare(bpos, ui->G_7);
    bpos = addSquare(bpos, ui->G_8);

    bpos = addSquare(bpos, ui->H_1);
    bpos = addSquare(bpos, ui->H_2);
    bpos = addSquare(bpos, ui->H_3);
    bpos = addSquare(bpos, ui->H_4);
    bpos = addSquare(bpos, ui->H_5);
    bpos = addSquare(bpos, ui->H_6);
    bpos = addSquare(bpos, ui->H_7);
    bpos = addSquare(bpos, ui->H_8);


    UpdateBoard();
}

ChessWindow::~ChessWindow()
{
    delete ui;
}

QString ChessWindow::getStyleSheetForColour(QColor &color)
{
    QString style = "QPushButton:pressed {\n";
    style += "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))\n";
    style += "}\n";

    style += "QPushButton {\n";
    if(color.isValid()) {
        style += QString("background-color: %1\n").arg(color.name());
    }
    else
        style += QString("background-color: #ddd\n");

    style += "}\n";
//    style += "{\n";
//    style += "     border: 1px solid black;\n";
//    style += "     border-radius: 5px;\n";
//    style += "}\n";

    style += "QPushButton:disabled {\n";
    style += "    background-color: rgb(170, 170, 127)\n";
    style += "}\n\n";
    style += "QPushButton:hover:!pressed\n";
    style += "{\n";
    style += "    background-color: rgb(170, 170, 127)\n";
    style += "}\n";
    style += "QPushButton:hover:checked\n";
    style += "{\n";
    style += "    background-color: #909\n";
    style += "}\n";
    style += "QPushButton:checked\n";
    style += "{\n";
    style += "    background-color: #f0f\n";
    style += "}\n";

    //    printf("%s",style.toLatin1().data());
    return style;
}

QPoint ChessWindow::addSquare(QPoint pos, class QPushButton *b)
{
    int x = pos.x();
    int y = pos.y();

    // make the button checkable and connect it
    b->setCheckable(true);
    connect(b, SIGNAL(clicked()), this, SLOT(on_buttonClicked()));
    // colour the squares
    if (y % 2){
        if (x %2)
            b->setStyleSheet(blackSquareStyle);
        else
            b->setStyleSheet(whiteSquareStyle);
    }
    else
    {
        if (x %2)
            b->setStyleSheet(whiteSquareStyle);
        else
            b->setStyleSheet(blackSquareStyle);

    }
    Board[y][x] = b;
    x++;
    if (x > 7)
    {
        y++;
        x=0;
    }
    return QPoint(x,y);
}

void ChessWindow::setPiece(int row, int column, Piece *piece)
{
    QPushButton *b = Board[row][column];
    QIcon &icon=PieceUnknown;

    switch(piece->getType())
    {
    case pieceNone:
        icon = PieceNone;
        break;

    case pieceTourNoir:
        icon = BlackCastle;
        break;

    case pieceCavalierNoir:
        icon = BlackHorse;
        break;

    case pieceRoiNoir:
        icon = BlackKing;
        break;

    case piecePionNoir:
        icon = BlackPawn;
        break;

    case pieceReineNoir:
        icon = BlackQueen;
        break;

    case pieceFouNoir:
        icon = BlackBishop;
        break;
    case pieceTourBlanc:
          icon = WhiteCastle;
          break;

      case pieceCavalierBlanc:
          icon = WhiteHorse;
          break;

      case pieceRoiBlanc:
          icon = WhiteKing;
          break;

      case piecePionBlanc:
          icon = WhitePawn;
          break;

      case pieceReineBlanc:
          icon = WhiteQueen;
          break;

      case pieceFouBlanc:
          icon = WhiteBishop;
          break;
default:
        printf("Unknown %d %s\n",piece->getType(), piece->getNom().c_str());
        icon = PieceUnknown;
    }
    b->setIcon(icon);
    b->setIconSize(QSize(150,150));
}

void ChessWindow::on_buttonClicked()
{
    QPushButton *button = (QPushButton *)sender();

    if (button->isChecked()){
        Piece *laPiece1 = nullptr;

        for(int r = 0; r < 8; r++)
        {
            for(int c = 0; c < 8; c++)
            {
                QPushButton *b = Board[r][c];
                if (b != button)
                    b->setChecked(false);
                else
                    laPiece1 = echec.getPiece(r,c);
            }
        }
        if (laPiece1)
        {
            for(int r = 0; r < 8; r++)
            {
                for(int c = 0; c < 8; c++)
                {
                    QPushButton *b = Board[r][c];
                    bool canMove = laPiece1->deplacement(r,c);
                    if (echec.getPiece(r,c)->getType() != pieceNone)
                        if (!echec.canTake(laPiece1, r,c))
                            canMove = false;

                    if (canMove)
                        b->setChecked(true);
                }
            }
        }
        currentlySelectedButton = button;
        printf("b clicked\n");fflush(stdout);
    }
    else
        printf("b clicked but not checked\n");fflush(stdout);
}

#include "chesswindow.h"
#include "ui_chesswindow.h"

ChessWindow::ChessWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChessWindow),
    BlackCastle(QPixmap(":/pieces/BlackCastle.png")),
    BlackHorse(QPixmap(":/pieces/BlackHorse.png")),
    BlackKing(QPixmap(":/pieces/BlackKing.png")),
    BlackPawn(QPixmap(":/pieces/BlackPawn.png")),
    BlackQueen(QPixmap(":/pieces/BlackQueen.png")),
    BlackRook(QPixmap(":/pieces/BlackRook.png")),
    WhiteCastle(QPixmap(":/pieces/WhiteCastle.png")),
    WhiteHorse(QPixmap(":/pieces/WhiteHorse.png")),
    WhiteKing(QPixmap(":/pieces/WhiteKing.png")),
    WhitePawn(QPixmap(":/pieces/WhitePawn.png")),
    WhiteQueen(QPixmap(":/pieces/WhiteQueen.png")),
    WhiteRook(QPixmap(":/pieces/WhiteRook.png"))
{
    ui->setupUi(this);
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

    setPiece(0,0, pieceBlackHorse);
    setPiece(0,1, pieceBlackCastle);

    setPiece(7,0, pieceWhiteHorse);
    setPiece(7,7, pieceWhiteCastle);

}

ChessWindow::~ChessWindow()
{
    delete ui;
}
QPoint ChessWindow::addSquare(QPoint pos, class QPushButton *b)
{
    int x = pos.x();
    int y = pos.y();
    printf("add %d %d \n",x,y);
    Board[y][x] = b;
    x++;
    if (x > 7)
    {
        y++;
        x=0;
    }
    return QPoint(x,y);
}
void ChessWindow::setPiece(int row, int column, ChessPieceEnum piece)
{
    QPushButton *b = Board[row][column];
    QIcon &icon=BlackKing;
    switch(piece)
    {
    case pieceBlackCastle:
        icon = BlackCastle;
        break;
    case pieceBlackHorse:
        icon = BlackHorse;
        break;
    case pieceWhiteHorse:
        icon = WhiteHorse;
        break;
    case pieceWhiteCastle:
        icon = WhiteCastle;
        break;
    }
    b->setIcon(icon);
    b->setIconSize(QSize(150,150));
}

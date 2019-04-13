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
    WhiteRook(QPixmap(":/pieces/WhiteRook.png")),
    PieceUnknown(QPixmap(":/pieces/PieceUnknown.png"))
{
    ui->setupUi(this);

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


    setPiece(0,0, pieceBlackCastle);
    setPiece(0,1, pieceBlackHorse);
    setPiece(0,2, pieceBlackRook);
    setPiece(0,3, pieceBlackKing);
    setPiece(0,4, pieceBlackQueen);
    setPiece(0,5, pieceBlackRook);
    setPiece(0,6, pieceBlackHorse);
    setPiece(0,7, pieceBlackCastle);

    setPiece(1,0, pieceBlackPawn);
    setPiece(1,1, pieceBlackPawn);
    setPiece(1,2, pieceBlackPawn);
    setPiece(1,3, pieceBlackPawn);
    setPiece(1,4, pieceBlackPawn);
    setPiece(1,5, pieceBlackPawn);
    setPiece(1,6, pieceBlackPawn);
    setPiece(1,7, pieceBlackPawn);


    setPiece(6,0, pieceWhitePawn);
    setPiece(6,1, pieceWhitePawn);
    setPiece(6,2, pieceWhitePawn);
    setPiece(6,3, pieceWhitePawn);
    setPiece(6,4, pieceWhitePawn);
    setPiece(6,5, pieceWhitePawn);
    setPiece(6,6, pieceWhitePawn);
    setPiece(6,7, pieceWhitePawn);

    setPiece(7,0, pieceWhiteCastle);
    setPiece(7,1, pieceWhiteHorse);
    setPiece(7,2, pieceWhiteRook);
    setPiece(7,3, pieceWhiteKing);
    setPiece(7,4, pieceWhiteQueen);
    setPiece(7,5, pieceWhiteRook);
    setPiece(7,6, pieceWhiteHorse);
    setPiece(7,7, pieceWhiteCastle);

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
    style += "     border: 1px solid black;\n";
    style += "     border-radius: 5px;\n";
    style += "}\n";
    style += "QPushButton:disabled {\n";
    style += "    background-color: rgb(170, 170, 127)\n";
    style += "}\n\n";
    //    style += "QPushButton:hover:!pressed\n";
    //    style += "{\n";
    //    style += "    background-color: rgb(170, 170, 127)\n";
    //    style += "}\n";

    //    printf("%s",style.toLatin1().data());
    return style;
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
void ChessWindow::setPiece(int row, int column, ChessPieceEnum piece)
{
    QPushButton *b = Board[row][column];
    QIcon &icon=PieceUnknown;
    switch(piece)
    {
    case pieceBlackCastle:
        icon = BlackCastle;
        break;

    case pieceBlackHorse:
        icon = BlackHorse;
        break;

    case pieceBlackKing:
        icon = BlackKing;
        break;

    case pieceBlackPawn:
        icon = BlackPawn;
        break;

    case pieceBlackQueen:
        icon = BlackQueen;
        break;

    case pieceBlackRook:
        icon = BlackRook;
        break;

    case pieceWhiteCastle:
        icon = WhiteCastle;
        break;

    case pieceWhiteHorse:
        icon = WhiteHorse;
        break;

    case pieceWhiteKing:
        icon = WhiteKing;
        break;

    case pieceWhitePawn:
        icon = WhitePawn;
        break;

    case pieceWhiteQueen:
        icon = WhiteQueen;
        break;

    case pieceWhiteRook:
        icon = WhiteRook;
        break;
default:
        icon = PieceUnknown;
    }
    b->setIcon(icon);
    b->setIconSize(QSize(150,150));
}

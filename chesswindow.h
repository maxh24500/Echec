#ifndef CHESSWINDOW_H
#define CHESSWINDOW_H

#include <QMainWindow>

namespace Ui {
class ChessWindow;
}

typedef enum _ChessPieceEnum {
    pieceBlackCastle,
    pieceBlackHorse,
    pieceBlackKing,
    pieceBlackPawn,
    pieceBlackQueen,
    pieceBlackRook,
    pieceWhiteCastle,
    pieceWhiteHorse,
    pieceWhiteKing,
    pieceWhitePawn,
    pieceWhiteQueen,
    pieceWhiteRook,
}ChessPieceEnum;

class ChessWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChessWindow(QWidget *parent = 0);
    ~ChessWindow();

private:
    Ui::ChessWindow *ui;
    QIcon BlackCastle;
    QIcon BlackHorse;
    QIcon BlackKing;
    QIcon BlackPawn;
    QIcon BlackQueen;
    QIcon BlackRook;
    QIcon WhiteCastle;
    QIcon WhiteHorse;
    QIcon WhiteKing;
    QIcon WhitePawn;
    QIcon WhiteQueen;
    QIcon WhiteRook;
    QIcon PieceUnknown;

    class QPushButton* Board[8][8];
    void setPiece(int row, int column, ChessPieceEnum piece);
    QPoint addSquare(QPoint pos, class QPushButton *b);
};

#endif // CHESSWINDOW_H

#ifndef CHESSWINDOW_H
#define CHESSWINDOW_H

#include <QMainWindow>
#include "Echecv4/echecinterface.h"

namespace Ui {
class ChessWindow;
}


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
    QIcon BlackBishop;
    QIcon WhiteCastle;
    QIcon WhiteHorse;
    QIcon WhiteKing;
    QIcon WhitePawn;
    QIcon WhiteQueen;
    QIcon WhiteBishop;
    QIcon PieceUnknown;
    QIcon PieceNone;

    QString blackSquareStyle;
    QString whiteSquareStyle;

    class QPushButton* Board[8][8];
    void setPiece(int row, int column, Piece *piece);
    QPoint addSquare(QPoint pos, class QPushButton *b);
    QString ChessWindow::getStyleSheetForColour(QColor &color);
    class QPushButton *currentlySelectedButton;

    EchecInterface echec;
private slots:
    void on_buttonClicked();
};

#endif // CHESSWINDOW_H

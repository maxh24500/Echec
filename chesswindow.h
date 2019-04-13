#ifndef CHESSWINDOW_H
#define CHESSWINDOW_H

#include <QMainWindow>

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
};

#endif // CHESSWINDOW_H

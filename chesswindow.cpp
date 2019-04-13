#include "chesswindow.h"
#include "ui_chesswindow.h"

ChessWindow::ChessWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChessWindow)
{
    ui->setupUi(this);
}

ChessWindow::~ChessWindow()
{
    delete ui;
}

#include "connectionwindow.h"
#include "ui_connectionwindow.h"

Connectionwindow::Connectionwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connectionwindow)
{
    ui->setupUi(this);
}

Connectionwindow::~Connectionwindow()
{
    delete ui;
}

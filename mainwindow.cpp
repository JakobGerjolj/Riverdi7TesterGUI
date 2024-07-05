#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_CanHandler = new CanHandler;



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rpmPortSlider_sliderMoved(int position)
{
    uint16_t temp;
    if(position == 0){
        temp=0;
    }else{
        temp = (position+1) * 40;
    }

    m_CanHandler -> setPortRPM(temp);

}




void MainWindow::on_voltagePort_sliderMoved(int position)
{

    uint16_t temp;
    temp = position * 4;

    m_CanHandler -> setPortVoltage(temp);

}


void MainWindow::on_currentPort_sliderMoved(int position)
{

    m_CanHandler -> setPortCurrent(position);
}


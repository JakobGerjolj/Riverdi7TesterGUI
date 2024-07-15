#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_CanHandler = new CanHandler;

    ui -> sendingStatus -> setStyleSheet("QLabel { background-color : red; }");
    ui -> stbStatus -> setStyleSheet("QLabel { background-color : red; }");
    ui -> speedSendingStatus -> setStyleSheet("QLabel { background-color : red; }");
    ui -> tripSendingLabel -> setStyleSheet("QLabel { background-color : red; }");
    ui -> PortMotorTempLabel -> setStyleSheet("QLabel { background-color : red; }");
    ui -> StbMotorText -> setStyleSheet("QLabel { background-color : red; }");
    ui -> TempPackageLabel -> setStyleSheet("QLabel { background-color : red; }");
    ui -> PortBatInfoLabel -> setStyleSheet("QLabel { background-color : red; }");
    ui -> PositionSendingLabel -> setStyleSheet("QLabel { background-color : red; }");
    ui -> PortBatInfoLabel_2 -> setStyleSheet("QLabel { background-color : red; }");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rpmPortSlider_sliderMoved(int position)
{

    m_CanHandler -> setPortRPM(position);

}




void MainWindow::on_voltagePort_sliderMoved(int position)
{

    m_CanHandler -> setPortVoltage(position);

}


void MainWindow::on_currentPort_sliderMoved(int position)
{

    qDebug()<<"Raw from slider: "<<position;
    int16_t temp = static_cast<int16_t>(position);
    m_CanHandler -> setPortCurrent(temp);

    qDebug()<<"After cast: "<<temp;
    qDebug()<<"Number written in hex after casting to int16_t: "<<QString::asprintf("%x", temp & 0xffff);
    qDebug()<<"Number before casting in hex: "<<QString::asprintf("%x", position & 0xffff);
}


void MainWindow::on_pushButton_clicked()
{

    m_CanHandler -> toggleSendingPortMessage();
    if(!areWeSendingPortMsg){
        areWeSendingPortMsg = true;
        ui -> sendingStatus -> setText("Sending packages");
        ui -> sendingStatus -> setStyleSheet("QLabel { background-color : green; }");
    }else {

        areWeSendingPortMsg = false;
        ui -> sendingStatus -> setText("Not sending");
        ui -> sendingStatus -> setStyleSheet("QLabel { background-color : red; }");
    }



}


void MainWindow::on_rpmStarboardSlider_sliderMoved(int position)
{

    m_CanHandler -> setStbRPM(position);

}


void MainWindow::on_rpmStarboardVoltage_sliderMoved(int position)
{

    m_CanHandler -> setStbVoltage(position);

}


void MainWindow::on_CurrentStarboardSlider_sliderMoved(int position)
{

    m_CanHandler -> setStbCurrent(static_cast<int16_t>(position));

}


void MainWindow::on_pushButton_2_clicked()
{

    m_CanHandler ->toggleSendingStbMessage();
    if(!areWeSendingStbMsg){

        areWeSendingStbMsg = true;
        ui -> stbStatus -> setText("Sending packages");
        ui -> stbStatus -> setStyleSheet("QLabel { background-color : green; }");
    }else {

        areWeSendingStbMsg = false;
        ui -> stbStatus -> setText("Not sending packages");
        ui -> stbStatus -> setStyleSheet("QLabel { background-color : red; }");
    }
}


void MainWindow::on_speedSlider_sliderMoved(int position)
{

    m_CanHandler -> setSpeed(position);

}


void MainWindow::on_pushButton_3_clicked()
{

    m_CanHandler -> toggleSendingSpeedMessage();
    if(!areWeSendingSpeedMsg){

        areWeSendingSpeedMsg = true;
        ui -> speedSendingStatus -> setText("Sending packages");
        ui -> speedSendingStatus -> setStyleSheet("QLabel { background-color : green; }");
    }else{

        areWeSendingSpeedMsg = false;
        ui -> speedSendingStatus -> setText("Not sending");
        ui -> speedSendingStatus -> setStyleSheet("QLabel { background-color : red; }");
    }
}


void MainWindow::on_speedSlider_2_sliderMoved(int position)
{


    m_CanHandler -> setDistToEmpty(position);

}


void MainWindow::on_pushButton_4_clicked()
{

    m_CanHandler ->toggleSendingTripMessage();
    if(!areWeSendingTripMsg){

        areWeSendingTripMsg = true;
        ui->tripSendingLabel->setText("Sending messages");
        ui->tripSendingLabel->setStyleSheet("QLabel { background-color : green; }");
    }else{
        areWeSendingTripMsg = false;
        ui->tripSendingLabel->setText("Not sending");
        ui->tripSendingLabel->setStyleSheet("QLabel { background-color : red; }");

    }

}


void MainWindow::on_speedSlider_3_sliderMoved(int position)
{

    m_CanHandler -> setTimeToEmpty(position);

}


void MainWindow::on_speedSlider_5_sliderMoved(int position)
{

    m_CanHandler -> setStbMotorTemp(position);

}


void MainWindow::on_speedSlider_4_sliderMoved(int position)
{

    m_CanHandler -> setPortMotorTemp(position);

}


void MainWindow::on_pushButton_5_clicked()
{

    m_CanHandler -> toggleSendingPortTempMessage();
    if(!areWeSendingPortMotorTemp){
        areWeSendingPortMotorTemp = true;
        ui -> PortMotorTempLabel -> setText("Sending messages");
        ui -> PortMotorTempLabel -> setStyleSheet("QLabel { background-color : green; }");
    }else
    {
        areWeSendingPortMotorTemp = false;
        ui -> PortMotorTempLabel -> setText("Not sending messages");
        ui -> PortMotorTempLabel -> setStyleSheet("QLabel { background-color : red; }");
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    m_CanHandler -> toggleSendingStbTempMessage();
    if(!areWeSendingStbMotorTemp){
        areWeSendingStbMotorTemp = true;
        ui -> StbMotorText -> setText("Sending packages");
        ui -> StbMotorText -> setStyleSheet("QLabel { background-color : green; }");
    }else{
        areWeSendingStbMotorTemp = false;
        ui -> StbMotorText -> setText("Not sending");
        ui -> StbMotorText -> setStyleSheet("QLabel { background-color : red; }");
    }

}


void MainWindow::on_speedSlider_6_sliderMoved(int position)
{

    m_CanHandler -> setHiCellTemp(position);

}


void MainWindow::on_pushButton_7_clicked()
{

    qDebug()<< "Pressed button";

    m_CanHandler -> toggleSendingHiCellTemp();
    if(areWeSendingHiCellTemp){
        areWeSendingHiCellTemp = false;
        ui -> TempPackageLabel -> setText("Not sending");
        ui -> TempPackageLabel -> setStyleSheet("QLabel { background-color : red; }");
    }else{
        areWeSendingHiCellTemp = true;
        ui -> TempPackageLabel -> setText("Sending messages");
        ui -> TempPackageLabel -> setStyleSheet("QLabel { background-color : green; }");
    }

}


void MainWindow::on_speedSlider_7_sliderMoved(int position)
{

    m_CanHandler -> setSOC(position);

}


void MainWindow::on_speedSlider_8_sliderMoved(int position)
{

    m_CanHandler -> setStbInverterTemp(position);

}


void MainWindow::on_speedSlider_9_sliderMoved(int position)
{
    m_CanHandler -> setPortInverterTemp(position);
}


void MainWindow::on_speedSlider_10_sliderMoved(int position)
{

    m_CanHandler -> setBatVoltage(position);

}


void MainWindow::on_pushButton_8_clicked()
{

    m_CanHandler -> toggleSendingBatInfoMessage();
    if(areWeSendingBatInfo){
        areWeSendingBatInfo = false;
        ui -> PortBatInfoLabel -> setText("Not sending");
        ui -> PortBatInfoLabel -> setStyleSheet("QLabel { background-color : red; }");
    }else{
        areWeSendingBatInfo = true;
        ui -> PortBatInfoLabel -> setText("Sending messages");
        ui -> PortBatInfoLabel -> setStyleSheet("QLabel { background-color : green; }");
    }

}


void MainWindow::on_speedSlider_11_sliderMoved(int position)
{
    m_CanHandler -> setBatCurrent((int16_t)position);
}


void MainWindow::on_speedSlider_12_sliderMoved(int position)
{
    m_CanHandler -> setLoCellTemp(position);
}


void MainWindow::on_speedSlider_13_sliderMoved(int position)
{

    int64_t fullValue = (int64_t)(position*10e11);

    m_CanHandler -> setLat(fullValue);

}


void MainWindow::on_speedSlider_14_sliderMoved(int position)
{
    int64_t fullValue = (int64_t)(position*10e11);

    m_CanHandler -> setLon(fullValue);
}


void MainWindow::on_pushButton_9_clicked()
{


    m_CanHandler -> toggleSendingPositionPackage();
    if(areWeSendingPosition){
        areWeSendingPosition = false;
        ui -> PositionSendingLabel -> setText("Not sending");
        ui -> PositionSendingLabel -> setStyleSheet("QLabel { background-color : red; }");
    }else{
        areWeSendingPosition = true;
        ui -> PositionSendingLabel -> setText("Sending messages");
        ui -> PositionSendingLabel -> setStyleSheet("QLabel { background-color : green; }");
    }

}


void MainWindow::on_speedSlider_16_sliderMoved(int position)
{

    m_CanHandler -> setHiVoltage(position);

}


void MainWindow::on_speedSlider_17_sliderMoved(int position)
{

    m_CanHandler -> setLoVoltage(position);

}


void MainWindow::on_pushButton_11_clicked()
{

    m_CanHandler -> toggleSendingCellVoltagePackage();
    if(areWeSendingCellVoltage){
        areWeSendingCellVoltage = false;
        ui -> PortBatInfoLabel_2 -> setText("Not sending");
        ui -> PortBatInfoLabel_2 -> setStyleSheet("QLabel { background-color : red; }");
    }else{
        areWeSendingCellVoltage = true;
        ui -> PortBatInfoLabel_2 -> setText("Sending messages");
        ui -> PortBatInfoLabel_2 -> setStyleSheet("QLabel { background-color : green; }");
    }

}


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
    ui -> stbStatus_2 -> setStyleSheet("QLabel { background-color : red; }");
    ui -> PortBatInfoLabel_3 -> setText("Not sending");
    ui -> PortBatInfoLabel_3 -> setStyleSheet("QLabel { background-color : red; }");
    ui -> PortBatInfoLabel_4 -> setText("Not sending");
    ui -> PortBatInfoLabel_4 -> setStyleSheet("QLabel { background-color: red; }");
    ui -> PortBatInfoLabel_5 -> setText("Not sending");
    ui -> PortBatInfoLabel_5 -> setStyleSheet("QLabel { background-color: red; }");
    ui -> stbStatus_3 -> setText("Not sending");
    ui -> stbStatus_3 -> setStyleSheet("QLabel { background-color: red; }");
    ui -> stbStatus_4 -> setText("Not sending");
    ui -> stbStatus_4 -> setStyleSheet("QLabel { background-color: red; }");
    ui -> stbStatus_5 -> setText("Not sending");
    ui -> stbStatus_5 -> setStyleSheet("QLabel { background-color: red; }");
    ui -> stbStatus_6 -> setText("Not sending");
    ui -> stbStatus_6 -> setStyleSheet("QLabel { background-color: red; }");
    ui -> stbStatus_7 -> setText("Not sending");
    ui -> stbStatus_7 -> setStyleSheet("QLabel { background-color: red; }");
    ui -> label_67 -> setText(QString::number(0) + " RPM");
    ui -> label_68 -> setText(QString::number(0) + " RPM");

    ui -> radioButton -> setChecked(true);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveAllSliders);
    //timer -> start();

}

MainWindow::~MainWindow()
{
    delete m_CanHandler;
    delete ui;
}

void MainWindow::on_rpmPortSlider_sliderMoved(int position)
{

    //m_CanHandler -> setPortRPM(position);

}




void MainWindow::on_voltagePort_sliderMoved(int position)
{

    // m_CanHandler -> setPortVoltage(position);



    // int power = (position/10) * ((ui -> currentPort -> value()) / 10);
    // ui -> calculatedPower -> setText(QString::number(power));

}


void MainWindow::on_currentPort_sliderMoved(int position)
{

    // qDebug()<<"Raw from slider: "<<position;
    // int16_t temp = static_cast<int16_t>(position);
    // m_CanHandler -> setPortCurrent(temp);

    // qDebug()<<"After cast: "<<temp;
    // qDebug()<<"Number written in hex after casting to int16_t: "<<QString::asprintf("%x", temp & 0xffff);
    // qDebug()<<"Number before casting in hex: "<<QString::asprintf("%x", position & 0xffff);


    // int power = (position/10) * ((ui -> voltagePort -> value()) / 10);
    // ui -> calculatedPower -> setText(QString::number(power));


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

    // m_CanHandler -> setStbRPM(position);

}


void MainWindow::on_rpmStarboardVoltage_sliderMoved(int position)
{

    // m_CanHandler -> setStbVoltage(position);

    // int power = (position/10) * ((ui -> CurrentStarboardSlider -> value()) / 10);
    // ui -> calculatedPowerStb -> setText(QString::number(power));

}


void MainWindow::on_CurrentStarboardSlider_sliderMoved(int position)
{

    // m_CanHandler -> setStbCurrent(static_cast<int16_t>(position));

    // int power = (position/10) * ((ui -> CurrentStarboardSlider -> value()) / 10);
    // ui -> calculatedPowerStb -> setText(QString::number(power));

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

    // m_CanHandler -> setSpeed(position);

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


    // m_CanHandler -> setDistToEmpty(position);

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

    // m_CanHandler -> setTimeToEmpty(position);

}


void MainWindow::on_speedSlider_5_sliderMoved(int position)
{

    // m_CanHandler -> setStbMotorTemp(position);

}


void MainWindow::on_speedSlider_4_sliderMoved(int position)
{

    // m_CanHandler -> setPortMotorTemp(position);

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
        ui -> PortMotorTempLabel -> setText("Not sending");
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

    // m_CanHandler -> setHiCellTemp(position);

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

    // m_CanHandler -> setSOC(position);

}


void MainWindow::on_speedSlider_8_sliderMoved(int position)
{

    // m_CanHandler -> setStbInverterTemp(position);

}


void MainWindow::on_speedSlider_9_sliderMoved(int position)
{
    // m_CanHandler -> setPortInverterTemp(position);
}


void MainWindow::on_speedSlider_10_sliderMoved(int position)
{

    // m_CanHandler -> setBatVoltage(position);

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
    // m_CanHandler -> setBatCurrent((int16_t)position);
}


void MainWindow::on_speedSlider_12_sliderMoved(int position)
{
    // m_CanHandler -> setLoCellTemp(position);
}


void MainWindow::on_speedSlider_13_sliderMoved(int position)
{

    // int64_t fullValue = static_cast<int64_t>(position*10e11);

    // m_CanHandler -> setLat(fullValue);

}


void MainWindow::on_speedSlider_14_sliderMoved(int position)
{
    // int64_t fullValue = static_cast<int64_t>(position*10e11);

    // m_CanHandler -> setLon(fullValue);
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

    // m_CanHandler -> setHiVoltage(position);

}


void MainWindow::on_speedSlider_17_sliderMoved(int position)
{

    // m_CanHandler -> setLoVoltage(position);

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


void MainWindow::on_rpmStarboardSlider_2_sliderMoved(int position)
{
    m_CanHandler -> setChargerTemp(static_cast<int16_t>(position));
}


void MainWindow::on_pushButton_12_clicked()
{
    m_CanHandler -> toggleSendingChargerInfo();
    if(areWeSendingChargerInfo){
        areWeSendingChargerInfo = false;
        ui -> stbStatus_2 -> setText("Not sending");
        ui -> stbStatus_2 -> setStyleSheet("QLabel { background-color : red; }");
    }else{
        areWeSendingChargerInfo = true;
        ui -> stbStatus_2 -> setText("Sending messages");
        ui -> stbStatus_2 -> setStyleSheet("QLabel { background-color : green; }");
    }
}


void MainWindow::on_rpmStarboardVoltage_2_sliderMoved(int position)
{
    //m_CanHandler -> setChargerVoltage(position);
}


void MainWindow::on_CurrentStarboardSlider_2_sliderMoved(int position)
{
    // m_CanHandler -> setChargerCurrent(position);
}


void MainWindow::on_speedSlider_18_sliderMoved(int position)
{
    // m_CanHandler -> setTimeToFull((int16_t)position);
}


void MainWindow::on_pushButton_13_clicked()
{

    QString type = ui -> textEdit -> toPlainText();

    QString id = ui -> textEdit_2 -> toPlainText();

    QString name = ui -> textEdit_3 -> toPlainText();

    QString desc = ui -> textEdit_4 -> toPlainText();







    QString completeString = "t:" + type + ";i:" + id + ";n:" + name + ";d:" + desc + ";";

    QByteArray byteArray = completeString.toUtf8();

    qDebug()<<"\nWe are sending: \n" << completeString;

    m_CanHandler -> sendAlarmPackage(byteArray);

    int tempNumber = ui -> textEdit_2 -> toPlainText().toInt();

    tempNumber++;

    ui -> textEdit_2 -> setText(QString::number(tempNumber));

    ui -> textEdit_3 -> setText("BMS" + QString::number(tempNumber));



    //qDebug() << byteArray.size();

    //Put it into can handler, and send it

}


void MainWindow::on_pushButton_14_clicked()
{

    QString type = ui -> textEdit_5 -> toPlainText();
    QString id = ui -> textEdit_6 -> toPlainText();

    uint8_t typeInint = (uint8_t)type.toInt();

    uint16_t idInInt = (uint16_t)id.toInt();

    m_CanHandler -> sendAlarmNotActivePackage(typeInint, idInInt);
    //Send not active
}


void MainWindow::on_speedSlider_19_sliderMoved(int position)
{

    // m_CanHandler -> setDepth(static_cast<uint32_t>(position));

}


void MainWindow::on_pushButton_15_clicked()
{

    m_CanHandler -> toggleSendingDepthInfo();
    if(areWeSendingDepthData){
        areWeSendingDepthData = false;
        ui -> PortBatInfoLabel_3 -> setText("Not sending");
        ui -> PortBatInfoLabel_3 -> setStyleSheet("QLabel { background-color : red; }");
    }else{
        areWeSendingDepthData = true;
        ui -> PortBatInfoLabel_3 -> setText("Sending messages");
        ui -> PortBatInfoLabel_3 -> setStyleSheet("QLabel { background-color : green; }");
    }

}


void MainWindow::on_pushButton_16_clicked()
{

    QString type = ui -> textEdit -> toPlainText();

    QString id = ui -> textEdit_2 -> toPlainText();

    QString name = ui -> textEdit_3 -> toPlainText();

    QString desc = ui -> textEdit_4 -> toPlainText();


    QString completeString = "t:" + type + ";i:" + id + ";n:" + name + ";d:" + desc + ";";

    QByteArray byteArray = completeString.toUtf8();



    for(int i = 1; i < 46; i++){

        QString asciiString = QString::number(i);

        completeString = "t:" + type + ";i:" + asciiString + ";n:" + name + ";d:" + desc + ";";

        qDebug() << "\nString sent: " << completeString << "\n";

        byteArray = completeString.toUtf8();

        bool isWait = true;

        // QTimer::singleShot(500, this, [&](){
        //     isWait = false;
        // });

        // while(isWait){};


        m_CanHandler -> sendAlarmPackage(byteArray);
        //send 50 call here


        // std::chrono::this_thread::sleep_for(std::chrono::senconds(1));

        //sleep(1);

        // QThread::msleep(500); // Blocking delay

    }
}


void MainWindow::on_radioButton_clicked() //DCDC status OK pressed
{

    m_CanHandler -> setDCDCStatus(0);

}


void MainWindow::on_radioButton_3_clicked() //DCDC status WARNING pressed
{

    m_CanHandler -> setDCDCStatus(2);

}


void MainWindow::on_radioButton_2_clicked() //DCDC status FAULT pressed
{

    m_CanHandler -> setDCDCStatus(3);

}


void MainWindow::on_speedSlider_20_sliderMoved(int position)
{

    // m_CanHandler -> setDCDCVoltage(static_cast<uint16_t>(position));

}


void MainWindow::on_speedSlider_21_sliderMoved(int position)
{

    // m_CanHandler -> setDCDCCurrent(static_cast<int16_t>(position));

}


void MainWindow::on_pushButton_17_clicked()
{

    m_CanHandler -> toggleSendingDCDCMessage();

    if(areWeSendingDCDCData){
        areWeSendingDCDCData = false;
        ui -> PortBatInfoLabel_4 -> setText("Not sending");
        ui -> PortBatInfoLabel_4 -> setStyleSheet("QLabel { background-color: red; }");
        // ui -> PortBatInfoLabel_3 -> setText("Not sending");
        // ui -> PortBatInfoLabel_3 -> setStyleSheet("QLabel { background-color : red; }");
    }else{
        areWeSendingDCDCData = true;
        ui -> PortBatInfoLabel_4 -> setText("Sending messages");
        ui -> PortBatInfoLabel_4 -> setStyleSheet("QLabel { background-color: green; }");
        // ui -> PortBatInfoLabel_3 -> setText("Sending messages");
        // ui -> PortBatInfoLabel_3 -> setStyleSheet("QLabel { background-color : green; }");
    }

}


void MainWindow::on_pushButton_18_clicked()
{

    m_CanHandler -> toggleSendingVCUMessage();

    if(areWeSendingVCU){
        areWeSendingVCU = false;
        ui -> PortBatInfoLabel_5 -> setText("Not sending");
        ui -> PortBatInfoLabel_5 -> setStyleSheet("QLabel { background-color: red; }");
        // ui -> PortBatInfoLabel_3 -> setText("Not sending");
        // ui -> PortBatInfoLabel_3 -> setStyleSheet("QLabel { background-color : red; }");
    }else{
        areWeSendingVCU = true;
        ui -> PortBatInfoLabel_5 -> setText("Sending messages");
        ui -> PortBatInfoLabel_5 -> setStyleSheet("QLabel { background-color: green; }");
        // ui -> PortBatInfoLabel_3 -> setText("Sending messages");
        // ui -> PortBatInfoLabel_3 -> setStyleSheet("QLabel { background-color : green; }");
    }

}


void MainWindow::on_radioButton_4_clicked()
{

    m_CanHandler -> setVCUStatus(1);

}


void MainWindow::on_radioButton_5_clicked()
{

    m_CanHandler -> setVCUStatus(3);

}


void MainWindow::on_pushButton_19_clicked()
{

    m_CanHandler -> toggleSendingCharger2Message();

    if(areWeSendingChargerInfo2){
        areWeSendingChargerInfo2 = false;
        ui -> stbStatus_3 -> setText("Not sending");
        ui -> stbStatus_3 -> setStyleSheet("QLabel { background-color: red; }");

    }else{
        areWeSendingChargerInfo2 = true;
        ui -> stbStatus_3 -> setText("Sending messages");
        ui -> stbStatus_3 -> setStyleSheet("QLabel { background-color: green; }");

    }

}


void MainWindow::on_rpmStarboardSlider_3_sliderMoved(int position)
{

    // m_CanHandler -> setCharger2VoltageL1((uint16_t)position);

}


void MainWindow::on_rpmStarboardVoltage_3_sliderMoved(int position)
{

    // m_CanHandler -> setCharger2VoltageL2((uint16_t)position);

}


void MainWindow::on_CurrentStarboardSlider_3_sliderMoved(int position)
{

    // m_CanHandler -> setCharger2VoltageL3((uint16_t)position);

}


void MainWindow::on_CurrentStarboardSlider_4_sliderMoved(int position)
{

    // m_CanHandler -> setCharger2Temperature1((uint8_t)position);

}


void MainWindow::on_pushButton_20_clicked()
{

    m_CanHandler -> toggleSendingCharger3Message();

    if(areWeSendingChargerInfo3){
        areWeSendingChargerInfo3 = false;
        ui -> stbStatus_4 -> setText("Not sending");
        ui -> stbStatus_4 -> setStyleSheet("QLabel { background-color: red; }");

    }else{
        areWeSendingChargerInfo3 = true;
        ui -> stbStatus_4 -> setText("Sending messages");
        ui -> stbStatus_4 -> setStyleSheet("QLabel { background-color: green; }");

    }

}


void MainWindow::on_rpmStarboardSlider_4_sliderMoved(int position)
{

    // m_CanHandler -> setCharger3CurrentL1((int16_t)position);

}


void MainWindow::on_rpmStarboardVoltage_4_sliderMoved(int position)
{

    // m_CanHandler -> setCharger3CurrentL2((int16_t)position);

}


void MainWindow::on_CurrentStarboardSlider_5_sliderMoved(int position)
{

    // m_CanHandler -> setCharger3CurrentL3((int16_t)position);

}


void MainWindow::on_pushButton_21_clicked()
{

    m_CanHandler -> toggleSendingPortMotorStatus();

    if(areWeSendingPortMotorInfo){
        areWeSendingPortMotorInfo = false;
        ui -> stbStatus_5 -> setText("Not sending");
        ui -> stbStatus_5 -> setStyleSheet("QLabel { background-color: red; }");

    }else{
        areWeSendingPortMotorInfo = true;
        ui -> stbStatus_5 -> setText("Sending messages");
        ui -> stbStatus_5 -> setStyleSheet("QLabel { background-color: green; }");

    }


}


void MainWindow::on_radioButton_6_clicked()
{

    m_CanHandler -> setMotorStatus(0);

}


void MainWindow::on_radioButton_7_clicked()
{

    m_CanHandler -> setMotorStatus(1);

}


void MainWindow::on_radioButton_8_clicked()
{

    m_CanHandler -> setMotorStatus(2);

}


void MainWindow::on_radioButton_9_clicked()
{

    m_CanHandler -> setMotorStatus(3);

}


void MainWindow::on_radioButton_10_clicked()
{

    m_CanHandler -> setDCDCStatus(1);

}


void MainWindow::on_radioButton_15_clicked()
{

    m_CanHandler -> setBMSStatus(0);

}


void MainWindow::on_radioButton_16_clicked()
{

    m_CanHandler -> setBMSStatus(1);

}


void MainWindow::on_radioButton_17_clicked()
{

    m_CanHandler -> setBMSStatus(2);

}


void MainWindow::on_radioButton_18_clicked()
{

    m_CanHandler -> setBMSStatus(3);

}


void MainWindow::on_radioButton_11_clicked()
{

    m_CanHandler -> setChargerStatus(0);

}


void MainWindow::on_radioButton_12_clicked()
{

    m_CanHandler -> setChargerStatus(1);

}




void MainWindow::on_radioButton_13_clicked()
{

    m_CanHandler -> setChargerStatus(2);

}




void MainWindow::on_radioButton_14_clicked()
{

    m_CanHandler -> setChargerStatus(3);

}


void MainWindow::on_pushButton_22_clicked()
{

    m_CanHandler -> sendMotorDirectionLeft();

}

void MainWindow::on_pushButton_23_clicked()
{

    m_CanHandler -> sendMotorDirectionRight();

}


void MainWindow::on_speedSlider_22_sliderMoved(int position)
{

    ui -> label_67 -> setText(QString::number(position) + " RPM");

}


void MainWindow::on_pushButton_24_clicked()
{

    m_CanHandler -> sendMotorContinousRPM(ui -> speedSlider_22 -> value());

}


void MainWindow::on_speedSlider_23_sliderMoved(int position)
{

    ui -> label_68 -> setText(QString::number(position) + " RPM");

}


void MainWindow::on_pushButton_25_clicked()
{

    m_CanHandler -> sendMotorPeakRPM(ui -> speedSlider_23 -> value());

}

void MainWindow::on_pushButton_26_clicked() //Disabled NFC lock button
{

    m_CanHandler -> sendLeverNFCDisabled();

}

void MainWindow::on_pushButton_27_clicked() //Enabled NFC unlock button
{

    m_CanHandler -> sendLeverNFCEnabled();

}


void MainWindow::on_pushButton_28_clicked()
{

    m_CanHandler -> sendVCUResponse();

}


void MainWindow::on_pushButton_29_clicked()
{

    m_CanHandler -> sendECUResponse();

}

void MainWindow::moveAllSliders()
{

    ui -> rpmPortSlider -> setValue(sliderMover*100);
    ui -> voltagePort -> setValue(sliderMover*100);
    ui -> currentPort -> setValue(sliderMover*10);
    ui -> rpmStarboardSlider -> setValue(sliderMover*100);
    ui -> rpmStarboardVoltage -> setValue(sliderMover*100);
    ui -> CurrentStarboardSlider -> setValue(sliderMover*10);
    ui -> speedSlider -> setValue(sliderMover*10);
    ui -> speedSlider_2 -> setValue(sliderMover*10000);
    ui -> speedSlider_3 -> setValue(sliderMover*10000);
    ui -> speedSlider_5 -> setValue(sliderMover*100);
    ui -> speedSlider_8 -> setValue(sliderMover*100);
    ui -> speedSlider_6 -> setValue(sliderMover*100);
    ui -> speedSlider_12 -> setValue(sliderMover*100);
    ui -> speedSlider_7 -> setValue(sliderMover);
    ui -> speedSlider_18 -> setValue(sliderMover*100);
    ui -> speedSlider_4 -> setValue(sliderMover*100);
    ui -> speedSlider_9 -> setValue(sliderMover*10);
    ui -> speedSlider_10 -> setValue(sliderMover*10);
    ui -> speedSlider_11 -> setValue(sliderMover*50);
    ui -> speedSlider_19 -> setValue(sliderMover*1000);
    ui -> speedSlider_13 -> setValue(sliderMover*1000);
    ui -> speedSlider_14 -> setValue(sliderMover);
    ui -> speedSlider_15 -> setValue(sliderMover*100);
    ui -> speedSlider_16 -> setValue(sliderMover*100);
    ui -> speedSlider_17 -> setValue(sliderMover*10);
    ui -> rpmStarboardVoltage_2 -> setValue(sliderMover*10);
    ui -> CurrentStarboardSlider_2 -> setValue(sliderMover*10);
    ui -> rpmStarboardSlider_3 -> setValue(sliderMover*10);
    ui -> rpmStarboardVoltage_3 -> setValue(sliderMover*10);
    ui -> CurrentStarboardSlider_3 -> setValue(sliderMover*10);
    ui -> CurrentStarboardSlider_4 -> setValue(sliderMover*10);
    ui -> rpmStarboardSlider_4 -> setValue(sliderMover*10);
    ui -> rpmStarboardVoltage_4 -> setValue(sliderMover);
    ui -> CurrentStarboardSlider_5 -> setValue(sliderMover);
    ui -> speedSlider_20 -> setValue(sliderMover*10);
    ui -> speedSlider_21 -> setValue(sliderMover*10);

    //QApplication::processEvents();

    sliderMover++;

}


void MainWindow::on_pushButton_30_clicked()
{

    if(timer -> isActive()){

        timer -> stop();

    }else{

        timer -> start(200);

    }

}


void MainWindow::on_pushButton_31_clicked()
{

    ui -> rpmPortSlider -> setValue(0);
    ui -> voltagePort -> setValue(0);
    ui -> currentPort -> setValue(0);
    ui -> rpmStarboardSlider -> setValue(0);
    ui -> rpmStarboardVoltage -> setValue(0);
    ui -> CurrentStarboardSlider -> setValue(0);
    ui -> speedSlider -> setValue(0);
    ui -> speedSlider_2 -> setValue(0);
    ui -> speedSlider_3 -> setValue(0);
    ui -> speedSlider_5 -> setValue(0);
    ui -> speedSlider_8 -> setValue(0);
    ui -> speedSlider_6 -> setValue(0);
    ui -> speedSlider_12 -> setValue(0);
    ui -> speedSlider_7 -> setValue(0);
    ui -> speedSlider_18 -> setValue(0);
    ui -> speedSlider_4 -> setValue(0);
    ui -> speedSlider_9 -> setValue(0);
    ui -> speedSlider_10 -> setValue(0);
    ui -> speedSlider_11 -> setValue(0);
    ui -> speedSlider_19 -> setValue(0);
    ui -> speedSlider_13 -> setValue(0);
    ui -> speedSlider_14 -> setValue(0);
    ui -> speedSlider_15 -> setValue(0);
    ui -> speedSlider_16 -> setValue(0);
    ui -> speedSlider_17 -> setValue(0);
    ui -> rpmStarboardVoltage_2 -> setValue(0);
    ui -> CurrentStarboardSlider_2 -> setValue(0);
    ui -> rpmStarboardSlider_3 -> setValue(0);
    ui -> rpmStarboardVoltage_3 -> setValue(0);
    ui -> CurrentStarboardSlider_3 -> setValue(0);
    ui -> CurrentStarboardSlider_4 -> setValue(0);
    ui -> rpmStarboardSlider_4 -> setValue(0);
    ui -> rpmStarboardVoltage_4 -> setValue(0);
    ui -> CurrentStarboardSlider_5 -> setValue(0);
    ui -> speedSlider_20 -> setValue(0);
    ui -> speedSlider_21 -> setValue(0);

    sliderMover=0;


}


void MainWindow::on_rpmPortSlider_valueChanged(int value)
{
    m_CanHandler -> setPortRPM(value);
}


void MainWindow::on_voltagePort_valueChanged(int value)
{
    m_CanHandler -> setPortVoltage(value);



    int power = (value/10) * ((ui -> currentPort -> value()) / 10);
    ui -> calculatedPower -> setText(QString::number(power));
}


void MainWindow::on_currentPort_valueChanged(int value)
{

    qDebug()<<"Raw from slider: "<<value;
    int16_t temp = static_cast<int16_t>(value);
    m_CanHandler -> setPortCurrent(temp);

    qDebug()<<"After cast: "<<temp;
    qDebug()<<"Number written in hex after casting to int16_t: "<<QString::asprintf("%x", temp & 0xffff);
    qDebug()<<"Number before casting in hex: "<<QString::asprintf("%x", value & 0xffff);


    int power = (value/10) * ((ui -> voltagePort -> value()) / 10);
    ui -> calculatedPower -> setText(QString::number(power));


}


void MainWindow::on_rpmStarboardSlider_valueChanged(int value)
{

    m_CanHandler -> setStbRPM(value);

}


void MainWindow::on_rpmStarboardVoltage_valueChanged(int value)
{

    m_CanHandler -> setStbVoltage(value);

    int power = (value/10) * (ui -> CurrentStarboardSlider -> value() / 10);
    ui -> calculatedPowerStb -> setText(QString::number(power));

}


void MainWindow::on_CurrentStarboardSlider_valueChanged(int value)
{

    m_CanHandler -> setStbCurrent(static_cast<int16_t>(value));

    int power = (value/10) * (ui -> rpmStarboardVoltage -> value() / 10);
    ui -> calculatedPowerStb -> setText(QString::number(power));

}


void MainWindow::on_speedSlider_valueChanged(int value)
{
    m_CanHandler -> setSpeed(value);
}


void MainWindow::on_speedSlider_2_valueChanged(int value)
{

    m_CanHandler -> setDistToEmpty(value);

}


void MainWindow::on_speedSlider_3_windowIconTextChanged(const QString &iconText)
{

}


void MainWindow::on_speedSlider_3_valueChanged(int value)
{

    m_CanHandler -> setTimeToEmpty(value);

}


void MainWindow::on_speedSlider_5_valueChanged(int value)
{

    m_CanHandler -> setStbMotorTemp(value);

}


void MainWindow::on_speedSlider_8_valueChanged(int value)
{

    m_CanHandler -> setStbInverterTemp(value);

}


void MainWindow::on_speedSlider_6_valueChanged(int value)
{
    m_CanHandler -> setHiCellTemp(value);
}


void MainWindow::on_speedSlider_12_valueChanged(int value)
{

    m_CanHandler -> setLoCellTemp(value);

}


void MainWindow::on_speedSlider_7_valueChanged(int value)
{

    m_CanHandler -> setSOC(value);

}


void MainWindow::on_speedSlider_18_valueChanged(int value)
{

    m_CanHandler -> setTimeToFull((int16_t)value);

}


void MainWindow::on_speedSlider_4_valueChanged(int value)
{

    m_CanHandler -> setPortMotorTemp(value);

}


void MainWindow::on_speedSlider_9_valueChanged(int value)
{

    m_CanHandler -> setPortInverterTemp(value);

}


void MainWindow::on_speedSlider_10_valueChanged(int value)
{

    m_CanHandler -> setBatVoltage(value);

}


void MainWindow::on_speedSlider_11_valueChanged(int value)
{

    m_CanHandler -> setBatCurrent((int16_t)value);

}


void MainWindow::on_speedSlider_19_valueChanged(int value)
{

    m_CanHandler -> setDepth(static_cast<uint32_t>(value));

}


void MainWindow::on_speedSlider_13_valueChanged(int value)
{

    int64_t fullValue = static_cast<int64_t>(value*10e11);

    m_CanHandler -> setLat(fullValue);

}


void MainWindow::on_speedSlider_14_valueChanged(int value)
{

    int64_t fullValue = static_cast<int64_t>(value*10e11);

    m_CanHandler -> setLon(fullValue);

}


void MainWindow::on_speedSlider_15_sliderMoved(int position)
{

}


void MainWindow::on_speedSlider_16_valueChanged(int value)
{
    m_CanHandler -> setHiVoltage(value);
}


void MainWindow::on_speedSlider_17_valueChanged(int value)
{

    m_CanHandler -> setLoVoltage(value);

}


void MainWindow::on_rpmStarboardVoltage_2_valueChanged(int value)
{
    m_CanHandler -> setChargerVoltage(value);
}


void MainWindow::on_CurrentStarboardSlider_2_valueChanged(int value)
{

    m_CanHandler -> setChargerCurrent(value);

}


void MainWindow::on_rpmStarboardSlider_3_valueChanged(int value)
{

    m_CanHandler -> setCharger2VoltageL1((uint16_t)value);

}


void MainWindow::on_rpmStarboardVoltage_3_valueChanged(int value)
{

    m_CanHandler -> setCharger2VoltageL2((uint16_t)value);

}


void MainWindow::on_CurrentStarboardSlider_3_valueChanged(int value)
{
    m_CanHandler -> setCharger2VoltageL3((uint16_t)value);
}


void MainWindow::on_CurrentStarboardSlider_4_valueChanged(int value)
{
    m_CanHandler -> setCharger2Temperature1((uint8_t)value);
}


void MainWindow::on_rpmStarboardSlider_4_valueChanged(int value)
{
    m_CanHandler -> setCharger3CurrentL1((int16_t)value);
}


void MainWindow::on_rpmStarboardVoltage_4_valueChanged(int value)
{
     m_CanHandler -> setCharger3CurrentL2((int16_t)value);
}


void MainWindow::on_CurrentStarboardSlider_5_valueChanged(int value)
{
    m_CanHandler -> setCharger3CurrentL3((int16_t)value);
}


void MainWindow::on_speedSlider_20_valueChanged(int value)
{
    m_CanHandler -> setDCDCVoltage(static_cast<uint16_t>(value));
}


void MainWindow::on_speedSlider_21_valueChanged(int value)
{
    m_CanHandler -> setDCDCCurrent(static_cast<int16_t>(value));
}


void MainWindow::on_pushButton_32_clicked()
{



}


void MainWindow::on_pushButton_33_clicked()//send trip button
{

    uint16_t time = ui -> textEdit_8 -> toPlainText().toInt();
    uint16_t distance = (ui -> textEdit_9 -> toPlainText().toInt())*10;
    uint16_t power = (ui -> textEdit_7 -> toPlainText().toInt())*10;
    bool isSinceClear = ui -> checkBox -> isChecked();
    bool isTotalClear = ui -> checkBox_2 -> isChecked();
    m_CanHandler -> sendTripMessage(time, distance, power, isSinceClear, isTotalClear);

}


void MainWindow::on_radioButton_19_clicked()
{

    m_CanHandler -> setVCUStatus(5);

}


void MainWindow::on_radioButton_21_clicked()
{

    m_CanHandler -> setVCUDriveStatus(0);

}


void MainWindow::on_radioButton_20_clicked()
{

    m_CanHandler -> setVCUDriveStatus(1);

}


void MainWindow::on_radioButton_22_clicked()
{

    m_CanHandler -> setVCUStatus(0);

}


void MainWindow::on_radioButton_23_clicked()
{
    m_CanHandler -> setVCUStatus(2);
}


void MainWindow::on_pushButton_34_clicked()
{

    m_CanHandler -> toggleSendingThrottle1Status();

    if(areWeSendingThrottle1Status){
        areWeSendingThrottle1Status = false;
        ui -> stbStatus_6 -> setText("Not sending");
        ui -> stbStatus_6 -> setStyleSheet("QLabel { background-color: red; }");

    }else{
        areWeSendingThrottle1Status = true;
        ui -> stbStatus_6 -> setText("Sending messages");
        ui -> stbStatus_6 -> setStyleSheet("QLabel { background-color: green; }");

    }



}


void MainWindow::on_radioButton_24_clicked()
{

    m_CanHandler -> setThrottle1Status(1);

}


void MainWindow::on_radioButton_25_clicked()
{

    m_CanHandler -> setThrottle1Status(2);

}


void MainWindow::on_pushButton_35_clicked()
{

    m_CanHandler -> toggleSendingThrottle2Status();

    if(areWeSendingThrottle2Status){
        areWeSendingThrottle2Status = false;
        ui -> stbStatus_7 -> setText("Not sending");
        ui -> stbStatus_7 -> setStyleSheet("QLabel { background-color: red; }");

    }else{
        areWeSendingThrottle2Status = true;
        ui -> stbStatus_7 -> setText("Sending messages");
        ui -> stbStatus_7 -> setStyleSheet("QLabel { background-color: green; }");

    }

}


void MainWindow::on_radioButton_26_clicked()
{

    m_CanHandler -> setThrottle2Status(1);

}


void MainWindow::on_radioButton_27_clicked()
{

    m_CanHandler -> setThrottle2Status(2);

}


void MainWindow::on_checkBox_3_stateChanged(int arg1)
{

    m_CanHandler -> setBatteryInternalPump(arg1);

}


void MainWindow::on_checkBox_4_stateChanged(int arg1)
{

    m_CanHandler -> setBatteryExternalPump(arg1);

}

void MainWindow::on_checkBox_5_stateChanged(int arg1)
{

    m_CanHandler -> setCoolingValve(arg1);

}


void MainWindow::on_checkBox_6_stateChanged(int arg1)
{

    m_CanHandler -> setHeatingValve(arg1);

}



void MainWindow::on_checkBox_7_stateChanged(int arg1)
{

    m_CanHandler -> setHeater(arg1);

}


void MainWindow::on_checkBox_8_stateChanged(int arg1)
{

    m_CanHandler -> setHeatExchange(arg1);

}


void MainWindow::on_checkBox_4_clicked()
{

}


void MainWindow::on_checkBox_9_stateChanged(int arg1)
{

    m_CanHandler -> setMotorInternalPump(arg1);

}


void MainWindow::on_checkBox_10_stateChanged(int arg1)
{

    m_CanHandler -> setMotorExternalPump(arg1);

}


void MainWindow::on_pushButton_36_clicked()
{

    m_CanHandler -> sendVCUCommisionResponse();

}


void MainWindow::on_radioButton_28_clicked()
{

    m_CanHandler -> setVCUStatus(6);

}


void MainWindow::on_speedSlider_24_valueChanged(int value)
{

    m_CanHandler -> setPortCoolantTemp(value);//set m_PortMotorCoolantTemperature

}


void MainWindow::on_rpmStarboardVoltage_actionTriggered(int action)
{

}


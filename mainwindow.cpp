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
    ui -> label_67 -> setText(QString::number(0) + " RPM");
    ui -> label_68 -> setText(QString::number(0) + " RPM");

    ui -> radioButton -> setChecked(true);
}

MainWindow::~MainWindow()
{
    delete m_CanHandler;
    delete ui;
}

void MainWindow::on_rpmPortSlider_sliderMoved(int position)
{

    m_CanHandler -> setPortRPM(position);

}




void MainWindow::on_voltagePort_sliderMoved(int position)
{

    m_CanHandler -> setPortVoltage(position);



    int power = (position/10) * ((ui -> currentPort -> value()) / 10);
    ui -> calculatedPower -> setText(QString::number(power));

}


void MainWindow::on_currentPort_sliderMoved(int position)
{

    qDebug()<<"Raw from slider: "<<position;
    int16_t temp = static_cast<int16_t>(position);
    m_CanHandler -> setPortCurrent(temp);

    qDebug()<<"After cast: "<<temp;
    qDebug()<<"Number written in hex after casting to int16_t: "<<QString::asprintf("%x", temp & 0xffff);
    qDebug()<<"Number before casting in hex: "<<QString::asprintf("%x", position & 0xffff);


    int power = (position/10) * ((ui -> voltagePort -> value()) / 10);
    ui -> calculatedPower -> setText(QString::number(power));


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

    int power = (position/10) * ((ui -> CurrentStarboardSlider -> value()) / 10);
    ui -> calculatedPowerStb -> setText(QString::number(power));

}


void MainWindow::on_CurrentStarboardSlider_sliderMoved(int position)
{

    m_CanHandler -> setStbCurrent(static_cast<int16_t>(position));

    int power = (position/10) * ((ui -> CurrentStarboardSlider -> value()) / 10);
    ui -> calculatedPowerStb -> setText(QString::number(power));

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

    int64_t fullValue = static_cast<int64_t>(position*10e11);

    m_CanHandler -> setLat(fullValue);

}


void MainWindow::on_speedSlider_14_sliderMoved(int position)
{
    int64_t fullValue = static_cast<int64_t>(position*10e11);

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
    m_CanHandler -> setChargerVoltage(position);
}


void MainWindow::on_CurrentStarboardSlider_2_sliderMoved(int position)
{
    m_CanHandler -> setChargerCurrent(position);
}


void MainWindow::on_speedSlider_18_sliderMoved(int position)
{
    m_CanHandler -> setTimeToFull((int16_t)position);
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

    //int tempNumber = ui -> textEdit_2 -> toPlainText().toInt();

    //tempNumber++;

    //ui -> textEdit_2 -> setText(QString::number(tempNumber));

    //ui -> textEdit_3 -> setText("BMS" + QString::number(tempNumber));



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

    m_CanHandler -> setDepth(static_cast<uint32_t>(position));

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

    m_CanHandler -> setDCDCVoltage(static_cast<uint16_t>(position));

}


void MainWindow::on_speedSlider_21_sliderMoved(int position)
{

    m_CanHandler -> setDCDCCurrent(static_cast<int16_t>(position));

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

    m_CanHandler -> setVCUStatus(0);

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

    m_CanHandler -> setCharger2VoltageL1((uint16_t)position);

}


void MainWindow::on_rpmStarboardVoltage_3_sliderMoved(int position)
{

    m_CanHandler -> setCharger2VoltageL2((uint16_t)position);

}


void MainWindow::on_CurrentStarboardSlider_3_sliderMoved(int position)
{

    m_CanHandler -> setCharger2VoltageL3((uint16_t)position);

}


void MainWindow::on_CurrentStarboardSlider_4_sliderMoved(int position)
{

    m_CanHandler -> setCharger2Temperature1((uint8_t)position);

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

    m_CanHandler -> setCharger3CurrentL1((int16_t)position);

}


void MainWindow::on_rpmStarboardVoltage_4_sliderMoved(int position)
{

    m_CanHandler -> setCharger3CurrentL2((int16_t)position);

}


void MainWindow::on_CurrentStarboardSlider_5_sliderMoved(int position)
{

    m_CanHandler -> setCharger3CurrentL3((int16_t)position);

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


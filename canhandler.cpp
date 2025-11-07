#include "canhandler.h"
#include <QDebug>

CanHandler::CanHandler(QObject *parent)
    : QObject{parent}
{
    //canDevice -> disconnectDevice();
    this -> startCAN();


    m_PortRPMbytes.resize(2);
    m_PortRPMbytes[0] = 0x00;
    m_PortRPMbytes[1] = 0x00;

    m_PortVoltagebytes.resize(2);
    m_PortVoltagebytes[0] = 0x00;
    m_PortVoltagebytes[1] = 0x00;

    m_PortCurrentbytes.resize(2);
    m_PortCurrentbytes[0] = 0x00;
    m_PortCurrentbytes[0] = 0x00;


    m_StbRPMbytes.resize(2);
    m_StbRPMbytes[0] = 0x00;
    m_StbRPMbytes[1] = 0x00;

    m_StbVoltagebytes.resize(2);
    m_StbVoltagebytes[0] = 0x00;
    m_StbVoltagebytes[1] = 0x00;

    m_StbCurrentbytes.resize(2);
    m_StbCurrentbytes[0] = 0x00;
    m_StbCurrentbytes[1] = 0x00;

    m_Speed.resize(2);
    m_Speed[0] = 0x00;
    m_Speed[1] = 0x00;

    m_TimeToEmpty.resize(4);
    m_TimeToEmpty[0] = 0x00;
    m_TimeToEmpty[1] = 0x00;
    m_TimeToEmpty[2] = 0x00;
    m_TimeToEmpty[3] = 0x00;

    m_DistToEmpty.resize(4);
    m_DistToEmpty[0] = 0x00;
    m_DistToEmpty[1] = 0x00;
    m_DistToEmpty[2] = 0x00;
    m_DistToEmpty[3] = 0x00;

    m_StbMotorTemp.resize(2);
    m_StbMotorTemp[0] = 0x00;
    m_StbMotorTemp[1] = 0x00;

    m_StbInverterTemp.resize(2);
    m_StbInverterTemp[0] = 0x00;
    m_StbInverterTemp[1] = 0x00;

    m_PortMotorTemp.resize(2);
    m_PortMotorTemp[0] = 0x00;
    m_PortMotorTemp[1] = 0x00;

    m_PortInverterTemp.resize(2);
    m_PortInverterTemp[0] = 0x00;
    m_PortInverterTemp[1] = 0x00;

    m_HiCellTemp.resize(2);
    m_HiCellTemp[0] = 0x00;
    m_HiCellTemp[1] = 0x00;

    m_SOC.resize(1);
    m_SOC[0] = 0x00;

    m_BatVoltage.resize(2);
    m_BatVoltage[0] = 0x00;
    m_BatVoltage[1] = 0x00;

    m_BatCurrent.resize(2);
    m_BatCurrent[0] = 0x00;
    m_BatCurrent[1] = 0x00;

    m_LoCellTemp.resize(2);
    m_LoCellTemp[0] = 0x00;
    m_LoCellTemp[1] = 0x00;

    m_Lat.resize(8);
    m_Lat[0] = 0x00;
    m_Lat[1] = 0x00;
    m_Lat[2] = 0x00;
    m_Lat[3] = 0x00;
    m_Lat[4] = 0x00;
    m_Lat[5] = 0x00;
    m_Lat[6] = 0x00;
    m_Lat[7] = 0x00;

    m_Lon.resize(8);
    m_Lon[0] = 0x00;
    m_Lon[1] = 0x00;
    m_Lon[2] = 0x00;
    m_Lon[3] = 0x00;
    m_Lon[4] = 0x00;
    m_Lon[5] = 0x00;
    m_Lon[6] = 0x00;
    m_Lon[7] = 0x00;

    m_HiCellVoltage.resize(2);
    m_HiCellVoltage[0] = 0x00;
    m_HiCellVoltage[1] = 0x00;

    m_LoCellVoltage.resize(2);
    m_LoCellVoltage[0] = 0x00;
    m_LoCellVoltage[1] = 0x00;

    m_BMSStatus.resize(1);
    m_BMSStatus[0] = 0x00;

    m_ChargerTemp.resize(2);
    m_ChargerTemp[0] = 0x00;
    m_ChargerTemp[1] = 0x00;

    m_ChargerVoltage.resize(2);
    m_ChargerVoltage[0] = 0x00;
    m_ChargerVoltage[1] = 0x00;

    m_ChargerCurrent.resize(2);
    m_ChargerCurrent[0] = 0x00;
    m_ChargerCurrent[1] = 0x00;

    m_ChargerStatus.resize(1);
    m_ChargerStatus[0] = 0x00;

    m_TimeToFull.resize(2);
    m_TimeToFull[0] = 0x00;
    m_TimeToFull[1] = 0x00;

    m_Depth.resize(4);
    m_Depth[0] = 0x00;
    m_Depth[1] = 0x00;
    m_Depth[2] = 0x00;
    m_Depth[3] = 0x00;

    m_DCDCStatus.resize(1);
    m_DCDCStatus[0] = 0x00;

    m_DCDCVoltage.resize(2);
    m_DCDCVoltage[0] = 0x00;
    m_DCDCVoltage[1] = 0x00;

    m_DCDCCurrent.resize(2);
    m_DCDCCurrent[0] = 0x00;
    m_DCDCCurrent[1] = 0x00;

    m_VCUStatus.resize(1);
    m_VCUStatus[0] = 0x00;

    m_VCUDriveStatus.resize(1);
    m_VCUDriveStatus[0] = 0x00;

    m_ChargerInputVoltageL1.resize(2);
    m_ChargerInputVoltageL1[0] = 0x00;
    m_ChargerInputVoltageL1[1] = 0x00;

    m_ChargerInputVoltageL2.resize(2);
    m_ChargerInputVoltageL2[0] = 0x00;
    m_ChargerInputVoltageL2[1] = 0x00;

    m_ChargerInputVoltageL3.resize(2);
    m_ChargerInputVoltageL3[0] = 0x00;
    m_ChargerInputVoltageL3[1] = 0x00;

    m_ChargerTemperature1.resize(1);
    m_ChargerTemperature1[0] = 0x00;

    m_ChargerInputCurrentL1.resize(2);
    m_ChargerInputCurrentL1[0] = 0x00;
    m_ChargerInputCurrentL1[1] = 0x00;

    m_ChargerInputCurrentL2.resize(2);
    m_ChargerInputCurrentL2[0] = 0x00;
    m_ChargerInputCurrentL2[1] = 0x00;

    m_ChargerInputCurrentL3.resize(2);
    m_ChargerInputCurrentL3[0] = 0x00;
    m_ChargerInputCurrentL3[1] = 0x00;

    m_PortMotorStatus.resize(1);
    m_PortMotorStatus[0] = 0x00;

    m_Throttle1Status.resize(1);
    m_Throttle1Status[0] = 0x00;

    m_Throttle2Status.resize(1);
    m_Throttle2Status[0] = 0x00;

    m_PortCoolantTemperature.resize(2);
    m_PortCoolantTemperature[0] = 0x00;
    m_PortCoolantTemperature[1] = 0x00;

    m_RudderAngle.resize(2);
    m_RudderAngle[0] = 0x00;
    m_RudderAngle[1] = 0x00;

    m_WaterTemp.resize(3);
    m_WaterTemp[0] = 0x00;
    m_WaterTemp[1] = 0x00;
    m_WaterTemp[2] = 0x00;

    QTimer *timer  = new QTimer(this);
    connect(timer, &QTimer::timeout,this, &CanHandler::sendPortRPMPackage);
    timer->start(500);//default: 500

    QTimer *timer2 = new QTimer(this);
    connect(timer2, &QTimer::timeout, this, &CanHandler::sendStbRPMPackage);
    timer2->start(500);//default: 500

    QTimer *timer3 = new QTimer(this);
    connect(timer3, &QTimer::timeout, this, &CanHandler::sendSpeedPackage);
    timer3->start(250); //default: 250

    QTimer *timer4 = new QTimer(this);
    connect(timer4, &QTimer::timeout, this, &CanHandler::sendTripPackage);
    timer4->start(1000);

    QTimer *timer5 = new QTimer(this);
    connect(timer5, &QTimer::timeout, this, &CanHandler::sendPortMotorTempPackage);
    timer5->start(1500);

    QTimer *timer6 = new QTimer(this);
    connect(timer6, &QTimer::timeout, this, &CanHandler::sendStbMotorTempPackage);
    timer6->start(1500);

    QTimer *timer7 = new QTimer(this);
    connect(timer7, &QTimer::timeout, this, &CanHandler::sendHiCellPackage);
    timer7->start(1500);

    QTimer *timer8 = new QTimer(this);
    connect(timer8, &QTimer::timeout, this, &CanHandler::sendBatInfoPackage);
    timer8->start(500);

    QTimer *timer9 = new QTimer(this);
    connect(timer9, &QTimer::timeout, this, &CanHandler::sendPositionPackage);
    timer9->start(1000);

    QTimer *timer10 = new QTimer(this);
    connect(timer10, &QTimer::timeout, this, &CanHandler::sendCellVoltage);
    timer10->start(500);

    QTimer *timer11 = new QTimer(this);
    connect(timer11, &QTimer::timeout, this, &CanHandler::sendChargerInfo);
    timer11->start(100);

    QTimer *timer12 = new QTimer(this);
    connect(timer12, &QTimer::timeout, this, &CanHandler::sendDepthPositionPackage);
    timer12->start(500);

    QTimer *timer13 = new QTimer(this);
    connect(timer13, &QTimer::timeout, this, &CanHandler::sendDCDCInfoPackage);
    timer13 -> start(500);

    QTimer *timer14 = new QTimer(this);
    connect(timer14, &QTimer::timeout, this, &CanHandler::sendVCUPackage);
    timer14 -> start(1000);

    QTimer *timer15 = new QTimer(this);
    connect(timer15, &QTimer::timeout, this, &CanHandler::sendChargerInfo2);
    timer15 -> start(500);

    QTimer *timer16 = new QTimer(this);
    connect(timer16, &QTimer::timeout, this, &CanHandler::sendChargerInfo3);
    timer16 -> start(500);

    QTimer *timer17 = new QTimer(this);
    connect(timer17, &QTimer::timeout, this, &CanHandler::sendPortMotorInfo);
    timer17 -> start(500);

    QTimer *timer18 = new QTimer(this);
    connect(timer18, &QTimer::timeout, this, &CanHandler::sendThrottle1Status);
    timer18 -> start(500);

    QTimer *timer19 = new QTimer(this);
    connect(timer19, &QTimer::timeout, this, &CanHandler::sendThrottle2Status);
    timer19 -> start(500);

    QTimer *timer20 = new QTimer(this);
    connect(timer20, &QTimer::timeout, this, &CanHandler::sendRudderAngle);
    timer20 -> start(100);

    QTimer *timer21 = new QTimer(this);
    connect(timer21, &QTimer::timeout, this, &CanHandler::sendConsumption);
    timer21 -> start(500);

    QTimer *timer22 = new QTimer(this);
    connect(timer22, &QTimer::timeout, this, &CanHandler::sendWaterTemp);
    timer22 -> start(2000);

}

CanHandler::~CanHandler()
{
    qDebug()<<"Closing connections";
    canDevice -> disconnectDevice();
    delete canDevice;

}

void CanHandler::startCAN(){

    //clx000can

    // QList<QCanBusDeviceInfo> result;

    // static QString const description("CLX000");

    //ssh with rasp solution?

    // Find all available USB-CDC devices.
    // auto allAvailablePorts = QSerialPortInfo::availablePorts();

    // for(auto const& portInfo: allAvailablePorts) {
    //     // Remove all non-CDC ports.
    //     if(!portInfo.hasVendorIdentifier() || !portInfo.hasProductIdentifier()) {
    //         continue;
    //     }

    //     // Take only devices matching the USB identifier of the CLX000 CDC mode.
    //     if( (portInfo.vendorIdentifier() != quint16(0x1CBEu)) ||
    //         (portInfo.productIdentifier() != quint16(0x021Au)) ) {
    //         continue;
    //     }


    //     qDebug() << "CLX000CanBus - found device" << portInfo.portName() << portInfo.serialNumber();

    // }

    //QSerialPort port("COM9");
    port = new QSerialPort("COM4");
    // port->setBaudRate(QSerialPort::Baud115200);
    // port->setDataBits(QSerialPort::Data8);
    //port->setStopBits(QSerialPort::OneStop);
    //port->setFlowControl(QSerialPort::NoFlowControl);
    // port->setReadBufferSize(1024*1024*10);

    // port->setBaudRate(QSerialPort::Baud115200);
    // port->setDataBits(QSerialPort::Data8);
    //port->setStopBits(QSerialPort::OneStop);
    //port->setFlowControl(QSerialPort::NoFlowControl);
    // port->setReadBufferSize(1024*1024*10);


    if(!port->open(QSerialPort::OpenModeFlag::ReadWrite)){
        qDebug() << "Failed to open port" << port->portName() << ", error:" << port->errorString();

    }




    //connect(port,SIGNAL(readyRead()), this, SLOT(testingData));

    // QCanBusFrame frame1;
    // frame1.setFrameId(0x1DF20300);
    // QByteArray payload1;
    // payload1.resize(8);

    // payload1[0] = 0x12;
    // payload1[1] = 0x0f;
    // payload1[2] = 0x00;
    // payload1[3] = 0x34;
    // payload1[4] = 0x00;
    // payload1[5] = 0x00;
    // payload1[6] = 0x56;
    // payload1[7] = 0x78;
    // frame1.setPayload(payload1);

    // for(int i=0;i<5;i++){
    //     qDebug()<<"Writting package number: " << i;
    //     sendToCL2000(frame1);}

    // QByteArray test;



    // test.resize(24);
    // test[0] = 0x7e;
    // test[1] = 0x01;
    // test[2] = 0x66;
    // test[3] = 0x8d;
    // test[4] = 0x05;
    // test[5] = 0x7a;
    // test[6] = 0x03;
    // test[7] = 0x22;
    // test[8] = 0x29;
    // test[9] = 0xf5; //7e 01 66 8d 05 7a 03 22 29 f5 03 00 08 01 fc ff ff 00 00 ff ff 6f f8 7e
    // test[10] = 0x03;
    // test[11] = 0x00;
    // test[12] = 0x08;
    // test[13] = 0x01;
    // test[14] = 0xfc;
    // test[15] = 0xff;
    // test[16] = 0xff;
    // test[17] = 0x00;
    // test[18] = 0x00;
    // test[19] = 0xff;
    // test[20] = 0xff;
    // test[21] = 0x6f;
    // test[22] = 0xf8;
    // test[23] = 0x7e;

    // port->write(test);


    qDebug() << "Written something to serial, lets try";
    //Above we experiment with cl2000
    const QString pluginName = "virtualcan"; //clx000can

    canDevice = QCanBus::instance()->createDevice(pluginName, "can0");
    if (canDevice && canDevice->connectDevice()) {
        qDebug() << "Connected to CAN bus";
        connect(canDevice, &QCanBusDevice::framesReceived, this, &CanHandler::readAndProcessCANpodatke);
    } else {
        qDebug() << "Failed to connect to CAN bus";
    }

}


void CanHandler::readAndProcessCANpodatke()
{
    while (canDevice->framesAvailable()) {
        const QCanBusFrame frame = canDevice->readFrame();
        qDebug() << "Received a CAN package";
        qDebug() << "FRAME ID";
        qDebug() << frame.frameId();
        qDebug() << "FRAME ID_OVER";
        qDebug() << "Received a CAN package";

    }
}

void CanHandler::sendChargerInfo()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18FF9149);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00; //node id
    payload[1]=m_ChargerStatus[0]; //here we set status of Charger
    payload[2]=m_ChargerVoltage[0];
    payload[3]=m_ChargerVoltage[1];
    payload[4]=m_ChargerCurrent[0];
    payload[5]=m_ChargerCurrent[1];
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    if(areWeSendingChargerInfo){
        canDevice -> writeFrame(frame);
        sendToCL2000(frame);
    }

}

void CanHandler::sendCellVoltage()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18FF95F3);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=m_HiCellVoltage[0];
    payload[2]=m_HiCellVoltage[1];
    payload[3]=m_LoCellVoltage[0];
    payload[4]=m_LoCellVoltage[1];
    payload[5]=m_BMSStatus[0]; //This is going to be status
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    if(areWeSendingCellVoltage){
        canDevice -> writeFrame(frame);
        sendToCL2000(frame);
    }

}

void CanHandler::sendHiCellPackage()
{

    QCanBusFrame frame1;
    frame1.setFrameId(0x1DF20300);
    QByteArray payload1;
    payload1.resize(8);

    payload1[0] = (uint8_t)(tripPackageCounter3 | 0x00);
    payload1[1] = 0x0f;
    payload1[2] = 0x00;//0x41 is node id we tried for NT
    payload1[3] = m_SOC[0];
    payload1[4] = m_TimeToFull[0];
    payload1[5] = m_TimeToFull[1];
    payload1[6] = m_HiCellTemp[0];
    payload1[7] = m_HiCellTemp[1];
    frame1.setPayload(payload1);

    QCanBusFrame frame2;
    frame2.setFrameId(0x1DF20300);
    QByteArray payload2;
    payload2.resize(8);
    payload2[0] = (uint8_t)(tripPackageCounter3 | 0x01);
    payload2[1] = m_LoCellTemp[0];
    payload2[2] = m_LoCellTemp[1];
    payload2[3] = 0x00;
    payload2[4] = 0x00;
    payload2[5] = 0x00;
    payload2[6] = 0x00;
    payload2[7] = 0x00;
    frame2.setPayload(payload2);

    QCanBusFrame frame3;
    frame3.setFrameId(0x1DF20300);
    QByteArray payload3;
    payload3.resize(8);
    payload3[0] = (uint8_t)(tripPackageCounter3 | 0x02);
    payload3[1] = 0x00;
    payload3[2] = 0x00;
    payload3[3] = 0x00;
    payload3[4] = 0x00;
    payload3[5] = 0x00;
    payload3[6] = 0x00;
    payload3[7] = 0x00;
    frame3.setPayload(payload3);

    if(areWeSendingHiCellTemp){
        canDevice -> writeFrame(frame1);
        canDevice -> writeFrame(frame2);
        canDevice -> writeFrame(frame3);

        sendToCL2000(frame1);
        sendToCL2000(frame2);
        sendToCL2000(frame3);
        if(tripPackageCounter3 != 240){
            tripPackageCounter3+=0x20; //but we want it in hex 0x00 0x20 0x40 0x60 0x80 ..
        }else{
            tripPackageCounter3=0x00;
        }
    }

}

void CanHandler::sendPortRPMPackage(){

    QCanBusFrame frame;
    frame.setFrameId(0x15F40200);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=0xff;
    payload[2]=m_PortRPMbytes[0];
    payload[3]=m_PortRPMbytes[1];
    payload[4]=m_PortVoltagebytes[0];
    payload[5]=m_PortVoltagebytes[1];
    payload[6]=m_PortCurrentbytes[0];
    payload[7]=m_PortCurrentbytes[1];
    frame.setPayload(payload);

    if(areWeSendingPortMsg){
        canDevice -> writeFrame(frame);
        sendToCL2000(frame);
    }

    //here we will add Current and Voltage from slider
}

void CanHandler::sendStbRPMPackage()
{


    QCanBusFrame frame;
    frame.setFrameId(0x15F40200);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x01;
    payload[1]=0xff;
    payload[2]=m_StbRPMbytes[0];
    payload[3]=m_StbRPMbytes[1];
    payload[4]=m_StbVoltagebytes[0];
    payload[5]=m_StbVoltagebytes[1];
    payload[6]=m_StbCurrentbytes[0];
    payload[7]=m_StbCurrentbytes[1];
    frame.setPayload(payload);

    if(areWeSendingStbMsg){
        canDevice -> writeFrame(frame);
        sendToCL2000(frame);    }

}

void CanHandler::sendSpeedPackage()
{


    QCanBusFrame frame;
    frame.setFrameId(0x09F80200);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0xff;
    payload[1]=0xff;
    payload[2]=0xff;
    payload[3]=0xff;
    payload[4]=m_Speed[0];
    payload[5]=m_Speed[1];
    payload[6]=0xff;
    payload[7]=0xff;
    frame.setPayload(payload);

    if(areWeSendingSpeedMsg){
        canDevice -> writeFrame(frame);
        sendToCL2000(frame);
    }
}

void CanHandler::sendTripPackage()
{

    QCanBusFrame frame1;
    frame1.setFrameId(0x15F20800);
    QByteArray payload1;
    payload1.resize(8);

    payload1[0] = (uint8_t)(tripPackageCounter | 0x00);
    payload1[1] = 0x0e;
    payload1[2] = m_TimeToEmpty[0];
    payload1[3] = m_TimeToEmpty[1];
    payload1[4] = m_TimeToEmpty[2];
    payload1[5] = m_TimeToEmpty[3];
    payload1[6] = m_DistToEmpty[0];
    payload1[7] = m_DistToEmpty[1];
    frame1.setPayload(payload1);

    QCanBusFrame frame2;
    frame2.setFrameId(0x15F20800);
    QByteArray payload2;
    payload2.resize(8);
    payload2[0] = (uint8_t)(tripPackageCounter | 0x01);
    payload2[1] = m_DistToEmpty[2];
    payload2[2] = m_DistToEmpty[3];
    payload2[3] = 0x00;
    payload2[4] = 0x00;
    payload2[5] = 0x00;
    payload2[6] = 0x00;
    payload2[7] = 0x00;
    frame2.setPayload(payload2);

    QCanBusFrame frame3;
    frame3.setFrameId(0x15F20800);
    QByteArray payload3;
    payload3.resize(8);
    payload3[0] = (uint8_t)(tripPackageCounter | 0x02);
    payload3[1] = 0x00;
    payload3[2] = 0x00;
    payload3[3] = 0x00;
    payload3[4] = 0x00;
    payload3[5] = 0x00;
    payload3[6] = 0x00;
    payload3[7] = 0x00;
    frame3.setPayload(payload3);

    if(areWeSendingTripMsg){
        canDevice -> writeFrame(frame1);
        canDevice -> writeFrame(frame2);
        canDevice -> writeFrame(frame3);

        sendToCL2000(frame1);
        sendToCL2000(frame2);
        sendToCL2000(frame3);
        if(tripPackageCounter != 240){
            tripPackageCounter+=0x20; //but we want it in hex 0x00 0x20 0x40 0x60 0x80 ..
        }else{
            tripPackageCounter=0x00;
        }
    }
}

void CanHandler::sendPortMotorTempPackage()
{

    QCanBusFrame frame1;
    frame1.setFrameId(0x5f20200);
    QByteArray payload1;
    payload1.resize(8);

    payload1[0] = (uint8_t)(tripPackageCounter2 | 0x00);
    payload1[1] = 0x0b;
    payload1[2] = 0x00;
    payload1[3] = 0x00;
    payload1[4] = m_PortMotorTemp[0];
    payload1[5] = m_PortMotorTemp[1];
    payload1[6] = m_PortInverterTemp[0];
    payload1[7] = m_PortInverterTemp[1];
    frame1.setPayload(payload1);

    QCanBusFrame frame2;
    frame2.setFrameId(0x5f20200);
    QByteArray payload2;
    payload2.resize(8);
    payload2[0] = (uint8_t)(tripPackageCounter2 | 0x01);
    payload2[1] = m_PortCoolantTemperature[0];//Coolant temp byte 0
    payload2[2] = m_PortCoolantTemperature[1];//Coolant temp byte 1
    payload2[3] = 0x00;
    payload2[4] = 0x00;
    payload2[5] = 0x00;
    payload2[6] = 0x00;
    payload2[7] = 0x00;
    frame2.setPayload(payload2);

    if(areWeSendingPortMotorTemp){
        canDevice -> writeFrame(frame1);
        canDevice -> writeFrame(frame2);

        sendToCL2000(frame1);
        sendToCL2000(frame2);
        if(tripPackageCounter2 != 240){
            tripPackageCounter2+=0x20; //but we want it in hex 0x00 0x20 0x40 0x60 0x80 ..
        }else{
            tripPackageCounter2=0x00;
        }
    }


}

void CanHandler::sendStbMotorTempPackage()
{

    QCanBusFrame frame1;
    frame1.setFrameId(0x5f20200);
    QByteArray payload1;
    payload1.resize(8);

    payload1[0] = (uint8_t)(tripPackageCounter4 | 0x00);
    payload1[1] = 0x0b;
    payload1[2] = 0x01;
    payload1[3] = 0x00;
    payload1[4] = m_StbMotorTemp[0];
    payload1[5] = m_StbMotorTemp[1];
    payload1[6] = m_StbInverterTemp[0];
    payload1[7] = m_StbInverterTemp[1];
    frame1.setPayload(payload1);

    QCanBusFrame frame2;
    frame2.setFrameId(0x5f20200);
    QByteArray payload2;
    payload2.resize(8);
    payload2[0] = (uint8_t)(tripPackageCounter4 | 0x01);
    payload2[1] = 0x00;
    payload2[2] = 0x00;
    payload2[3] = 0x00;
    payload2[4] = 0x00;
    payload2[5] = 0x00;
    payload2[6] = 0x00;
    payload2[7] = 0x00;
    frame2.setPayload(payload2);

    if(areWeSendingStbMotorTemp){
        canDevice -> writeFrame(frame1);
        canDevice -> writeFrame(frame2);

        sendToCL2000(frame1);
        sendToCL2000(frame2);
        if(tripPackageCounter4 != 240){
            tripPackageCounter4+=0x20; //but we want it in hex 0x00 0x20 0x40 0x60 0x80 ..
        }else{
            tripPackageCounter4=0x00;
        }
    }


}

void CanHandler::sendBatInfoPackage()
{

    QCanBusFrame frame;
    frame.setFrameId(0x15F40300);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00; //Instance has to be 0
    payload[1]=0x00;
    payload[2]=m_BatVoltage[0];
    payload[3]=m_BatVoltage[1];
    payload[4]=m_BatCurrent[0];
    payload[5]=m_BatCurrent[1];
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    if(areWeSendingBatInfo){
        canDevice -> writeFrame(frame);
        sendToCL2000(frame);
    }

}

void CanHandler::sendPositionPackage()
{

    QCanBusFrame frame1;
    frame1.setFrameId(0x0DF80500); //Where did we get 0D prio from, maybe riverdi should just check PGNs
    //frame1.setFrameId(0x19F805FE);
    QByteArray payload1;
    payload1.resize(8);

    payload1[0] = (uint8_t)(tripPackageCounter5 | 0x00);
    payload1[1] = 0x00;//How many bytes we are sending
    payload1[2] = 0x00;
    payload1[3] = 0x26;//Date low byte
    payload1[4] = 0x4e;//Date high byte
    // payload1[3] = 0xb6; //date 400 days from up, replace to test maintenance marks as done and notifs
    // payload1[4] = 0x4f;
    payload1[5] = 0x00;//Position time byte1
    payload1[6] = 0xc2;//Position time byte2
    payload1[7] = 0xeb;//Position time byte3
    frame1.setPayload(payload1);

    QCanBusFrame frame2;
    frame2.setFrameId(0x0DF80500);
    //frame2.setFrameId(0x19F805FE);
    QByteArray payload2;
    payload2.resize(8);
    payload2[0] = (uint8_t)(tripPackageCounter5 | 0x01);
    payload2[1] = 0x0b;//Position time byte4
    payload2[2] = m_Lat[0];
    payload2[3] = m_Lat[1];
    payload2[4] = m_Lat[2];
    payload2[5] = m_Lat[3];
    payload2[6] = m_Lat[4];
    payload2[7] = m_Lat[5];
    frame2.setPayload(payload2);

    QCanBusFrame frame3;
    frame3.setFrameId(0x0DF80500);
    //frame3.setFrameId(0x19F805FE);
    QByteArray payload3;
    payload3.resize(8);
    payload3[0] = (uint8_t)(tripPackageCounter5 | 0x02);
    payload3[1] = m_Lat[6];
    payload3[2] = m_Lat[7];
    payload3[3] = m_Lon[0];
    payload3[4] = m_Lon[1];
    payload3[5] = m_Lon[2];
    payload3[6] = m_Lon[3];
    payload3[7] = m_Lon[4];
    frame3.setPayload(payload3);

    QCanBusFrame frame4;
    frame4.setFrameId(0x0DF80500);
    //frame4.setFrameId(0x19F805FE);
    QByteArray payload4;
    payload4.resize(8);
    payload4[0] = (uint8_t)(tripPackageCounter5 | 0x03);
    payload4[1] = m_Lon[5];
    payload4[2] = m_Lon[6];
    payload4[3] = m_Lon[7];
    payload4[4] = 0x00;
    payload4[5] = 0x00;
    payload4[6] = 0x00;
    payload4[7] = 0x00;
    frame4.setPayload(payload4);

    QCanBusFrame frame5;
    frame5.setFrameId(0x0DF80500);
    //frame5.setFrameId(0x19F805FE);
    QByteArray payload5;
    payload5.resize(8);
    payload5[0] = (uint8_t)(tripPackageCounter5 | 0x04);
    payload5[1] = 0x00;
    payload5[2] = 0x00;
    payload5[3] = 0x00;
    payload5[4] = 0x00;
    payload5[5] = 0x01; //GNSS fix
    payload5[6] = 0x7f;
    payload5[7] = 0x00;
    frame5.setPayload(payload5);

    QCanBusFrame frame6;
    frame6.setFrameId(0x0DF80500);
    //frame6.setFrameId(0x19F805FE);
    QByteArray payload6;
    payload6.resize(8);
    payload6[0] = (uint8_t)(tripPackageCounter5 | 0x05);
    payload6[1] = 0x00;
    payload6[2] = 0x00;
    payload6[3] = 0x00;
    payload6[4] = 0x00;
    payload6[5] = 0x00;
    payload6[6] = 0x00;
    payload6[7] = 0x00;
    frame6.setPayload(payload6);

    QCanBusFrame frame7;
    frame7.setFrameId(0x0DF80500);
    //frame7.setFrameId(0x19F805FE);
    QByteArray payload7;
    payload7.resize(8);
    payload7[0] = (uint8_t)(tripPackageCounter5 | 0x06);
    payload7[1] = 0x00;
    payload7[2] = 0x00;
    payload7[3] = 0x00;
    payload7[4] = 0x00;
    payload7[5] = 0x00;
    payload7[6] = 0x00;
    payload7[7] = 0x00;
    frame7.setPayload(payload7);

    QCanBusFrame frame8;
    frame8.setFrameId(0x0DF80500);
    //frame8.setFrameId(0x19F805FE);
    QByteArray payload8;
    payload8.resize(8);
    payload8[0] = (uint8_t)(tripPackageCounter5 | 0x07);
    payload8[1] = 0x00;
    payload8[2] = 0x00;
    payload8[3] = 0x00;
    payload8[4] = 0x00;
    payload8[5] = 0x00;
    payload8[6] = 0x00;
    payload8[7] = 0x00;
    frame8.setPayload(payload8);

    //Here we might have to add another package so that it is 7 like in the standard pdf and just not detect the last on stm

    if(areWeSendingPosition){
        canDevice -> writeFrame(frame1);
        canDevice -> writeFrame(frame2);
        canDevice -> writeFrame(frame3);
        canDevice -> writeFrame(frame4);
        canDevice -> writeFrame(frame5);
        canDevice -> writeFrame(frame6);
        canDevice -> writeFrame(frame7);
        //canDevice -> writeFrame(frame8);

        sendToCL2000(frame1);
        sendToCL2000(frame2);
        sendToCL2000(frame3);
        sendToCL2000(frame4);
        sendToCL2000(frame5);
        sendToCL2000(frame6);
        sendToCL2000(frame7);
        //sendToCL2000(frame8);
        if(tripPackageCounter5 != 192){
            tripPackageCounter5+=0x20; //but we want it in hex 0x00 0x20 0x40 0x60 0x80 ..
        }else{
            tripPackageCounter5=0x00;
        }
    }

}

void CanHandler::sendDepthPositionPackage()
{

    QCanBusFrame frame;
    frame.setFrameId(0x0DF50B00);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0xff;
    payload[1]=m_Depth[0];
    payload[2]=m_Depth[1];
    payload[3]=m_Depth[2];
    payload[4]=m_Depth[3];


    if(AmISendingMaxDepth){

        payload[1] = 0xff;
        payload[2] = 0xff;
        payload[3] = 0xff;
        payload[4] = 0xff;

    }

    payload[5]=0xff;
    payload[6]=0xff;
    payload[7]=0xff;
    frame.setPayload(payload);

    if(areWeSendingDepthMsg){
        canDevice -> writeFrame(frame);
        sendToCL2000(frame);
    }

}

void CanHandler::setPortRPM(uint16_t rpm){

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>(rpm & 0xFF);
    bytes[1] = static_cast<char>((rpm >> 8) & 0xFF);

    m_PortRPMbytes = bytes;

}

void CanHandler::setPortVoltage(uint16_t voltage)
{

    //qDebug()<<"Hello change";
    QByteArray bytes;
    bytes.resize(2);

    bytes[0] = 0x12;

    bytes[0] = static_cast<char>(voltage & 0xFF);
    bytes[1] = static_cast<char>((voltage >> 8) & 0xFF);

    m_PortVoltagebytes = bytes;

}

void CanHandler::setPortCurrent(int16_t current)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = (char)((current & 0xFF));
    bytes[1] = (char)((current >> 8) & 0xFF);

    // qint16_le value = current

    //Need to compare to the actual value somehow
    qDebug() << "Byte on the 0 spot: "<< QString::asprintf("%x", bytes[0] & 0xff);
    qDebug() << "Byte on the 1 spot: "<< QString::asprintf("%x", bytes[1] & 0xff);

    int16_t hh = (int16_t)(((uint16_t)bytes[0] | (((uint16_t)bytes[1]) << 8)));



    //int16_t full = bytes[0] | bytes[1] << 8;// I dont know maybe problems here, for now I will just leave it
    //int16_t afterProcess = static_cast<int16_t>(((uint16_t)bytes[0] << 8) | (uint16_t)bytes[1]);

    qDebug() <<"Processed value: "<< QString::asprintf("%x", hh & 0xFFFF);
    m_PortCurrentbytes = bytes;

}

void CanHandler::toggleSendingDepthInfo()
{
    if(areWeSendingDepthMsg){

        areWeSendingDepthMsg = false;
    }else {

        areWeSendingDepthMsg = true;
    }

}

void CanHandler::toggleSendingChargerInfo()
{

    if(areWeSendingChargerInfo){
        areWeSendingChargerInfo = false;

    }else {
        areWeSendingChargerInfo = true;

    }

}

void CanHandler::toggleSendingCellVoltagePackage()
{

    if(areWeSendingCellVoltage){
        areWeSendingCellVoltage=false;
    }else{
        areWeSendingCellVoltage=true;
    }

}

void CanHandler::toggleSendingPositionPackage()
{

    if(areWeSendingPosition){
        areWeSendingPosition = false;
    }else{
        areWeSendingPosition = true;
    }

}

void CanHandler::toggleSendingBatInfoMessage()
{

    if(areWeSendingBatInfo){
        areWeSendingBatInfo=false;
    }else areWeSendingBatInfo = true;

}

void CanHandler::toggleSendingHiCellTemp()
{

    if(areWeSendingHiCellTemp){
        areWeSendingHiCellTemp=false;
    }else areWeSendingHiCellTemp = true;

}

void CanHandler::toggleSendingStbTempMessage()
{

    if(areWeSendingStbMotorTemp){
        areWeSendingStbMotorTemp = false;
    }else{
        areWeSendingStbMotorTemp = true;
    }

}

void CanHandler::toggleSendingPortTempMessage()
{

    if(areWeSendingPortMotorTemp){
        areWeSendingPortMotorTemp = false;
    }else areWeSendingPortMotorTemp = true;

}

void CanHandler::toggleSendingPortMessage()
{
    if(areWeSendingPortMsg){
        areWeSendingPortMsg = false;
    }else areWeSendingPortMsg = true;
}

void CanHandler::toggleSendingStbMessage()
{

    if(areWeSendingStbMsg){
        areWeSendingStbMsg = false;
    }else areWeSendingStbMsg = true;
}

void CanHandler::toggleSendingSpeedMessage()
{
    if(areWeSendingSpeedMsg){
        areWeSendingSpeedMsg = false;
    }else areWeSendingSpeedMsg = true;

}

void CanHandler::toggleSendingTripMessage()
{

    if(areWeSendingTripMsg){
        areWeSendingTripMsg = false;
    }else areWeSendingTripMsg = true;

}

void CanHandler::toggleSendingDCDCMessage()
{

    if(areWeSendingDCDCInfo){
        areWeSendingDCDCInfo = false;
    }else areWeSendingDCDCInfo = true;

}

void CanHandler::toggleSendingVCUMessage()
{

    if(areWeSendingVCUMsg){
        areWeSendingVCUMsg = false;
    }else areWeSendingVCUMsg = true;

}

void CanHandler::toggleSendingCharger2Message()
{

    if(areWeSendingChargerMsg2){
        areWeSendingChargerMsg2 = false;
    }else areWeSendingChargerMsg2 = true;

}

void CanHandler::toggleSendingCharger3Message()
{

    if(areWeSendingChargerMsg3){
        areWeSendingChargerMsg3 = false;
    }else areWeSendingChargerMsg3 = true;

}

void CanHandler::toggleSendingPortMotorStatus()
{

    if(areWeSendingPortMotorStatus){
        areWeSendingPortMotorStatus = false;
    }else areWeSendingPortMotorStatus = true;

}

void CanHandler::toggleSendingThrottle1Status()
{

    if(areWeSendingThrottle1Status){
        areWeSendingThrottle1Status = false;
    }else areWeSendingThrottle1Status = true;

}

void CanHandler::toggleSendingThrottle2Status()
{

    if(areWeSendingThrottle2Status){
        areWeSendingThrottle2Status = false;
    }else areWeSendingThrottle2Status = true;

}

void CanHandler::toggleSendingRudderAngle()
{

    if(areWeSendingRudderAngle){
        areWeSendingRudderAngle = false;
    }else areWeSendingRudderAngle = true;

}

void CanHandler::toggleSendingConsumption()
{

    //sendConsumption(); //to try with single shots

    if(areWeSendingConsumption){
        areWeSendingConsumption = false;
    }else areWeSendingConsumption = true;

}

void CanHandler::toggleSendingWaterTemp()
{

    if(areWeSendingWaterTemp){
        areWeSendingWaterTemp = false;
    }else areWeSendingWaterTemp = true;

}

void CanHandler::setStbRPM(uint16_t rpm)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>(rpm & 0xFF);
    bytes[1] = static_cast<char>((rpm >> 8) & 0xFF);

    m_StbRPMbytes = bytes;

}

void CanHandler::setStbVoltage(uint16_t voltage)
{

    QByteArray bytes;
    bytes.resize(2);

    bytes[0] = 0x12;

    bytes[0] = static_cast<char>(voltage & 0xFF);
    bytes[1] = static_cast<char>((voltage >> 8) & 0xFF);

    m_StbVoltagebytes = bytes;

}

void CanHandler::setStbCurrent(int16_t current)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>((uint8_t)(current & 0xFF));
    bytes[1] =  static_cast<char>((current >> 8) & 0xFF);

    m_StbCurrentbytes = bytes;

}

void CanHandler::setDistToEmpty(uint32_t dist)
{
    QByteArray bytes;
    bytes.resize(4);
    bytes[0] = static_cast<char>(dist & 0xFF);
    bytes[1] = static_cast<char>((dist >> 8) & 0xFF);
    bytes[2] = static_cast<char>((dist >> 16) & 0xFF);
    bytes[3] = static_cast<char>((dist >> 24) & 0xFF);

    m_DistToEmpty = bytes;

}

void CanHandler::setTimeToEmpty(uint32_t time)
{
    QByteArray bytes;
    bytes.resize(4);
    bytes[0] = static_cast<char>(time & 0xFF);
    bytes[1] = static_cast<char>((time >> 8) & 0xFF);
    bytes[2] = static_cast<char>((time >> 16) & 0xFF);
    bytes[3] = static_cast<char>((time >> 24) & 0xFF);

    m_TimeToEmpty = bytes;

}

void CanHandler::setStbMotorTemp(uint16_t temp)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>((uint8_t)(temp & 0xFF));
    bytes[1] = static_cast<char>((temp >> 8) & 0xFF);

    m_StbMotorTemp = bytes;

}

void CanHandler::setStbInverterTemp(uint16_t temp)
{


    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>((uint8_t)(temp & 0xFF));
    bytes[1] = static_cast<char>((temp >> 8) & 0xFF);

    m_StbInverterTemp = bytes;

}

void CanHandler::setPortMotorTemp(uint16_t temp)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>((uint8_t)(temp & 0xFF));
    bytes[1] =  static_cast<char>((temp >> 8) & 0xFF);

    m_PortMotorTemp = bytes;

}

void CanHandler::setPortInverterTemp(uint16_t temp)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>((uint8_t)(temp & 0xFF));
    bytes[1] =  static_cast<char>((temp >> 8) & 0xFF);

    m_PortInverterTemp = bytes;

}

void CanHandler::setPortCoolantTemp(uint16_t temp)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>((uint8_t)(temp & 0xFF));
    bytes[1] =  static_cast<char>((temp >> 8) & 0xFF);

    m_PortCoolantTemperature = bytes;

}

void CanHandler::setSpeed(uint16_t speed){

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>((uint8_t)(speed & 0xFF));
    bytes[1] =  static_cast<char>((speed >> 8) & 0xFF);

    m_Speed = bytes;

}

void CanHandler::setHiCellTemp(uint16_t temp)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(temp & 0xFF));
    bytes[1] =  static_cast<char>((temp >> 8) & 0xFF);

    m_HiCellTemp = bytes;

}

void CanHandler::setLoCellTemp(uint16_t temp)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(temp & 0xFF));
    bytes[1] =  static_cast<char>((temp >> 8) & 0xFF);

    m_LoCellTemp = bytes;

}

void CanHandler::setSOC(uint8_t soc)
{
    QByteArray bytes;
    bytes.resize(1);
    bytes[0] = soc;

    m_SOC = bytes;

}

void CanHandler::setTimeToFull(int16_t time)
{
    qDebug() << time << "\n";
    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(time & 0xFF));
    bytes[1] =  static_cast<char>((time >> 8) & 0xFF);
    m_TimeToFull = bytes;

}

void CanHandler::setBatVoltage(uint16_t volt)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(volt & 0xFF));
    bytes[1] =  static_cast<char>((volt >> 8) & 0xFF);

    m_BatVoltage = bytes;

}

void CanHandler::setBatCurrent(int16_t volt)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(volt & 0xFF));
    bytes[1] =  static_cast<char>((volt >> 8) & 0xFF);

    m_BatCurrent = bytes;

}

void CanHandler::setLat(int64_t value)
{

    QByteArray bytes;
    bytes.resize(8);

    bytes[0] = static_cast<char>((value >> 0) & 0xFF);
    bytes[1] = static_cast<char>((value >> 8) & 0xFF);
    bytes[2] = static_cast<char>((value >> 16) & 0xFF);
    bytes[3] = static_cast<char>((value >> 24) & 0xFF);
    bytes[4] = static_cast<char>((value >> 32) & 0xFF);
    bytes[5] = static_cast<char>((value >> 40) & 0xFF);
    bytes[6] = static_cast<char>((value >> 48) & 0xFF);
    bytes[7] = static_cast<char>((value >> 56) & 0xFF);

    m_Lat = bytes;

}

void CanHandler::setLon(int64_t value)
{

    QByteArray bytes;
    bytes.resize(8);

    bytes[0] = static_cast<char>((value >> 0) & 0xFF);
    bytes[1] = static_cast<char>((value >> 8) & 0xFF);
    bytes[2] = static_cast<char>((value >> 16) & 0xFF);
    bytes[3] = static_cast<char>((value >> 24) & 0xFF);
    bytes[4] = static_cast<char>((value >> 32) & 0xFF);
    bytes[5] = static_cast<char>((value >> 40) & 0xFF);
    bytes[6] = static_cast<char>((value >> 48) & 0xFF);
    bytes[7] = static_cast<char>((value >> 56) & 0xFF);

    m_Lon = bytes;

}

void CanHandler::setHiVoltage(uint16_t value)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    m_HiCellVoltage = bytes;

}

void CanHandler::setLoVoltage(uint16_t value)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    m_LoCellVoltage = bytes;

}

void CanHandler::setBMSStatus(uint8_t value)
{

    QByteArray bytes;
    bytes.resize(1);
    bytes[0] = static_cast<char>(value);

    m_BMSStatus = bytes;

}

void CanHandler::setChargerTemp(int16_t value)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    m_ChargerTemp = bytes;

}

void CanHandler::setChargerVoltage(uint16_t value)
{
    qDebug() << "voltage" << value << "\n";
    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    m_ChargerVoltage = bytes;

}

void CanHandler::setChargerCurrent(int16_t value)
{
    qDebug() << "current" << value << "\n";
    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    m_ChargerCurrent = bytes;

}

void CanHandler::setChargerStatus(uint8_t status)
{

    QByteArray bytes;
    bytes.resize(1);
    bytes[0] = static_cast<char>(status);

    m_ChargerStatus = bytes;

}

void CanHandler::setCharger2VoltageL1(uint16_t value)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    if(bytes[0] == 0x10 && bytes[1] == 0x27){

        bytes[0] = 0xFF;
        bytes[1] = 0xFF;

    }

    m_ChargerInputVoltageL1 = bytes;

}

void CanHandler::setCharger2VoltageL2(uint16_t value)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    if(bytes[0] == 0x10 && bytes[1] == 0x27){

        bytes[0] = 0xFF;
        bytes[1] = 0xFF;

    }

    m_ChargerInputVoltageL2 = bytes;

}

void CanHandler::setCharger2VoltageL3(uint16_t value)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    if(bytes[0] == 0x10 && bytes[1] == 0x27){

        bytes[0] = 0xFF;
        bytes[1] = 0xFF;

    }

    m_ChargerInputVoltageL3 = bytes;

}

void CanHandler::setCharger2Temperature1(uint8_t value)
{

    QByteArray bytes;
    bytes.resize(1);
    bytes[0] = static_cast<char>(value);

    m_ChargerTemperature1 = bytes;

}

void CanHandler::setCharger3CurrentL1(int16_t value)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    if(bytes[0] == 0x40 && bytes[1] == 0x1F){

        bytes[0] = 0xFF;
        bytes[1] = 0xFF;

    }

    m_ChargerInputCurrentL1 = bytes;

}

void CanHandler::setCharger3CurrentL2(int16_t value)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    if(bytes[0] == 0x40 && bytes[1] == 0x1F){

        bytes[0] = 0xFF;
        bytes[1] = 0xFF;

    }

    m_ChargerInputCurrentL2 = bytes;

}

void CanHandler::setCharger3CurrentL3(int16_t value)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);

    if(bytes[0] == 0x40 && bytes[1] == 0x1F){

        bytes[0] = 0xFF;
        bytes[1] = 0xFF;

    }

    m_ChargerInputCurrentL3 = bytes;

}

void CanHandler::setDepth(uint32_t value)
{

    QByteArray bytes;
    bytes.resize(4);
    bytes[0] = static_cast<char>(value & 0xFF);
    bytes[1] = static_cast<char>((value >> 8) & 0xFF);
    bytes[2] = static_cast<char>((value >> 16) & 0xFF);
    bytes[3] = static_cast<char>((value >> 24) & 0xFF);

    m_Depth = bytes;

}

void CanHandler::sendAlarmPackage(QByteArray data)
{
    const int FIRST_PAYLOAD_SIZE = 6;
    const int SUBSEQUENT_PAYLOAD_SIZE = 7;

    qDebug() << "\nData size: "<<data.size()<<"\n";
    int totalSize = static_cast<uint8_t>(data.size());
    int remainingSize = totalSize - FIRST_PAYLOAD_SIZE;
    int numSubsequentFrames = (remainingSize + SUBSEQUENT_PAYLOAD_SIZE - 1) / SUBSEQUENT_PAYLOAD_SIZE; // Ceiling division

    // Handle the first 6 bytes
    QByteArray firstPayload(FIRST_PAYLOAD_SIZE + 2, 0); // 6 bytes + 2 for headers
    firstPayload[0] = 0x00 | 0x00; // Example header for the first frame
    firstPayload[1] = totalSize; // Example header value
    for (int i = 0; i < FIRST_PAYLOAD_SIZE; ++i) {
        firstPayload[i + 2] = data[i];
    }

    QCanBusFrame firstFrame;
    firstFrame.setFrameId(0x14FFA000);
    firstFrame.setPayload(firstPayload);
    sendToCL2000(firstFrame); // Placeholder for actual sending logic
    //qDebug() << "Sent first frame with payload:" << firstPayload.toHex();

    // Handle the remaining bytes in chunks of 7 bytes
    for (int i = 0; i < numSubsequentFrames; ++i) {
        QCanBusFrame frame;
        frame.setFrameId(0x14FFA000);
        QByteArray payload(SUBSEQUENT_PAYLOAD_SIZE + 1, 0); // 7 bytes + 1 for header

        int offset = FIRST_PAYLOAD_SIZE + i * SUBSEQUENT_PAYLOAD_SIZE;
        int chunkSize = qMin(SUBSEQUENT_PAYLOAD_SIZE, totalSize - offset);

        payload[0] = 0x00 | (((i + 1)) & 0x0F); // Example header for subsequent frames
        for (int j = 0; j < chunkSize; ++j) {
            payload[j + 1] = data[offset + j];
        }

        frame.setPayload(payload);
        sendToCL2000(frame); // Placeholder for actual sending logic
        //qDebug() << "Sent subsequent frame" << i << "with payload:" << payload.toHex();


    }

}



void CanHandler::testingData()
{

    auto const data = port->read(1024);

    qDebug()<<"Here is data: "<<data;

}

void CanHandler::transformCanPackage(const QCanBusFrame &frame, QByteArray &packedFrame)
{

    QByteArray payloadArray;
    QDataStream payloadStream(&payloadArray, QIODevice::ReadWrite);
    payloadStream.setByteOrder(QDataStream::ByteOrder::BigEndian);

    payloadStream << static_cast<quint8>(0x03);

    /* Write CAN ID (Big endian) */
    quint32 canID = frame.frameId() & 0x1FFFFFFF;
    if( frame.hasExtendedFrameFormat() ) {
        canID |= 0x20000000;
    }
    payloadStream << canID;

    int dataLength = frame.payload().length();
    if(0 <= dataLength && dataLength <= 8) {
        auto DLC = static_cast<quint8>(dataLength);
        payloadStream << DLC;
    }

    payloadStream.writeRawData(frame.payload().data(), dataLength);

    /* Calculate checksum */
    quint16 checksum = calculateCRC16(payloadArray);

    /* Write checksum */
    payloadStream << checksum;

    /* Escape any 0x7E sequences */
    packedFrame.append(0x07E);
    for (char const& byteValue: payloadArray) {
        if( byteValue == 0x7E ) {
            packedFrame.append(static_cast<quint8>(0x7D));
            packedFrame.append(static_cast<quint8>(byteValue ^ 0b00100000) );
        } else {
            packedFrame.append(byteValue );
        }
    }
    packedFrame.append(0x07E);

}

void CanHandler::sendToCL2000(const QCanBusFrame &frame)
{

    QByteArray packedFrame;
    transformCanPackage(frame, packedFrame);

    port->write(packedFrame);

}

void CanHandler::setSendingMaxDepth(int arg)
{

    if(arg == 2){

        AmISendingMaxDepth = true;

    }else if(arg == 0){

        AmISendingMaxDepth = false;

    }


}

uint16_t CanHandler::calculateCRC16(QByteArray data, CRC16Type crc16Type)
{
    uint16_t const initial = 0x0000u;
    uint16_t const polynomial = 0xA001;
    uint16_t const final = 0x0000;

    uint16_t crc = initial;

    for(char const& value: data) {
        // Reinterpret from signed to unsigned.
        uint8_t d = value;

        crc ^= d;

        for(auto i = 0; i < 8; ++i) {
            if (crc & 0x0001u) {
                crc >>= 1;
                crc ^= polynomial;
            } else {
                crc >>= 1;
            }
        }
    }

    return crc ^ final;
}

void CanHandler::sendAlarmNotActivePackage(uint8_t type, uint16_t id){

    QByteArray bytesType;
    bytesType.resize(1);

    bytesType[0] = static_cast<char>(type);


    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(id & 0xFF));
    bytes[1] =  static_cast<char>((id >> 8) & 0xFF);

    QCanBusFrame frame;
    frame.setFrameId(0x14FFA100);
    QByteArray payload;
    payload.resize(8);
    payload[0]=bytesType[0];
    payload[1]=bytes[0];
    payload[2]=bytes[1];
    payload[3]=0x00;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);


    canDevice -> writeFrame(frame);
    sendToCL2000(frame);


}

void CanHandler::sendMotorDirectionLeft()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18EFFD1D);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=0x03;
    payload[2]=0x02;
    payload[3]=0x02;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x01;
    frame.setPayload(payload);

    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendMotorDirectionRight()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18EFFD1D);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=0x03;
    payload[2]=0x02;
    payload[3]=0x02;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendMotorContinousRPM(uint16_t rpm)
{

    uint8_t highByte = (rpm >> 8) & 0xFF;
    uint8_t lowByte = rpm & 0xFF;

    QCanBusFrame frame;
    frame.setFrameId(0x18EFFD1D);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=0x03;
    payload[2]=0x02;
    payload[3]=0x03;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=lowByte;
    payload[7]=highByte;
    frame.setPayload(payload);

    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendMotorPeakRPM(uint16_t rpm)
{

    uint8_t highByte = (rpm >> 8) & 0xFF;
    uint8_t lowByte = rpm & 0xFF;

    QCanBusFrame frame;
    frame.setFrameId(0x18EFFD1D);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=0x03;
    payload[2]=0x02;
    payload[3]=0x04;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=lowByte;
    payload[7]=highByte;
    frame.setPayload(payload);

    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendLeverNFCEnabled()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18EFFD1D);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x30;
    payload[1]=0x03;
    payload[2]=0x02;
    payload[3]=0x03;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x01;
    frame.setPayload(payload);

    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendLeverNFCDisabled()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18EFFD1D);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x30;
    payload[1]=0x03;
    payload[2]=0x02;
    payload[3]=0x03;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendVCUResponse()
{

    std::array<uint8_t, 3> bytesToSend;
    bytesToSend = m_VCUPumpHandler.getArray();

    QCanBusFrame frame;
    frame.setFrameId(0x18FF9BD0);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x20;
    payload[1]=0x03;
    payload[2]=bytesToSend[0]; //DRV byte 0
    payload[3]=bytesToSend[1]; //DRV byte 1
    payload[4]=bytesToSend[2]; //DRV byte 2
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendECUResponse()
{


    std::array<uint8_t, 3> tempECUArray = m_ECUPumpHandler.getArray();

    QCanBusFrame frame;
    frame.setFrameId(0x18FF9BD0);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00; //ECU is 0x00 now
    payload[1]=0x03;
    payload[2]=tempECUArray[0]; //DRV byte 0
    payload[3]=tempECUArray[1]; //DRV byte 1
    payload[4]=tempECUArray[2]; //DRV byte 2
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendVCUCommisionResponse()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18EFFD1D);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x20;
    payload[1]=0x03;
    payload[2]=0x03;
    payload[3]=0x01;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0xFF;
    frame.setPayload(payload);

    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendTripMessage(uint16_t time, uint16_t distance, uint16_t power, bool isResetSince, bool isResetTotal)
{

    uint8_t timeLowByte = time & 0xFF;
    uint8_t timeHighByte = (time >> 8) & 0xFF;

    uint8_t distanceLowByte = distance & 0xFF;
    uint8_t distanceHighByte = (distance >> 8) & 0xFF;

    uint8_t powerLowByte = power & 0xFF;
    uint8_t powerHighByte = (power >> 8) & 0xFF;

    uint8_t resetByte = 0x00;

    if(isResetSince) resetByte += 0x01;
    if(isResetTotal) resetByte += 0x02;

    QCanBusFrame frame;
    frame.setFrameId(0x18FF9018);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00; // node id
    payload[1]=timeLowByte;
    payload[2]=timeHighByte;
    payload[3]=distanceLowByte;
    payload[4]=distanceHighByte;
    payload[5]=powerLowByte;
    payload[6]=powerHighByte;
    payload[7]=resetByte;
    frame.setPayload(payload);

    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendCurrentShoreLimit(int Ampers)
{

    QCanBusFrame frame;
    frame.setFrameId(0x18EFFD1D);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x10;
    payload[1]=0x02;
    payload[2]=0x02;
    payload[3]=0x01;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=(uint8_t)Ampers;
    frame.setPayload(payload);


    canDevice -> writeFrame(frame);
    sendToCL2000(frame);

}

void CanHandler::sendWaterTemp()
{


    QCanBusFrame frame;
    frame.setFrameId(0x15FD0CFE);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=0x00;
    payload[2]=0x00;
    payload[3]=m_WaterTemp[0];
    payload[4]=m_WaterTemp[1];
    payload[5]=m_WaterTemp[2];
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    if(areWeSendingWaterTemp){

        canDevice -> writeFrame(frame);
        sendToCL2000(frame);

    }

}

void CanHandler::sendDCDCInfoPackage(){

    QCanBusFrame frame;
    frame.setFrameId(0x18FF96D0);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=m_DCDCStatus[0];
    payload[2]=m_DCDCVoltage[0];
    payload[3]=m_DCDCVoltage[1];
    payload[4]=m_DCDCCurrent[0];
    payload[5]=m_DCDCCurrent[1];
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    if(areWeSendingDCDCInfo){

        canDevice -> writeFrame(frame);
        sendToCL2000(frame);

    }

}

void CanHandler::sendVCUPackage()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18FF9A27);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x20;
    payload[1]=m_VCUStatus[0];
    payload[2]=0x00;
    payload[3]=0x00;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    QCanBusFrame frame2;
    frame2.setFrameId(0x18FF9700);
    QByteArray payload2;
    payload2.resize(8);
    payload2[0]=0x00;
    payload2[1]=0x00;
    payload2[2]=m_VCUDriveStatus[0];
    payload2[3]=0x00;
    payload2[4]=0x00;
    payload2[5]=0x00;
    payload2[6]=0x00;
    payload2[7]=0x00;
    frame2.setPayload(payload2);

    //Also send ecu status message for modes

    if(areWeSendingVCUMsg){

        canDevice -> writeFrame(frame);
        sendToCL2000(frame);

        canDevice -> writeFrame(frame2);
        sendToCL2000(frame2);

    }


}

void CanHandler::sendChargerInfo2()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18FF9249);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=m_ChargerInputVoltageL1[0];
    payload[2]=m_ChargerInputVoltageL1[1];
    payload[3]=m_ChargerInputVoltageL2[0];
    payload[4]=m_ChargerInputVoltageL2[1];
    payload[5]=m_ChargerInputVoltageL3[0];
    payload[6]=m_ChargerInputVoltageL3[1];
    payload[7]=m_ChargerTemperature1[0];
    frame.setPayload(payload);

    if(areWeSendingChargerMsg2){

        canDevice -> writeFrame(frame);
        sendToCL2000(frame);

    }

}

void CanHandler::sendChargerInfo3()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18FF9349);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=m_ChargerInputCurrentL1[0];
    payload[2]=m_ChargerInputCurrentL1[1];
    payload[3]=m_ChargerInputCurrentL2[0];
    payload[4]=m_ChargerInputCurrentL2[1];
    payload[5]=m_ChargerInputCurrentL3[0];
    payload[6]=m_ChargerInputCurrentL3[1];
    payload[7]=0x00;
    frame.setPayload(payload);

    if(areWeSendingChargerMsg3){

        canDevice -> writeFrame(frame);
        sendToCL2000(frame);

    }

}

void CanHandler::sendPortMotorInfo()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18FF9700);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=m_PortMotorStatus[0];
    payload[2]=0x00;
    payload[3]=0x00;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    if(areWeSendingPortMotorStatus){

        canDevice -> writeFrame(frame);
        sendToCL2000(frame);

    }

}

void CanHandler::sendThrottle1Status()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18FF80FD);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x30;
    payload[1]=m_Throttle1Status[0];
    payload[2]=0x00;
    payload[3]=0x00;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    if(areWeSendingThrottle1Status){

        canDevice -> writeFrame(frame);
        sendToCL2000(frame);

    }

}

void CanHandler::sendThrottle2Status()
{

    QCanBusFrame frame;
    frame.setFrameId(0x18FF80FD);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x31;
    payload[1]=m_Throttle2Status[0];
    payload[2]=0x00;
    payload[3]=0x00;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    if(areWeSendingThrottle2Status){

        canDevice -> writeFrame(frame);
        sendToCL2000(frame);

    }

}

void CanHandler::sendRudderAngle()
{

    QCanBusFrame frame;
    frame.setFrameId(0x09F10DFE);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=0x00;
    payload[2]=0x00;
    payload[3]=0x00;
    payload[4]=m_RudderAngle[0]; //rudder angle low byte
    payload[5]=m_RudderAngle[1]; //rudder angle high byte
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    if(areWeSendingRudderAngle){

        canDevice -> writeFrame(frame);
        sendToCL2000(frame);

    }

}

void CanHandler::setDCDCStatus(int status){

    QByteArray bytes;
    bytes.resize(1);
    bytes[0] = (uint8_t)status;

    m_DCDCStatus = bytes;


}

void CanHandler::setDCDCVoltage(uint16_t value){

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>(value & 0xFF);
    bytes[1] = static_cast<char>((value >> 8) & 0xFF);

    m_DCDCVoltage = bytes;

}

void CanHandler::setDCDCCurrent(int16_t value){

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);
    m_DCDCCurrent = bytes;

}

void CanHandler::setRudderAngle(int16_t value)
{

    QByteArray bytes;
    bytes.resize(2);
    bytes[0] =  static_cast<char>((uint8_t)(value & 0xFF));
    bytes[1] =  static_cast<char>((value >> 8) & 0xFF);
    m_RudderAngle = bytes;

}

void CanHandler::setMotorStatus(int status)
{

    QByteArray bytes;
    bytes.resize(1);
    bytes[0] = static_cast<char>(status);

    m_PortMotorStatus = bytes;

}

void CanHandler::setVCUStatus(int status)
{

    m_VCUStatus[0] = status;

}

void CanHandler::setVCUDriveStatus(int status)
{

    m_VCUDriveStatus[0] = status;

}

void CanHandler::setThrottle1Status(int status)
{

    if(status == 1){//Unlocked inactive

        m_Throttle1Status[0] = 0x01;

    }else if(status == 2){//Unlocked active

        m_Throttle1Status[0] = 0x03;

    }

}

void CanHandler::setThrottle2Status(int status)
{

    if(status == 1){//Unlocked inactive

        m_Throttle2Status[0] = 0x01;

    }else if(status == 2){//Unlocked active

        m_Throttle2Status[0] = 0x03;

    }

}

void CanHandler::setBatteryExternalPump(int set)
{

    if(set == 2){

        m_VCUPumpHandler.turnOnExternalPump();

    }else if(set == 0){

        m_VCUPumpHandler.turnOffExternalPump();

    }

}

void CanHandler::setBatteryInternalPump(int set)
{

    if(set == 2){

        m_VCUPumpHandler.turnOnInternalPump();

    }else if(set == 0){

        m_VCUPumpHandler.turnOffInternalPump();

    }

}

void CanHandler::setCoolingValve(int set){

    if(set == 2){

        m_VCUPumpHandler.turnOnCoolingValve();

    }else if(set == 0){

        m_VCUPumpHandler.turnOffCoolingValve();

    }

}

void CanHandler::setHeatingValve(int set){

    if(set == 2){

        m_VCUPumpHandler.turnOnHeatingValve();

    }else if(set == 0){

        m_VCUPumpHandler.turnOffHeatingValve();

    }
}

void CanHandler::setHeater(int set)
{

    if(set == 2){

        m_VCUPumpHandler.turnOnHeater();

    }else if(set == 0){

        m_VCUPumpHandler.turnOffHeater();

    }

}

void CanHandler::setHeatExchange(int set)
{

    if(set == 2){

        m_VCUPumpHandler.turnOnHeatExchange();

    }else if(set == 0){

        m_VCUPumpHandler.turnOffHeatExchange();

    }

}

void CanHandler::setMotorExternalPump(int set)
{

    if(set == 2){

        m_ECUPumpHandler.turnOnExternalPump();

    }else if(set == 0){

        m_ECUPumpHandler.turnOffExternalPump();

    }

}

void CanHandler::setMotorInternalPump(int set)
{

    if(set == 2){

        m_ECUPumpHandler.turnOnInternalPump();

    }else if(set == 0){

        m_ECUPumpHandler.turnOffInternalPump();

    }

}

void CanHandler::setMotorExternal2Pump(int set){

    if(set == 2){

        m_ECUPumpHandler.turnOnExternal2Pump();

    }else if(set == 0){

        m_ECUPumpHandler.turnOffExternal2Pump();

    }

}

void CanHandler::setMotorInternal2Pump(int set){

    if(set == 2){

        m_ECUPumpHandler.turnOnInternal2Pump();

    }else if(set == 0){

        m_ECUPumpHandler.turnOffInternal2Pump();

    }

}

void CanHandler::setWaterTemperature(uint32_t value)
{

    QByteArray bytes;
    bytes.resize(8);

    bytes[0] = static_cast<char>((value >> 0) & 0xFF);
    bytes[1] = static_cast<char>((value >> 8) & 0xFF);
    bytes[2] = static_cast<char>((value >> 16) & 0xFF);

    m_WaterTemp = bytes;

}

void CanHandler::sendConsumption(){

    QCanBusFrame frame;
    frame.setFrameId(0x19F20100);
    QByteArray payload;
    payload.resize(8);
    payload[0]=0x00;
    payload[1]=0x1B;
    payload[2]=0x00;
    payload[3]=0x00;
    payload[4]=0x00;
    payload[5]=0x00;
    payload[6]=0x00;
    payload[7]=0x00;
    frame.setPayload(payload);

    QCanBusFrame frame2;
    frame2.setFrameId(0x19F20100);
    QByteArray payload2;
    payload2.resize(8);
    payload2[0]=0x01;
    payload2[1]=0x00;
    payload2[2]=0x00;
    payload2[3]=0x00;
    payload2[4]=0x90;//Fuel rate low byte
    payload2[5]=0x00;//Fuel rate high byte
    payload2[6]=0x00;
    payload2[7]=0x00;
    frame2.setPayload(payload2);

    QCanBusFrame frame3;
    frame3.setFrameId(0x19F20100);
    QByteArray payload3;
    payload3.resize(8);
    payload3[0]=0x02;
    payload3[1]=0x00;
    payload3[2]=0x00;
    payload3[3]=0x00;
    payload3[4]=0x00;
    payload3[5]=0x00;
    payload3[6]=0x00;
    payload3[7]=0x00;
    frame3.setPayload(payload3);

    QCanBusFrame frame4;
    frame4.setFrameId(0x19F20100);
    QByteArray payload4;
    payload4.resize(8);
    payload4[0]=0x03;
    payload4[1]=0x00;
    payload4[2]=0x00;
    payload4[3]=0x00;
    payload4[4]=0x00;
    payload4[5]=0x00;
    payload4[6]=0x00;
    payload4[7]=0x00;
    frame4.setPayload(payload4);

    //Add boolean here and send on interval
    if(areWeSendingConsumption){
        canDevice -> writeFrame(frame);
        sendToCL2000(frame);

        canDevice -> writeFrame(frame2);
        sendToCL2000(frame2);

        canDevice -> writeFrame(frame3);
        sendToCL2000(frame3);

        canDevice -> writeFrame(frame4);
        sendToCL2000(frame4);
    }

}



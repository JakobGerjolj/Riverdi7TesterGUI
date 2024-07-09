#include "canhandler.h"

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

    QTimer *timer  = new QTimer(this);
    connect(timer, &QTimer::timeout,this, &CanHandler::sendPortRPMPackage);
    timer->start(100);

    QTimer *timer2 = new QTimer(this);
    connect(timer2, &QTimer::timeout, this, &CanHandler::sendStbRPMPackage);
    timer2->start(500);

    QTimer *timer3 = new QTimer(this);
    connect(timer3, &QTimer::timeout, this, &CanHandler::sendSpeedPackage);
    timer3->start(500);

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

}

CanHandler::~CanHandler()
{
    qDebug()<<"Closing connections";
    canDevice -> disconnectDevice();
    delete canDevice;

}

void CanHandler::startCAN(){

    const QString pluginName = "virtualcan";

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

void CanHandler::sendHiCellPackage()
{

    QCanBusFrame frame1;
    frame1.setFrameId(0x001DF203);
    QByteArray payload1;
    payload1.resize(8);

    payload1[0] = (uint8_t)(tripPackageCounter3 | 0x00);
    payload1[1] = 0x0f;
    payload1[2] = 0x00;
    payload1[3] = m_SOC[0];
    payload1[4] = 0x00;
    payload1[5] = 0x00;
    payload1[6] = m_HiCellTemp[0];
    payload1[7] = m_HiCellTemp[1];
    frame1.setPayload(payload1);

    QCanBusFrame frame2;
    frame2.setFrameId(0x001DF203);
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
    frame3.setFrameId(0x001DF203);
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

    if(areWeSendingPortMsg)
        canDevice -> writeFrame(frame);

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

    if(areWeSendingStbMsg)
        canDevice -> writeFrame(frame);


}

void CanHandler::sendSpeedPackage()
{


    QCanBusFrame frame;
    frame.setFrameId(0x15F80200);
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

    if(areWeSendingSpeedMsg)
        canDevice -> writeFrame(frame);

}

void CanHandler::sendTripPackage()
{

    QCanBusFrame frame1;
    frame1.setFrameId(0x015F208);
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
    frame2.setFrameId(0x015F208);
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
    frame3.setFrameId(0x015F208);
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
    payload2[1] = 0x00;
    payload2[2] = 0x00;
    payload2[3] = 0x00;
    payload2[4] = 0x00;
    payload2[5] = 0x00;
    payload2[6] = 0x00;
    payload2[7] = 0x00;
    frame2.setPayload(payload2);

    if(areWeSendingPortMotorTemp){
        canDevice -> writeFrame(frame1);
        canDevice -> writeFrame(frame2);
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
    payload[0]=0xff;
    payload[1]=0xff;
    payload[2]=m_BatVoltage[0];
    payload[3]=m_BatVoltage[1];
    payload[4]=m_BatCurrent[0];
    payload[5]=m_BatCurrent[1];
    payload[6]=0xff;
    payload[7]=0xff;
    frame.setPayload(payload);

    if(areWeSendingBatInfo)
        canDevice -> writeFrame(frame);

}

void CanHandler::sendPositionPackage()
{

    QCanBusFrame frame1;
    frame1.setFrameId(0x0DF80500);
    QByteArray payload1;
    payload1.resize(8);

    payload1[0] = (uint8_t)(tripPackageCounter | 0x00);
    payload1[1] = 0x0e;
    payload1[2] = 0x00;
    payload1[3] = 0x00;
    payload1[4] = 0x00;
    payload1[5] = 0x00;
    payload1[6] = 0x00;
    payload1[7] = 0x00;
    frame1.setPayload(payload1);

    QCanBusFrame frame2;
    frame2.setFrameId(0x0DF80500);
    QByteArray payload2;
    payload2.resize(8);
    payload2[0] = (uint8_t)(tripPackageCounter | 0x01);
    payload2[1] = 0x00;
    payload2[2] = m_Lat[0];
    payload2[3] = m_Lat[1];
    payload2[4] = m_Lat[2];
    payload2[5] = m_Lat[3];
    payload2[6] = m_Lat[4];
    payload2[7] = m_Lat[5];
    frame2.setPayload(payload2);

    QCanBusFrame frame3;
    frame3.setFrameId(0x0DF80500);
    QByteArray payload3;
    payload3.resize(8);
    payload3[0] = (uint8_t)(tripPackageCounter | 0x02);
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
    QByteArray payload4;
    payload4.resize(8);
    payload4[0] = (uint8_t)(tripPackageCounter | 0x03);
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
    QByteArray payload5;
    payload5.resize(8);
    payload5[0] = (uint8_t)(tripPackageCounter | 0x04);
    payload5[1] = 0x00;
    payload5[2] = 0x00;
    payload5[3] = 0x00;
    payload5[4] = 0x00;
    payload5[5] = 0x00;
    payload5[6] = 0x00;
    payload5[7] = 0x00;
    frame5.setPayload(payload5);

    QCanBusFrame frame6;
    frame6.setFrameId(0x0DF80500);
    QByteArray payload6;
    payload6.resize(8);
    payload6[0] = (uint8_t)(tripPackageCounter | 0x05);
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
    QByteArray payload7;
    payload7.resize(8);
    payload7[0] = (uint8_t)(tripPackageCounter | 0x06);
    payload7[1] = 0x00;
    payload7[2] = 0x00;
    payload7[3] = 0x00;
    payload7[4] = 0x00;
    payload7[5] = 0x00;
    payload7[6] = 0x00;
    payload7[7] = 0x00;
    frame7.setPayload(payload7);

    //Here we might have to add another package so that it is 7 like in the standard pdf and just not detect the last on stm

    if(areWeSendingPosition){
        canDevice -> writeFrame(frame1);
        canDevice -> writeFrame(frame2);
        canDevice -> writeFrame(frame3);
        canDevice -> writeFrame(frame4);
        canDevice -> writeFrame(frame5);
        canDevice -> writeFrame(frame6);
        canDevice -> writeFrame(frame7);
        if(tripPackageCounter5 != 240){
            tripPackageCounter5+=0x20; //but we want it in hex 0x00 0x20 0x40 0x60 0x80 ..
        }else{
            tripPackageCounter5=0x00;
        }
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
    bytes[0] = static_cast<char>((current & 0xFF));
    bytes[1] = static_cast<char>((current >> 8) & 0xFF);

    // qint16_le value = current

    //int16_t hh = (int16_t)((uint16_t)(bytes[0] >> 8) | (uint16_t)(bytes[1] << 8));



    //int16_t full = bytes[0] | bytes[1] << 8;// I dont know maybe problems here, for now I will just leave it
    //int16_t afterProcess = static_cast<int16_t>(((uint16_t)bytes[0] << 8) | (uint16_t)bytes[1]);

    //qDebug() <<"Processed value: "<< full;
    m_PortCurrentbytes = bytes;

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

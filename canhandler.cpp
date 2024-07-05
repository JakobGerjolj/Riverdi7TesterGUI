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

    QTimer *timer  = new QTimer(this);
    connect(timer, &QTimer::timeout,this, &CanHandler::sendPortRPMPackage);
    timer->start(500);

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

    canDevice -> writeFrame(frame);

    //here we will add Current and Voltage from slider
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

void CanHandler::setPortCurrent(uint16_t current)
{
    QByteArray bytes;
    bytes.resize(2);
    bytes[0] = static_cast<char>((uint8_t)(current & 0xFF));
    bytes[1] =  static_cast<char>((current >> 8) & 0xFF);

    m_PortCurrentbytes = bytes;
}

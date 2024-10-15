#ifndef CANHANDLER_H
#define CANHANDLER_H

#include <QObject>
#include <QCanBusDevice>
#include <QCanBusDevice>
#include <QCanBus>
#include <QDebug>
#include <QTimer>
#include <QByteArray>
#include <QtEndian>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <cstdint>
#include <QByteArray>

class CanHandler : public QObject
{
    Q_OBJECT
public:
    explicit CanHandler(QObject *parent = nullptr);
    ~CanHandler();
    void setPortRPM(uint16_t rpm);
    void setPortVoltage(uint16_t voltage);
    void setPortCurrent(int16_t current);

    void toggleSendingDepthInfo();

    void toggleSendingChargerInfo();

    void toggleSendingCellVoltagePackage();

    void toggleSendingPositionPackage();

    void toggleSendingBatInfoMessage();

    void toggleSendingHiCellTemp();

    void toggleSendingStbTempMessage();

    void toggleSendingPortTempMessage();

    void toggleSendingPortMessage();

    void toggleSendingStbMessage();

    void toggleSendingSpeedMessage();

    void toggleSendingTripMessage();

    void setStbRPM(uint16_t rpm);
    void setStbVoltage(uint16_t voltage);
    void setStbCurrent(int16_t current);

    void setDistToEmpty(uint32_t dist);
    void setTimeToEmpty(uint32_t time);

    void setStbMotorTemp(uint16_t temp);
    void setStbInverterTemp(uint16_t temp);

    void setPortMotorTemp(uint16_t temp);
    void setPortInverterTemp(uint16_t temp);

    void setSpeed(uint16_t speed);

    void setHiCellTemp(uint16_t temp);
    void setLoCellTemp(uint16_t temp);
    void setSOC(uint8_t soc);
    void setTimeToFull(int16_t time);

    void setBatVoltage(uint16_t volt);
    void setBatCurrent(int16_t volt);

    void setLat(int64_t value);
    void setLon(int64_t value);

    void setHiVoltage(uint16_t value);
    void setLoVoltage(uint16_t value);

    void setChargerTemp(int16_t value);
    void setChargerVoltage(uint16_t value);
    void setChargerCurrent(int16_t);

    void setDepth(uint32_t);


    void sendAlarmPackage(QByteArray data);
    void sendAlarmNotActivePackage(uint8_t type, uint16_t id);


    //Testing CL2000

    void testingData();

    void transformCanPackage(QCanBusFrame const& frame, QByteArray &packedFrame);

    void sendToCL2000(const QCanBusFrame &frame);


    enum struct CRC16Type {
        CRC_16_IBM
    };



    uint16_t calculateCRC16(QByteArray data, CRC16Type crc16Type = CRC16Type::CRC_16_IBM);

signals:

private:

    //Testing

    QSerialPort* port;


    //End testing
    bool areWeSendingChargerInfo{false};
    bool areWeSendingCellVoltage{false};
    bool areWeSendingPosition{false};
    bool areWeSendingBatInfo{false};
    bool areWeSendingHiCellTemp{false};
    bool areWeSendingPortMotorTemp{false};
    bool areWeSendingStbMotorTemp{false};
    bool areWeSendingTripMsg{false};
    bool areWeSendingStbMsg{false};
    bool areWeSendingPortMsg{false};
    bool areWeSendingSpeedMsg{false};
    void startCAN();
    void readAndProcessCANpodatke();
    QCanBusDevice *canDevice;

    bool areWeSendingDepthMsg{false};

    void sendChargerInfo();
    void sendCellVoltage();
    void sendHiCellPackage();
    void sendPortRPMPackage();
    void sendStbRPMPackage();
    void sendSpeedPackage();
    void sendTripPackage();
    void sendPortMotorTempPackage();
    void sendStbMotorTempPackage();
    void sendBatInfoPackage();
    void sendPositionPackage();
    void sendDepthPositionPackage();


    QByteArray m_PortRPMbytes;
    QByteArray m_PortVoltagebytes;
    QByteArray m_PortCurrentbytes;

    QByteArray m_StbRPMbytes;
    QByteArray m_StbVoltagebytes;
    QByteArray m_StbCurrentbytes;

    QByteArray m_Speed;

    QByteArray m_TimeToEmpty;
    QByteArray m_DistToEmpty;

    QByteArray m_StbMotorTemp;
    QByteArray m_StbInverterTemp;

    QByteArray m_PortMotorTemp;
    QByteArray m_PortInverterTemp;

    QByteArray m_HiCellTemp;
    QByteArray m_LoCellTemp;
    QByteArray m_SOC;
    QByteArray m_TimeToFull;

    QByteArray m_BatVoltage;
    QByteArray m_BatCurrent;

    QByteArray m_Lat;
    QByteArray m_Lon;

    QByteArray m_HiCellVoltage;
    QByteArray m_LoCellVoltage;

    QByteArray m_ChargerTemp;
    QByteArray m_ChargerVoltage;
    QByteArray m_ChargerCurrent;

    QByteArray m_Depth;

    uint8_t tripPackageCounter{0x00};
    uint8_t tripPackageCounter2{0x00};
    uint8_t tripPackageCounter3{0x00};
    uint8_t tripPackageCounter4{0x00};
    uint8_t tripPackageCounter5{0x00};

};

#endif // CANHANDLER_H

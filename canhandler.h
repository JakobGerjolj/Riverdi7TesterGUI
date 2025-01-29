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

    void toggleSendingDCDCMessage();

    void toggleSendingVCUMessage();

    void toggleSendingCharger2Message();

    void toggleSendingCharger3Message();

    void toggleSendingPortMotorStatus();

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
    void setBMSStatus(uint8_t value);

    void setChargerTemp(int16_t value);
    void setChargerVoltage(uint16_t value);
    void setChargerCurrent(int16_t);
    void setChargerStatus(uint8_t status);

    void setCharger2VoltageL1(uint16_t value);
    void setCharger2VoltageL2(uint16_t value);
    void setCharger2VoltageL3(uint16_t value);
    void setCharger2Temperature1(uint8_t value);

    void setCharger3CurrentL1(int16_t value);
    void setCharger3CurrentL2(int16_t value);
    void setCharger3CurrentL3(int16_t value);

    void setDepth(uint32_t);

    void setDCDCStatus(int status);
    void setDCDCVoltage(uint16_t value);
    void setDCDCCurrent(int16_t value);

    void setMotorStatus(int status);

    void setVCUStatus(int status);

    void sendAlarmPackage(QByteArray data);
    void sendAlarmNotActivePackage(uint8_t type, uint16_t id);

    void sendMotorDirectionLeft();
    void sendMotorDirectionRight();

    void sendMotorContinousRPM(uint16_t rpm);
    void sendMotorPeakRPM(uint16_t rpm);

    void sendLeverNFCEnabled();
    void sendLeverNFCDisabled();





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
    bool areWeSendingDCDCInfo{false};
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
    bool areWeSendingVCUMsg{false};
    bool areWeSendingChargerMsg2{false};
    bool areWeSendingChargerMsg3{false};
    bool areWeSendingPortMotorStatus{false};

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
    void sendDCDCInfoPackage();
    void sendVCUPackage();
    void sendChargerInfo2();
    void sendChargerInfo3();
    void sendPortMotorInfo();

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
    QByteArray m_BMSStatus;

    QByteArray m_ChargerTemp;
    QByteArray m_ChargerVoltage;
    QByteArray m_ChargerCurrent;
    QByteArray m_ChargerStatus;

    QByteArray m_Depth;

    QByteArray m_DCDCStatus;
    QByteArray m_DCDCVoltage;
    QByteArray m_DCDCCurrent;

    QByteArray m_VCUStatus;

    QByteArray m_PortMotorStatus;

    QByteArray m_ChargerInputVoltageL1;
    QByteArray m_ChargerInputVoltageL2;
    QByteArray m_ChargerInputVoltageL3;
    QByteArray m_ChargerTemperature1;

    QByteArray m_ChargerInputCurrentL1;
    QByteArray m_ChargerInputCurrentL2;
    QByteArray m_ChargerInputCurrentL3;

    uint8_t tripPackageCounter{0x00};
    uint8_t tripPackageCounter2{0x00};
    uint8_t tripPackageCounter3{0x00};
    uint8_t tripPackageCounter4{0x00};
    uint8_t tripPackageCounter5{0x00};

};

#endif // CANHANDLER_H

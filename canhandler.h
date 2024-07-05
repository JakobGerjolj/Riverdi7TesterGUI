#ifndef CANHANDLER_H
#define CANHANDLER_H

#include <QObject>
#include <QCanBusDevice>
#include <QCanBusDevice>
#include <QCanBus>
#include <QDebug>
#include <QTimer>
#include <QByteArray>

class CanHandler : public QObject
{
    Q_OBJECT
public:
    explicit CanHandler(QObject *parent = nullptr);
    ~CanHandler();
    void setPortRPM(uint16_t rpm);
    void setPortVoltage(uint16_t voltage);
    void setPortCurrent(uint16_t current);

    void toggleSendingHiCellTemp();

    void toggleSendingStbTempMessage();

    void toggleSendingPortTempMessage();

    void toggleSendingPortMessage();

    void toggleSendingStbMessage();

    void toggleSendingSpeedMessage();

    void toggleSendingTripMessage();

    void setStbRPM(uint16_t rpm);
    void setStbVoltage(uint16_t voltage);
    void setStbCurrent(uint16_t current);

    void setDistToEmpty(uint32_t dist);
    void setTimeToEmpty(uint32_t time);

    void setStbMotorTemp(uint16_t temp);
    void setPortMotorTemp(uint16_t temp);

    void setSpeed(uint16_t speed);

    void setHiCellTemp(uint16_t temp);
signals:

private:
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

    void sendHiCellPackage();
    void sendPortRPMPackage();
    void sendStbRPMPackage();
    void sendSpeedPackage();
    void sendTripPackage();
    void sendPortMotorTempPackage();
    void sendStbMotorTempPackage();

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
    QByteArray m_PortMotorTemp;

    QByteArray m_HiCellTemp;
    uint8_t tripPackageCounter{0x00};
    uint8_t tripPackageCounter2{0x00};
    uint8_t tripPackageCounter3{0x00};
    uint8_t tripPackageCounter4{0x00};

};

#endif // CANHANDLER_H

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
signals:

private:
    void startCAN();
    void readAndProcessCANpodatke();
    QCanBusDevice *canDevice;


    void sendPortRPMPackage();


    QByteArray m_PortRPMbytes;
    QByteArray m_PortVoltagebytes;
    QByteArray m_PortCurrentbytes;

};

#endif // CANHANDLER_H

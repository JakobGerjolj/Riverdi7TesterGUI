#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTextStream>
#include "canhandler.h"
#include <QThread>
#include <chrono>
#include <unistd.h>
#include <QtMath>// For sleep
#include "connectdialog.h"
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_rpmPortSlider_sliderMoved(int position);

    void on_voltagePort_sliderMoved(int position);

    void on_currentPort_sliderMoved(int position);

    void on_pushButton_clicked();

    void on_rpmStarboardSlider_sliderMoved(int position);

    void on_rpmStarboardVoltage_sliderMoved(int position);

    void on_CurrentStarboardSlider_sliderMoved(int position);

    void on_pushButton_2_clicked();

    void on_speedSlider_sliderMoved(int position);

    void on_pushButton_3_clicked();

    void on_speedSlider_2_sliderMoved(int position);

    void on_pushButton_4_clicked();

    void on_speedSlider_3_sliderMoved(int position);

    void on_speedSlider_5_sliderMoved(int position);

    void on_speedSlider_4_sliderMoved(int position);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_speedSlider_6_sliderMoved(int position);

    void on_pushButton_7_clicked();

    void on_speedSlider_7_sliderMoved(int position);

    void on_speedSlider_8_sliderMoved(int position);

    void on_speedSlider_9_sliderMoved(int position);

    void on_speedSlider_10_sliderMoved(int position);

    void on_pushButton_8_clicked();

    void on_speedSlider_11_sliderMoved(int position);

    void on_speedSlider_12_sliderMoved(int position);

    void on_speedSlider_13_sliderMoved(int position);

    void on_speedSlider_14_sliderMoved(int position);

    void on_pushButton_9_clicked();

    void on_speedSlider_16_sliderMoved(int position);

    void on_speedSlider_17_sliderMoved(int position);

    void on_pushButton_11_clicked();

    void on_rpmStarboardSlider_2_sliderMoved(int position);

    void on_pushButton_12_clicked();

    void on_rpmStarboardVoltage_2_sliderMoved(int position);

    void on_CurrentStarboardSlider_2_sliderMoved(int position);

    void on_speedSlider_18_sliderMoved(int position);

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_speedSlider_19_sliderMoved(int position);

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();

    void on_speedSlider_20_sliderMoved(int position);

    void on_speedSlider_21_sliderMoved(int position);

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_pushButton_19_clicked();

    void on_rpmStarboardSlider_3_sliderMoved(int position);

    void on_rpmStarboardVoltage_3_sliderMoved(int position);

    void on_CurrentStarboardSlider_3_sliderMoved(int position);

    void on_CurrentStarboardSlider_4_sliderMoved(int position);

    void on_pushButton_20_clicked();

    void on_rpmStarboardSlider_4_sliderMoved(int position);

    void on_rpmStarboardVoltage_4_sliderMoved(int position);

    void on_CurrentStarboardSlider_5_sliderMoved(int position);

    void on_pushButton_21_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_9_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_15_clicked();

    void on_radioButton_16_clicked();

    void on_radioButton_17_clicked();

    void on_radioButton_18_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_12_clicked();

    void on_radioButton_13_clicked();

    void on_radioButton_14_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_speedSlider_22_sliderMoved(int position);

    void on_pushButton_24_clicked();

    void on_speedSlider_23_sliderMoved(int position);

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void moveAllSliders();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_rpmPortSlider_valueChanged(int value);

    void on_voltagePort_valueChanged(int value);

    void on_currentPort_valueChanged(int value);

    void on_rpmStarboardSlider_valueChanged(int value);

    void on_rpmStarboardVoltage_valueChanged(int value);

    void on_CurrentStarboardSlider_valueChanged(int value);

    void on_speedSlider_valueChanged(int value);

    void on_speedSlider_2_valueChanged(int value);

    void on_speedSlider_3_windowIconTextChanged(const QString &iconText);

    void on_speedSlider_3_valueChanged(int value);

    void on_speedSlider_5_valueChanged(int value);

    void on_speedSlider_8_valueChanged(int value);

    void on_speedSlider_6_valueChanged(int value);

    void on_speedSlider_12_valueChanged(int value);

    void on_speedSlider_7_valueChanged(int value);

    void on_speedSlider_18_valueChanged(int value);

    void on_speedSlider_4_valueChanged(int value);

    void on_speedSlider_9_valueChanged(int value);

    void on_speedSlider_10_valueChanged(int value);

    void on_speedSlider_11_valueChanged(int value);

    void on_speedSlider_19_valueChanged(int value);

    void on_speedSlider_13_valueChanged(int value);

    void on_speedSlider_14_valueChanged(int value);

    void on_speedSlider_15_sliderMoved(int position);

    void on_speedSlider_16_valueChanged(int value);

    void on_speedSlider_17_valueChanged(int value);

    void on_rpmStarboardVoltage_2_valueChanged(int value);

    void on_CurrentStarboardSlider_2_valueChanged(int value);

    void on_rpmStarboardSlider_3_valueChanged(int value);

    void on_rpmStarboardVoltage_3_valueChanged(int value);

    void on_CurrentStarboardSlider_3_valueChanged(int value);

    void on_CurrentStarboardSlider_4_valueChanged(int value);

    void on_rpmStarboardSlider_4_valueChanged(int value);

    void on_rpmStarboardVoltage_4_valueChanged(int value);

    void on_CurrentStarboardSlider_5_valueChanged(int value);

    void on_speedSlider_20_valueChanged(int value);

    void on_speedSlider_21_valueChanged(int value);

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_radioButton_19_clicked();

    void on_radioButton_21_clicked();

    void on_radioButton_20_clicked();

    void on_radioButton_22_clicked();

    void on_radioButton_23_clicked();

    void on_pushButton_34_clicked();

    void on_radioButton_24_clicked();

    void on_radioButton_25_clicked();

    void on_pushButton_35_clicked();

    void on_radioButton_26_clicked();

    void on_radioButton_27_clicked();

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_6_stateChanged(int arg1);

    void on_checkBox_7_stateChanged(int arg1);

    void on_checkBox_8_stateChanged(int arg1);

    void on_checkBox_4_clicked();

    void on_checkBox_9_stateChanged(int arg1);

    void on_checkBox_10_stateChanged(int arg1);

    void on_pushButton_36_clicked();

    void on_radioButton_28_clicked();

    void on_speedSlider_24_valueChanged(int value);

    void on_rpmStarboardVoltage_actionTriggered(int action);

    void on_CurrentStarboardSlider_6_valueChanged(int value);

    void on_pushButton_37_clicked();

    void on_CurrentStarboardSlider_6_sliderMoved(int position);

    void on_pushButton_38_clicked();

    void on_pushButton_39_clicked();

    void on_checkBox_11_stateChanged(int arg1);

    void on_checkBox_12_stateChanged(int arg1);

    void on_checkBox_13_stateChanged(int arg1);

    void on_speedSlider_25_valueChanged(int value);

    void on_actionConnect_triggered();

    void on_speedSlider_26_valueChanged(int value);

    void on_speedSlider_27_valueChanged(int value);

private:

    QString getTimeOfDayFromSeconds(int seconds);

    int sliderMover{0};

    QTimer *timer;

    bool areWeSendingDCDCData{false};
    bool areWeSendingDepthData{false};
    bool areWeSendingChargerInfo{false};
    bool areWeSendingCellVoltage{false};
    bool areWeSendingPosition{false};
    bool areWeSendingBatInfo{false};
    bool areWeSendingHiCellTemp{false};
    bool areWeSendingSpeedMsg{false};
    bool areWeSendingStbMsg{false};
    bool areWeSendingPortMsg{false};
    bool areWeSendingTripMsg{false};
    bool areWeSendingPortMotorTemp{false};
    bool areWeSendingStbMotorTemp{false};
    bool areWeSendingVCU{false};
    bool areWeSendingChargerInfo2{false};
    bool areWeSendingChargerInfo3{false};
    bool areWeSendingPortMotorInfo{false};
    bool areWeSendingThrottle1Status{false};
    bool areWeSendingThrottle2Status{false};
    bool areWeSendingRudderAngle{false};
    bool areWeSendingConsumption{false};
    bool areWeSendingWaterTemp{false};

    QString canPlugin{"SavvyCAN"};
    QString portName{"COM0"};

    QSettings* settings;

    CanHandler* m_CanHandler;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

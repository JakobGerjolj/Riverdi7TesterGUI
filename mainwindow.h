#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTextStream>
#include "canhandler.h"
#include <QThread>
#include <chrono>
#include <unistd.h>  // For sleep

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

private:
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
    CanHandler* m_CanHandler;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

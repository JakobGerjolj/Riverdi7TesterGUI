#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "canhandler.h"

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

private:
    bool areWeSendingHiCellTemp{false};
    bool areWeSendingSpeedMsg{false};
    bool areWeSendingStbMsg{false};
    bool areWeSendingPortMsg{false};
    bool areWeSendingTripMsg{false};
    bool areWeSendingPortMotorTemp{false};
    bool areWeSendingStbMotorTemp{false};
    CanHandler* m_CanHandler;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

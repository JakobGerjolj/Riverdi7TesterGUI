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

private:
    CanHandler* m_CanHandler;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

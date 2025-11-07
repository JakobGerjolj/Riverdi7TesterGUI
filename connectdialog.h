#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>

#include <QSerialPortInfo>

namespace Ui {
class Connectdialog;
}

class Connectdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Connectdialog(QWidget *parent = nullptr);
    ~Connectdialog();

    QString getPlugin(){ return plugin; }
    QString getPort(){ return port; }

private slots:
    void on_pluginListBox_currentTextChanged(const QString &arg1);



    void on_interfaceListBox_currentTextChanged(const QString &arg1);

private:

    QString plugin{"savvyCan"};
    QString port{"COM0"};



    Ui::Connectdialog *ui;
};

#endif // CONNECTDIALOG_H

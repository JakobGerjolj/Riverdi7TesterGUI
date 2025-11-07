#include "connectdialog.h"
#include "ui_connectdialog.h"

Connectdialog::Connectdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Connectdialog)
{
    ui->setupUi(this);

    ui->pluginListBox->addItem("SavvyCAN");
    ui->pluginListBox->addItem("PeakCAN");

    //select persistant item and then add the ports if it is savvy


    // foreach (const QSerialPortInfo &port, QSerialPortInfo::availablePorts()) {
    //     ui->interfaceListBox->addItem(port.portName());
    // }

    // if(QSerialPortInfo::availablePorts().empty()){

    //     ui->interfaceListBox->addItem("No ports available");
    //     ui->interfaceListBox->setEnabled(false);

    // }else{

    //     ui->interfaceListBox->setEnabled(true);

    // }

    // ui ->interfaceListBox
    //add all ports here, but if it is peak,we add all usbs, if it is savvy we add all COMs



}

Connectdialog::~Connectdialog()
{
    delete ui;
}

void Connectdialog::on_pluginListBox_currentTextChanged(const QString &arg1)
{

    if(arg1 == "PeakCAN"){ //when the combo box changes

        plugin = arg1;
        port = "usb0";

        ui -> interfaceListBox ->clear();
        ui -> interfaceListBox ->addItem("usb0");
        ui -> interfaceListBox ->setEnabled(false);//disable selection on port and just select usb0, in the future we can handle multiple peak cans if the need arises

    }else if(arg1 == "SavvyCAN"){

        plugin = "SavvyCAN";

        ui ->interfaceListBox->clear();

        foreach (const QSerialPortInfo &port, QSerialPortInfo::availablePorts()) {

            ui->interfaceListBox->addItem(port.portName());

        }

        if(QSerialPortInfo::availablePorts().empty()){

            ui->interfaceListBox->addItem("No ports available");
            ui->interfaceListBox->setEnabled(false);

        }else{
            ui->interfaceListBox->setEnabled(true);

        }

    }

}


void Connectdialog::on_interfaceListBox_currentTextChanged(const QString &arg1)
{

    port = arg1;

}


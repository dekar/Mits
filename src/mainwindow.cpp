#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mitshpacket.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>
#include <QMessageBox>



MainWindow::MainWindow(PacketSender *packetSender, QWidget *parent)

    :QMainWindow(parent)
      , ui(new Ui::MainWindow)
      ,sender(packetSender)

{
    ui->setupUi(this);
    ui->labelCOM->setText("Com port: "+sender->COM);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    uint8_t address = ui->spinAddress->value();
    uint8_t cmd = ui->lineCMD->text().toInt(nullptr,16);
    uint8_t dataNo = ui->lineDataNo->text().toInt(nullptr,16);

    MitshPacket mp = MitshPacket(address, cmd, dataNo);

    mp.pushDataValue(
        ui->lineData->text().toULongLong(nullptr,16),
        ui->comboBox->currentText().toUInt()/2);
    ui->labelHEX->setText("PKG: "+mp.returnBytes());
    QByteArray tmp = sender->sendPacket(mp);
    ui->lineAnswer->setText(tmp);
}


void MainWindow::on_button1EA5_clicked()
{
    ui->lineData->setText("1EA5");
    ui->comboBox->setCurrentText("4");
}

void MainWindow::on_lineData_textChanged(const QString &arg1)
{
    if(arg1.size()>0)
        ui->comboBox->setCurrentText("4");
    if(arg1.size()>4)
       ui->comboBox->setCurrentText("8");
    if(arg1.size()>8)
        ui->comboBox->setCurrentText("12");
    if(arg1.size()>16)
       ui->comboBox->setCurrentText("16");
}



#include "packetsender.h"
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QThread>
#include <QTextStream>

PacketSender::PacketSender()
{

}

QByteArray PacketSender::sendPacket(MitshPacket &p)
{
    if(COM.isEmpty())
    {
        error("Serial port not founded!");
        return QByteArray();
    }
    QSerialPort *serial = new QSerialPort(COM);
    serial->setBaudRate(115200);
    serial->setDataBits(QSerialPort::Data8);

    serial->setParity(QSerialPort::EvenParity);

    serial->setStopBits(QSerialPort::OneStop);
    //We will chose the Flow controls
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (!serial->open(QIODevice::ReadWrite))
    {
        error("Can't open serial port: "+ serial->errorString());
        return QByteArray();
    }
    serial->write(p.returnBytes());
    serial->flush();
    serial->waitForReadyRead(300);
    serial->thread()->usleep(100*1000);
    QByteArray tmp = serial->readAll();
    serial->close();
    delete serial;
    return tmp;
}

bool PacketSender::findCom(QString name)
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : serialPortInfos) {
        /*qDebug() << "\n"
                 << "Port:" << portInfo.portName() << "\n"
                 << "Location:" << portInfo.systemLocation() << "\n"
                 << "Description:" << portInfo.description() << "\n"
                 << "Manufacturer:" << portInfo.manufacturer() << "\n"
                 << "Serial number:" << portInfo.serialNumber() << "\n"
                 << "Vendor Identifier:"
                 << (portInfo.hasVendorIdentifier()
                         ? QByteArray::number(portInfo.vendorIdentifier(), 16)
                         : QByteArray()) << "\n"
                 << "Product Identifier:"
                 << (portInfo.hasProductIdentifier()
                         ? QByteArray::number(portInfo.productIdentifier(), 16)
                         : QByteArray());*/
        if (portInfo.description() == name)
        {
            this->COM = portInfo.portName();
            return true;
        }
    }
    return false;
}

void PacketSender::error(QString message)
{
    message = message.simplified()+"\n";
    QTextStream err(stderr);
    err<< message;
    err.flush();
}


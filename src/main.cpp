
#include "packetsender.h"
#include "clirunner.h"
#include "mainwindow.h"


#include <QApplication>
#include <QDebug>

const QString USB_description = QString("USB-SERIAL CH340");

int main(int argc, char *argv[])
{
    PacketSender ps;
    if(!ps.findCom(USB_description))
        ps.error("No port with description \"" + USB_description + "\"!");
    CliRunner cli(&ps);
    if(cli.tryCli())
        return cli.errorCode;
    QApplication a(argc, argv);
    MainWindow w(&ps);
    w.show();
    return a.exec();
}

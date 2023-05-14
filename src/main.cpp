#include "mainwindow.h"
#include "mitshpacket.h"

#include <QApplication>
#include <QDebug>

bool checkArg(QString s, int numBytes)
{
    if(s.size() > (numBytes*2))
        return false;
    bool ok;
    s.toUInt(&ok,16);
    return ok;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
/*    if (a.arguments().size()>2)
    {
        bool ok =
            checkArg(a.arguments()[1],1) &&
            checkArg(a.arguments()[2],1)  &&
            checkArg(a.arguments()[3],1);
        if(ok)
        {
            MitshPacket::generate(a.arguments()[1].nu,0x05,0x02);
        }
    }
    MitshPacket mp = MitshPacket::generate(01,0x05,0x02);
    mp.pushDataValue(0x11223344AABBCCDD,8);
    QByteArray mifk = mp.returnBytes();
    qDebug()<<mp.returnBytes();*/
    return a.exec();
}

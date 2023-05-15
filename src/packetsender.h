
#ifndef PACKETSENDER_H
#define PACKETSENDER_H
#include "mitshpacket.h"

#include <QString>



class PacketSender
{
public:
    PacketSender();
    QByteArray sendPacket(MitshPacket &p);
    bool findCom(QString name);
    void error(QString message);
    QString COM;
};

#endif // PACKETSENDER_H

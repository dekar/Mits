
#ifndef PACKETSENDER_H
#define PACKETSENDER_H
#include "mitshpacket.h"

#include <QString>



class PacketSender
{
public:
    PacketSender();
    QByteArray sendPacket(MitshPacket &p);
    void findCom();
    QString COM;
};

#endif // PACKETSENDER_H

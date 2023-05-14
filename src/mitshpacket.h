#ifndef MITSHPACKET_H
#define MITSHPACKET_H

#include <QByteArray>
#include <stdint.h>



class MitshPacket
{
private:
    uint8_t address;

    uint8_t command;
    uint8_t dataNo;

    uint8_t data[16];
    uint8_t dataSize;

    uint8_t crcByte;

    void calcCRC();
    uint16_t crc(uint8_t byte);
    QByteArray toHex(uint8_t byte);
    MitshPacket();
public:
    static MitshPacket generate(uint8_t address, uint8_t command, uint8_t dataNo);
    void pushData(uint8_t byte);
    void pushDataValue(uint64_t byte, uint8_t byteSize);
    QByteArray returnBytes();
};

#endif // MITSHPACKET_H

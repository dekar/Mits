#include "mitshpacket.h"
const uint8_t hexcodes[]= "0123456789ABCDEF";
const uint8_t SOX = 1;
const uint8_t STX = 2;
const uint8_t ETX = 3;
const uint8_t EOT = 4;
void MitshPacket::calcCRC()
{
    uint16_t crcNum = address + '0' + crc(command)+ STX +  crc(dataNo) + ETX;
    for(int i=0;i<dataSize;i++)
        crcNum += crc(data[i]);
    crcByte = crcNum &0xFF;
}

uint16_t MitshPacket::crc(uint8_t byte)
{
    uint16_t res = hexcodes[(byte & 0x0F)];
    res = res + hexcodes[byte >>4];
    return res;
}

QByteArray MitshPacket::toHex(uint8_t byte)
{
    QByteArray res;
    res.append(hexcodes[byte >>4]);
    res.append(hexcodes[(byte & 0x0F)]);
    return res;
}

MitshPacket::MitshPacket()
    :dataSize (0)
{

}

/*MitshPacket MitshPacket::generate(uint8_t address, uint8_t command, uint8_t dataNo)
{
    MitshPacket res;
    res.address = address;
    res.command = command;
    res.dataNo = dataNo;
    res.calcCRC();
    return res;
}*/

MitshPacket::MitshPacket(uint8_t address, uint8_t command, uint8_t dataNo)
    :address(address),command(command),dataNo(dataNo)
{
    calcCRC();
}

void MitshPacket::pushData(uint8_t byte)
{
    if(dataSize == 16)
        return;
    data[dataSize] = byte;
    dataSize++;
    calcCRC();
}

void MitshPacket::pushDataValue(uint64_t byte, uint8_t byteSize)
{
    for(int i=byteSize;i != 0;i--)
    {
        uint8_t shift = (i-1)*8;
        uint64_t mask = ((uint64_t)0xFF)<<(shift);
        uint64_t num = byte & mask;
        uint8_t c = num >> (shift);
        pushData(c);
    }
}

QByteArray MitshPacket::returnBytes()
{
    QByteArray res;
    res.append(SOX);
    res.append(address + '0'    );
    res.append(toHex(command));
    res.append(STX);
    res.append(toHex(dataNo));
    for(int i=0;i<dataSize;i++)
        res.append(toHex(data[i]));
    res.append(ETX);
    res.append(toHex(crcByte));
    return res;

}


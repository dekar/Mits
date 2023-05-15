#ifndef CLIRUNNER_H
#define CLIRUNNER_H
#include "packetsender.h"


class CliRunner
{
private:

    PacketSender *ps;



public:
    CliRunner(PacketSender *sender);
    bool tryCli();
    int errorCode;
};

#endif // CLIRUNNER_H

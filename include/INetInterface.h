#ifndef INETINTERFACE_H
#define INETINTERFACE_H

#include <cstring>
#include <sys/socket.h>
#include <netdb.h>

class INetInterface
{
protected:
  int sock;
};

#endif

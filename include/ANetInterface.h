#ifndef INETINTERFACE_H
#define INETINTERFACE_H

#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include "CircularBuffer.h"

class ANetInterface
{
public:
  ANetInterface();
  virtual ~ANetInterface();
  void Init();
  int Send(std::string &msg, struct sockaddr_in addr);
  int Receive(std::string &msg, struct sockaddr_in addr);
protected:
  int socketfd;
  bool initialized;
  CircularBuffer<unsigned char> buf;
};

#endif

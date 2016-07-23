#ifndef INETINTERFACE_H
#define INETINTERFACE_H

#include <cstring>
#include <string>
#include <sys/socket.h>
#include <netdb.h>
#include "CircularBuffer.h"

class ANetInterface
{
public:
  ANetInterface();
  virtual ~ANetInterface();
  void Init();
  std::string Receive();
  void Send(std::string &to_send);
protected:
  int socketfd;
  CircularBuffer<unsigned char> buf;
};

#endif

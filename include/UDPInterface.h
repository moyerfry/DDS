#ifndef UDPINTERFACE_H
#define UDPINTERFACE_H

#include "ANetInterface.h"

class UDPInterface : ANetInterface
{
public:
  UDPInterface();
  virtual ~UDPInterface();
  virtual void Init();
  virtual int Send(std::string &msg, struct sockaddr_in addr);
  virtual int Receive(std::string &msg, struct sockaddr_in addr);
protected:
};

#endif

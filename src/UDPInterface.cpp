#include "UDPInterface.h"
#include <cstdlib>
#include <unistd.h>

#define BUFFER_LENGTH 256

UDPInterface::UDPInterface()
{
  //This is for a UDP Socket
  socketfd = socket(AF_INET, SOCK_DGRAM, 0);
  Init();
}

UDPInterface::~UDPInterface()
{
  if(initialized)
  {
    close(socketfd);
  }
}

void UDPInterface::Init()
{
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family=AF_INET;
  addr.sin_addr.s_addr=htonl(INADDR_ANY);
  addr.sin_port=htons(0);

  if(bind(socketfd,( struct sockaddr *) &addr, sizeof(addr))<0)
  {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  initialized = true;
}

int UDPInterface::Send(std::string &msg, struct sockaddr_in addr)
{
  int datagramLength = strlen(msg.c_str());
  int ret = sendto(socketfd, msg.c_str(), datagramLength, 0, ( struct sockaddr *) &addr, sizeof(addr));
  return ret;
}

int UDPInterface::Receive(std::string &msg, struct sockaddr_in addr)
{
  char buf[BUFFER_LENGTH];
  socklen_t addrlen = sizeof(addr);
  recvfrom(socketfd, buf, BUFFER_LENGTH, 0, ( struct sockaddr *) &addr, &addrlen);
}

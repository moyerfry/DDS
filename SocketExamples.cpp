#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <cstdio>
#include <cstdlib>
#include <string>

int main(int argc, char * argv[])
{
  int status;
  struct addrinfo host_info;       // The struct that getaddrinfo() fills up with data.
  struct addrinfo *host_info_list; // Pointer to the to the linked list of host_info's.

  // The MAN page of getaddrinfo() states "All  the other fields in the structure pointed
  // to by hints must contain either 0 or a null pointer, as appropriate." When a struct
  // is created in C++, it will be given a block of memory. This memory is not necessary
  // empty. Therefor we use the memset function to make sure all fields are NULL.
  memset(&host_info, 0, sizeof host_info);

  printf("Setting up the structs...\n");

  host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
  host_info.ai_socktype = SOCK_STREAM; // Use SOCK_STREAM for TCP or SOCK_DGRAM for UDP.

  // Now fill up the linked list of host_info structs with google's address information.
  status = getaddrinfo("www.google.com", "80", &host_info, &host_info_list);
  // getaddrinfo returns 0 on succes, or some other value when an error occured.
  // (translated into human readable text by the gai_gai_strerror function).
  if (status != 0)  printf("getaddrinfo error %s\n", gai_strerror(status));

  printf("Creating a socket...\n");
  int socketfd ; // The socket descripter
  socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,
  host_info_list->ai_protocol);
  if (socketfd == -1)  printf("socket error\n");

  printf("Connecting...\n");
  status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
  if (status == -1)  printf("connect error\n");

  printf("sending message...\n");
  std::string msg = "GET / HTTP/1.1\nhost: www.google.com\n\n";
  int len;
  ssize_t bytes_sent;
  len = strlen(msg.c_str());
  bytes_sent = send(socketfd, msg.c_str(), len, 0);

  printf("Waiting to recieve data...\n");
  ssize_t bytes_recieved;
  char incoming_data_buffer[1000];
  bytes_recieved = recv(socketfd, incoming_data_buffer,1000, 0);
  // If no data arrives, the program will just wait here until some data arrives.
  if (bytes_recieved == 0) printf("host shut down.\n");
  if (bytes_recieved == -1)printf("recieve error!\n");
  printf("%i bytes recieved :", (int)bytes_recieved);
  printf("%s\n", incoming_data_buffer);
}

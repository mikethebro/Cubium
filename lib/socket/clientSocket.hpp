#ifndef CLIENT_SOCKET_HPP
#define CLIENT_SOCKET_HPP

#include <netinet/in.h>  // for sockaddr_in
#include <stdint.h>      // for uint32_t
#include <sys/types.h>   // for ssize_t
#include <functional>    // for std::function

/* Everything we need for socket communication bundled up into a struct */
typedef struct
{
  uint32_t sock;
  uint32_t nBytesRecv;
  uint32_t length;
  struct sockaddr_in server;
  struct sockaddr_in from;
  struct hostent * hp;
  char buf[256];
} cubiumClientSocket_t;

/* Open a socket on the given port. Returns socket info. */
cubiumClientSocket_t clientSocket_openSocket(uint16_t port);

/* Connect to a UDP server */
void clientSocket_serverConnect(cubiumClientSocket_t * ,   /* Socket that server is listening through */
                                  void* hello,   /* Hello sent to server */
                                   size_t len,   /* Length of hello */
std::function<void(cubiumClientSocket_t *)> func /* Called when ack is received */
                                );

/* Send a message through the socket */ 
ssize_t clientSocket_send(const void * msg,         /* The message buffer */
                          size_t len,               /* Message length */
                          cubiumClientSocket_t * s  /* Socket */
                          );

#endif

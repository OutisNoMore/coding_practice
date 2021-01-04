#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
  struct addrinfo hints, *result;
  int sockfd;
  int status;
  int ip = 0;
  char subnet[3];
  char strIp[13];

  if(argc != 2){
    fprintf(stderr, "usage: ./netScanner subnet\n");
    return 1;
  }

  memset(&hints, 0, sizeof hints);
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_family = AF_UNSPEC;
  
//  while(ip != 256){
  //  strcpy(strIp, argv[1]);
    //sprintf(subnet, "%d", ip);
    //strcat(strIp, subnet);

    if((status = getaddrinfo(argv[1], "80", &hints, &result) != 0)){
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
      return 1;
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if(connect(sockfd, result->ai_addr, result->ai_addrlen) == 0){
      printf("Host %s is up\n", argv[1]);
    }

    close(sockfd);

  //  ip++;
//  }

  freeaddrinfo(result);

  return 0;
}

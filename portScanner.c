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
  int status;
  int sockfd;
  int port = 0;
  char sPort[6];
  time_t rawtime;
  struct tm * timeinfo;

  if(argc != 2){
    fprintf(stderr, "usage: net hostname\n");
    return 1;
  }
  
  memset(&hints, 0, sizeof hints);
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_family = AF_UNSPEC;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("--------------------------------------------------\n");
  printf("scanning target: %s\n", argv[1]);
  printf("time started: %s", asctime(timeinfo));
  printf("--------------------------------------------------\n\n");

  clock_t begin = clock();
  while(port != 65536){
    sprintf(sPort, "%d", port);
    if((status = getaddrinfo(argv[1], sPort, &hints, &result)) != 0){
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
      return 2;
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if(connect(sockfd, result->ai_addr, result->ai_addrlen) == 0){
      printf("port %d is open\n", port);
    } 
    close(sockfd);

    port++;
  }

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("\n--------------------------------------------------\n");
  printf("time ended: %s", asctime(timeinfo));
  printf("total time elapsed: %f seconds\n", (double)(clock()-begin)/CLOCKS_PER_SEC);
  printf("--------------------------------------------------\n");

  freeaddrinfo(result);

  return 0;
}

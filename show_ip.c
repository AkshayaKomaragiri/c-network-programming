#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
    // argc is the argument count
    struct addrinfo hints, *res, *p;
    char ipstr[INET6_ADDRSTRLEN];
    int status;

    if (argc != 2){
        fprintf(stderr, "usage: show ip hostname");
        return 1;
    }
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((status = getaddrinfo(argv[0], "3490", &hints, &res)) != 0){
        printf("gai error: %s", gai_strerror(status));
        exit(1);
    }

    printf("IP addresses for %s: \n\n", argv[1]);


}
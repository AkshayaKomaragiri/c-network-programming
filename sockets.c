
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#define BACKLOG 10
int main(){
    int s, new_fd; 
    socklen_t addr_size;
    struct sockaddr_storage their_addr;
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; 
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;    

getaddrinfo(NULL, "3490", &hints, &res);
    s = socket(res->ai_family, res->ai_socktype,res->ai_protocol);
    bind(s, res->ai_addr, res->ai_addrlen);
    listen(s, BACKLOG);

    addr_size = sizeof their_addr;
    new_fd = accept(s, (struct sockaddr *)&their_addr, &addr_size);
}


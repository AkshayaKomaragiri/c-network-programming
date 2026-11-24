
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(){
    int s; 
    struct addrinfo hints, *res;
    getaddrinfo("www.example.com", "http", &hints, &res);
    s = socket(res->ai_family, res->ai_socktype,res->ai_protocol);
}


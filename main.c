//
// Created by sean on 4/15/19.
//

//SSL-Server.c
#include <errno.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <resolv.h>
#include "openssl/ssl.h"
#include "openssl/err.h"
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <jmorecfg.h>
#include <memory.h>
#include <stdlib.h>
#include <errno.h>
#include <zconf.h>
#include <time.h>
#include <openssl/sha.h>



int boardPositionsArray[12];
char boardPos[12];
unsigned char hash[SHA256_DIGEST_LENGTH];

void hasher () {

    size_t length = strlen(boardPos);
    SHA256(boardPos, length, hash);
    int i;
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
        printf("%02x", hash[i]);
    putchar('\n');

}

void hasherTest () {


    char data[] = "012345678912";
    size_t length = strlen(data);
    ///size_t length = strlen(boardPos);
    SHA256(data, length, hash);
    int i;
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
        printf("%02x", hash[i]);
    putchar('\n');

}

void setBoardPositions(){

    for (int i=0; i<12; i++)
    { boardPos[i] = boardPositionsArray[i] + '0';}

}


void printBoardPos(){

    printf("\n");
    for ( int i = 0 ; i < 12 ; i ++ )
    {
        printf("%d", boardPositionsArray[i]);
    }

    printf("\n%s", boardPos);
}

int main() {
    printf("Hello, World!\n");
    /// populate board with values 012345678912 ///
    for ( int i = 0; i < 10; i ++)
    { boardPositionsArray[i] = i;}
    boardPositionsArray[10] = 1;
    boardPositionsArray[11] = 2;
    setBoardPositions();
    printBoardPos();
    printf("\n");
    hasher();
    hasherTest();

    return 0;
}
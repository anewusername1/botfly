#ifndef BOT_H
#define BOT_H

#include <stdlib.h>
#define BUFSIZE 512

struct irc_data {
    char nick[32];
    char user[32];
    char server[64];
    char chan[32];
    char message[512];
    int is_ready;
};

void die(const char*,int);
void parse_data(char*,struct irc_data**);
int  sayc(int,const char*,const char*, ...);
void usage();
#endif

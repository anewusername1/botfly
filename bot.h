/*
 *  bot.h
 *  testing
 *
 *  Created by MoneyDesktop on 3/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#define BUFSIZE 512
#define PSYCHO  NULL

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

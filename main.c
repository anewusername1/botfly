/*
 *  bot.c
 *  testing
 *
 *  Created by MoneyDesktop on 3/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "bot.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#define BUFSIZE 512
#define PSYCHO  NULL

/***********************
 * argv[1] -> host
 * argv[2] -> port
 * argv[3] -> chan
 * argv[4] -> nick
 * argv[5] -> user
 ***********************/

struct irc_data { 
    char nick[32];
    char user[32];
    char host[64];
    char chan[32];
    char message[512];
    int is_ready;
};

void die(const char*,int);
void parse_data(char*,struct irc_data**);
int  sayc(int,const char*,const char*, ...);

int main(int argc, char **argv){
	
    if(argc!=6){
        fprintf(stderr,"usage: %s <host> <port> <chan> <nick> <ident>\n",argv[0]);
        exit(1);
    }
	
    const char *host = argv[1];
    const char *port = argv[2];
    const char *chan = argv[3];
    const char *nick = argv[4];
    const char *user = argv[5];
	
    char buff[BUFSIZE], ip[INET_ADDRSTRLEN];
    int sfd,status,sent,recvd,i;
    struct addrinfo hints,*serv;
    struct sockaddr_in *sip;
    struct irc_data *irc = malloc(sizeof(struct irc_data));
	
    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
	
    if((status=getaddrinfo(host,port,&hints,&serv))<0)
        die("getaddrinfo",status);
    if((sfd=socket(serv->ai_family,serv->ai_socktype,serv->ai_protocol))<0)
        die("socket",sfd);
    if((status=connect(sfd,serv->ai_addr,serv->ai_addrlen))<0)
        die("connect",status);
	
    sip = (struct sockaddr_in*)serv->ai_addr;
    inet_ntop(serv->ai_family,&sip->sin_addr,ip,sizeof(ip));
	
    snprintf(buff,BUFSIZE,"USER %s 8 * :\x50\x73\x79\x63\x68\x6F\x20\x42\x6F\x74\r\nNICK %s\r\nJOIN #%s\r\n",user,nick,chan);
    if((sent=send(sfd,buff,strlen(buff),0))<0)
        die("send",sent);
	
    while((recvd=recv(sfd,buff,BUFSIZE-1,0))>=0){
        buff[recvd-1]=0;
        puts(buff);
        parse_data(buff,&irc);
        if(irc->is_ready)
            if(strstr(irc->message,nick) != NULL)
                sayc(sfd,irc->chan,"sup %s",irc->nick);
        if(sscanf(buff,"PING :%s",buff)==1){
            snprintf(buff,BUFSIZE,"PONG :%s",buff);
            if(send(sfd,buff,strlen(buff),0)>0)
                puts("PONG!");
            else puts("PONG failed...just sayin");
        }
        
    }
    free(irc);
    close(sfd);
    freeaddrinfo(serv);
}


void die(const char *msg, int err){
    fprintf(stderr,"%s: %s\n",msg,gai_strerror(err));
    exit(1);
}

void parse_data(char *buff,struct irc_data **fat){
    if(sscanf(buff,":%[^!]!%[^@]@%[^ ] %*[^ ] %[^ :] :%[^\r\n]",(*fat)->nick,(*fat)->user,(*fat)->host,(*fat)->chan,(*fat)->message) == 5){
        (*fat)->is_ready = 1;
        if((*fat)->chan[0] != '#') strcpy((*fat)->chan,(*fat)->nick);
    } else (*fat)->is_ready = 0;
}

int sayc(int sockfd, const char *chan, const char *fmt, ...){
    char msg[BUFSIZE], k[BUFSIZE];    //need to change sizes..do it later
    va_list list;
    va_start(list,fmt);
    vsnprintf(k,BUFSIZE,fmt,list);
    snprintf(msg,BUFSIZE,"PRIVMSG %s :%s\r\n",chan,k); //potential problem with \r\n being truncated if string is too large..do it later
    va_end(list);
    return send(sockfd,msg,strlen(msg),0);
}
// Psycho

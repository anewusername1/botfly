#ifndef BOT_H
#define BOT_H
#include <stdio.h>
#include "irc/irc.h"

int irc_handle_data(irc_t *irc);
int irc_parse_action(irc_t *irc);
int irc_reply_message(irc_t *irc, char *nick, char* msg);
int smack(char *botnick, char *mesg, char *arg, int bufzise, char *irc_nick);
int google(char *mesg, char *arg, int bufzise);
void usage();
#endif

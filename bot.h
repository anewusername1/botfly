#ifndef BOT_H
#define BOT_H
#include <stdio.h>
#include "irc.h"

int irc_handle_data(irc_t *irc);
int irc_parse_action(irc_t *irc);
int irc_reply_message(irc_t *irc, char *nick, char* msg);
void usage();
#endif

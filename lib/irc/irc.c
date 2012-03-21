#include "../net/socket.h"
#include "irc.h"
#include <string.h>
#include <time.h>

int irc_connect(irc_t *irc, const char* server, const char* port){
  if((irc->s = get_socket(server, port)) < 0){
    return -1;
  }

  irc->bufptr = 0;
  return 0;
}

int irc_login(irc_t *irc){
  return irc_reg(irc->s, irc->nick, "arch", "HANSUDESU");
}

int irc_join_channel(irc_t *irc, const char* channel){
  strncpy(irc->channel, channel, 254);
  irc->channel[254] = '\0';
  return irc_join(irc->s, channel);
}

int irc_leave_channel(irc_t *irc){
  return irc_part(irc->s, irc->channel);
}

int irc_set_output(irc_t *irc, const char* file){
  irc->file = fopen(file, "w");
  if(irc->file == NULL)
    return -1;
  return 0;
}

int irc_log_message(irc_t *irc, const char* nick, const char* message){
  char timestring[128];
  time_t curtime;
  time(&curtime);
  strftime(timestring, 127, "%F - %H:%M:%S", localtime(&curtime));
  timestring[127] = '\0';

  fprintf(irc->file, "%s - [%s] <%s> %s\n", irc->channel, timestring, nick, message);
  fflush(irc->file);
  return 0;
}

void irc_close(irc_t *irc){
  sck_done(irc->s);
  fclose(irc->file);
}


// irc_pong: For answering pong requests...
int irc_pong(int s, const char *data){
  return sck_sendf(s, "PONG :%s\r\n", data);
}

// irc_reg: For registering upon login
int irc_reg(int s, const char *nick, const char *username, const char *fullname){
  return sck_sendf(s, "NICK %s\r\nUSER %s localhost 0 :%s\r\n", nick, username, fullname);
}

// irc_join: For joining a channel
int irc_join(int s, const char *data){
  return sck_sendf(s, "JOIN %s\r\n", data);
}

// irc_part: For leaving a channel
int irc_part(int s, const char *data){
  return sck_sendf(s, "PART %s\r\n", data);
}

// irc_nick: For changing your nick
int irc_nick(int s, const char *data){
  return sck_sendf(s, "NICK %s\r\n", data);
}

// irc_quit: For quitting IRC
int irc_quit(int s, const char *data){
  return sck_sendf(s, "QUIT :%s\r\n", data);
}

// irc_topic: For setting or removing a topic
int irc_topic(int s, const char *channel, const char *data){
  return sck_sendf(s, "TOPIC %s :%s\r\n", channel, data);
}

// irc_action: For executing an action (.e.g /me is hungry)
int irc_action(int s, const char *channel, const char *data){
  return sck_sendf(s, "PRIVMSG %s :\001ACTION %s\001\r\n", channel, data);
}

// irc_msg: For sending a channel message or a query
int irc_msg(int s, const char *channel, const char *data){
  return sck_sendf(s, "PRIVMSG %s :%s\r\n", channel, data);
}

// irc_who: Retrieve nick and host information
char *irc_who(const char *channel){
  // TODO: implement /who method to grab nick and host info
}

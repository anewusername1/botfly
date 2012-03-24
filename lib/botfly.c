#include "botfly.h"
#include "net/socket.h"
#include <string.h>
#include <time.h>

int irc_handle_data(irc_t *irc){
  char tempbuffer[512];
  int rc, i;

  if((rc = sck_recv(irc->s, tempbuffer, sizeof(tempbuffer) - 2 )) <= 0){
    fprintf(stderr, "buffer == %s\n", tempbuffer);
    perror("Timeout");
    return -1;
  }

  tempbuffer[rc] = '\0';

  for(i = 0; i < rc; ++i){
    switch (tempbuffer[i]){
      case '\r':
      case '\n':
      {
        irc->servbuf[irc->bufptr] = '\0';
        irc->bufptr = 0;

        if(irc_parse_action(irc) < 0)
          return -1;

        break;
      }

      default:
      {
        irc->servbuf[irc->bufptr] = tempbuffer[i];
        if(irc->bufptr >= (sizeof(irc->servbuf) -1))
          // Overflow!
          ;
        else
          irc->bufptr++;
      }
    }
  }
  return 0;
}

int irc_parse_action(irc_t *irc){
  // handle pings, errors, and notices
  if(strncmp(irc->servbuf, "PING :", 6) == 0){
    return irc_pong(irc->s, &irc->servbuf[6]);
  }
  else if(strncmp(irc->servbuf, "NOTICE AUTH :", 13) == 0){
    // Don't care
    return 0;
  }
  else if(strncmp(irc->servbuf, "ERROR :", 7) == 0){
    // Still don't care
    return 0;
  }

  // Parses IRC message that pulls out nick and message.
  char *ptr;
  int privmsg = 0;
  char irc_nick[128];
  char irc_msg[512];
  *irc_nick = '\0';
  *irc_msg = '\0';

  // Checks if we have non-message string
  if(strchr(irc->servbuf, 1) != NULL)
    return 0;

  if(irc->servbuf[0] == ':'){
    ptr = strtok(irc->servbuf, "!");
    if ( ptr == NULL ){
      printf("ptr == NULL\n");
      return 0;
    } else {
      strncpy(irc_nick, &ptr[1], 127);
      irc_nick[127] = '\0';
    }

    while((ptr = strtok(NULL, " ")) != NULL){
      if ( strcmp(ptr, "PRIVMSG") == 0 ){
        privmsg = 1;
        break;
      }
    }

    if(privmsg){
      if((ptr = strtok(NULL, ":")) != NULL && (ptr = strtok(NULL, "")) != NULL){
        strncpy(irc_msg, ptr, 511);
        irc_msg[511] = '\0';
      }
    }

    if(privmsg == 1 && strlen(irc_nick) > 0 && strlen(irc_msg) > 0){
      irc_log_message(irc, irc_nick, irc_msg);
      if(irc_reply_message(irc, irc_nick, irc_msg) < 0)
        return -1;
    }
  }
  return 0;
}

int irc_reply_message(irc_t *irc, char *irc_nick, char *msg)
{
  // TODO: implement action for nowai and when the first word someone says is 'sudo'. We'll make it say "sudo make _yourself_ a sandwich"
  // Checks if someone calls on the bot.
  if(*msg != '.')
    return 0;

  int buffer_size = 512;
  char message[buffer_size];
  char *command;
  char *arg;
  int me = 0;
  int retval = 0;

  // Gets command
  command = strtok(&msg[1], " ");
  arg = strtok(NULL, "");
  if(arg != NULL)
    while(*arg == ' ')
       arg++;

  if(command == NULL)
    return 0;

  if(strcmp(command, "ping") == 0){
    snprintf(message, buffer_size, "pong");
  }
  else if(strcmp(command, "smack") == 0){
    smack(irc->nick, message, arg, buffer_size, irc_nick);
    me = 1;
  }
  else if(strcmp(command, "google") == 0){
    google(message, arg, buffer_size);
  }
  else if(strcmp(command, "roflcopter") == 0){
    snprintf(message, buffer_size, "%s", roflcopter());
    /* roflcopter(message, arg, buffer_size); */
  }
  else if(strcmp(command, "annoybj") == 0){
    snprintf(message, buffer_size, "zomg bj!!");
  }
  else if(strcmp(command, "pet") == 0){
    snprintf(message, buffer_size, "purrs");
    me = 1;
  }
  else if(strcmp(command, "nowai") == 0){
    snprintf(message, buffer_size, "yawai");
  } else {
    snprintf(message, buffer_size, "yawns");
    me = 1;
  }

  if(me == 1)
    retval = irc_action(irc->s, irc->channel, message);
  else
    retval = irc_msg(irc->s, irc->channel, message);

  return retval;
}

int smack(char *botnick, char *mesg, char *arg, int bufsize, char *irc_nick){
  srand(time(NULL));
  int critical;
  critical = (rand()%10)/8;

  if(arg != NULL && strlen(arg) > 0){
    if(strcmp(botnick, arg) == 0){
      snprintf(mesg, bufsize, "scoffs then smacks %s with a rusty pipe for %d damage!", irc_nick, rand()%20 + 41);
    }else if(critical)
      snprintf(mesg, bufsize, "smacks %s, for %d damage (it's super effective).", arg, rand()%20 + 21);
    else
      snprintf(mesg, bufsize, "smacks %s, for %d damage.", arg, rand()%20 + 1);
    mesg[bufsize] = '\0';
  } else {
     snprintf(mesg, bufsize, "Smacking thin air..");
     mesg[bufsize] = '\0';
  }
  return 1;
}

int google(char *mesg, char *arg, int bufsize){
  char t_nick[128];
  char t_link[256];
  char link[256] = {0};

  char *t_arg = strtok(arg, " ");
  if ( t_arg ){
    strncpy(t_nick, t_arg, 127);
    t_nick[127] = '\0';
  }
  else
     return 0;

  t_arg = strtok(NULL, "");
  if ( t_arg ){
    while ( *t_arg == ' ' )
      t_arg++;

    strncpy(t_link, t_arg, 255);
    t_link[255] = '\0';
  }
  else
    return 0;

  t_arg = strtok(t_link, " ");
  while ( t_arg ){
    strncpy(&link[strlen(link)], t_arg, 254 - strlen(link));

    t_arg = strtok(NULL, " ");
    if ( !t_arg )
      break;

    strncpy(&link[strlen(link)], "%20", 254 - strlen(link));
  }

  snprintf(mesg, 511, "%s: http://lmgtfy.com/?q=%s", t_nick, link);
  mesg[bufsize - 1] = '\0';
  return 0;
}

const char* roflcopter(){
  const char *data = "  ROFL:ROFL:LOL:ROFL:ROFL\n"
         "       ______|_____      \n"
         " L    /            \\     \n"
         "LOL===            []\\    \n"
         " L    \\______________\\   \n"
         "         |     |         \n"
         "       -------------/    \n";
  return data;
}

// TODO: make botfly respond to private messages. We should be able to tell it to say something in the
// channel we specify, or do any number of unspecified actions

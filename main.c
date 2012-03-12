#include "socket.h"
#include "bot.h"
#include "irc.h"

int main(int argc, char **argv){
  if(argc < 2)
    usage();

  int ch;
  const char *server, *port, *chan, *nick, *user;
  port = "6667";
  nick = "botfly";
  user = "botfly";
  server = argv[1];
  chan = argv[2];
  irc_t irc;

  while((ch = getopt(argc, argv, "p:n:i:")) != -1){
    switch(ch){
      case 'p':
        port = optarg;
        break;
      case 'n':
        nick = optarg;
        break;
      case 'i':
        user = optarg;
        break;
      case '?':
      default:
        usage();
    }
  }
  argc -= optind;
  argv += optind;

  if ( irc_connect(&irc, server, port) < 0 )
  {
    fprintf(stderr, "Connection failed.\n");
    goto exit_err;
  }

  irc_set_output(&irc, "/dev/stdout");

  if ( irc_login(&irc, "botfly") < 0 )
  {
    fprintf(stderr, "Couldn't log in.\n");
    goto exit_err;
  }

  if ( irc_join_channel(&irc, chan) < 0 )
  {
    fprintf(stderr, "Couldn't join channel.\n");
    goto exit_err;
  }

  while ( irc_handle_data(&irc) >= 0 );

  irc_close(&irc);
  return 0;
exit_err:
  exit(1);
}

void usage(){
  puts("botfly <server> <chan> -p [port] -n <nick> -i <identity>");
  exit(1);
}
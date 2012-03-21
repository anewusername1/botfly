#include <string.h>
#include <unistd.h>
#include "lib/net/socket.h"
#include "lib/botfly.h"
#include "lib/irc/irc.h"

int main(int argc, char **argv){
  if(argc < 2)
    usage();

  int ch;
  const char *server, *port, *chan, *user, *file;
  irc_t irc;

  // defaults
  port = "6667";

  // TODO: need to pull nick from argv[0]
  irc.nick = "botfly";
  user = "botfly";
  file = stdout;

  server = argv[1];
  chan = argv[2];

  while((ch = getopt(argc, argv, "p:n:i:f:")) != -1){
    switch(ch){
      case 'p':
        port = optarg;
        break;
      case 'n':
        irc.nick = optarg;
        break;
      case 'i':
        user = optarg;
        break;
      case 'f':

      case '?':
      default:
        usage();
    }
  }
  argc -= optind;
  argv += optind;

  if(irc_connect(&irc, server, port) < 0){
    fprintf(stderr, "Connection failed.\n");
    goto exit_err;
  }

  irc_set_output(&irc, file);

  if(irc_login(&irc) < 0){
    fprintf(stderr, "Couldn't log in.\n");
    goto exit_err;
  }

  if(irc_join_channel(&irc, chan) < 0){
    fprintf(stderr, "Couldn't join channel.\n");
    goto exit_err;
  }

  while(irc_handle_data(&irc) >= 0);

  irc_close(&irc);
  return 0;
exit_err:
  exit(1);
}

CC = gcc

TARGET = bin/botfly

OBJECTS = main.o lib/irc/irc.o lib/botfly.o lib/net/socket.o

all: $(TARGET)

%.o: %.c
	$(CC) -Wall -g -c -o $@ $<

clean: clean-obj clean-bin

clean-obj:
	rm -rf *.o
	
clean-bin:
	rm -rf $(TARGET)
	
$(TARGET): $(OBJECTS)
	$(CC) -g -o $(TARGET) $(OBJECTS)

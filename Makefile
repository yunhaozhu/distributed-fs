CC     := gcc
CFLAGS := -Wall -Werror

default: udp library server

udp: udp.c
	$(CC) $(CFLAGS) -fPIC -c -o udp.o udp.c

library: mfs.c
	$(CC) $(CFLAGS) -fPIC -c -o mfs.o mfs.c
	$(CC) $(CFLAGS) -shared -Wl,-soname,libmfs.so -o libmfs.so mfs.o udp.o -lc

server: server.c
	$(CC) $(CFLAGS) -c -o server.o server.c 
	$(CC) $(CFLAGS) server.o udp.o -o server

client: client.c
	$(CC) $(CFLAGS) -c client.c -o client.o -lmfs -L.
	$(CC) $(CFLAGS) -o client client.o udp.o -lmfs -L.

clean:
	rm -f *.o *.so client server
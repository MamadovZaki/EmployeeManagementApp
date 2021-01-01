CC = gcc 
CFLAGS = -g -w -Wall

main: obj/main.o obj/utils.o obj/interface.o
	$(CC) $(CFLAGS) -o executables/main obj/main.o obj/utils.o obj/interface.o

utils.o: include/utils.h src/utils.c 
	$(CC) $(CFLAGS) -c src/utils.c 

interface.o: include/interface.h src/interface.c
	$(CC) $(CFLAGS) -c src/interface.c 

clean:
	rm -f core obj/*.o executables/main 


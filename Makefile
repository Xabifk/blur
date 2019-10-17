CC = gcc

CFLAGS = -c -Wall

all: test_program memory_coruption

memory_coruption: memory_map.o memory_interface.o memory_coruption.o
	$(CC) -o bin/memory_coruption obj/memory_map.o obj/memory_coruption.o obj/memory_interface.o

memory_map.o: 
	$(CC) $(CFLAGS) -o obj/memory_map.o src/memory_map/memory_map.c

memory_interface.o:
	$(CC) $(CFLAGS) -o obj/memory_interface.o src/memory_interface/memory_interface.c

memory_coruption.o:
	$(CC) $(CFLAGS) -o obj/memory_coruption.o src/main.c


test_program:
	$(CC) -o bin/test_program src/test_program/test.c

clean:
	rm obj/* bin/*
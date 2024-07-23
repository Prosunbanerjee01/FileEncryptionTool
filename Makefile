CC = gcc
CFLAGS = -Wall
TARGET = FileEncryptionTool

all: $(TARGET)

$(TARGET): main.o encryption.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o encryption.o

main.o: main.c encryption.h
	$(CC) $(CFLAGS) -c main.c

encryption.o: encryption.c encryption.h
	$(CC) $(CFLAGS) -c encryption.c

clean:
	rm -f *.o $(TARGET)

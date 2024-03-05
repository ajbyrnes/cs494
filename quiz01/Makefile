CC=g++
CFLAGS=-fopenmp
TARGET=totalsum

all: $(TARGET)

$(TARGET): $(TARGET).cc
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cc

clean:
	rm -f $(TARGET)

SRC=sort.c
TARGET=sort


all: sort generator

sort:
		gcc $(SRC) -o $(TARGET) -g

generator:
		gcc generator.c -o generator -g

clean:
			rm sort generator


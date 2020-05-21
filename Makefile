SRC=sort.c
TARGET=sort

sort:
		gcc $(SRC) -o $(TARGET) -g

clean:
			rm sort


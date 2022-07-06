.PHONY: all clean

all: librefcount.so librefcount.a

librefcount.so:
	$(CC) -fPIC -c refcount.c
	$(CC) -shared refcount.o -o librefcount.so

librefcount.a:
	ar -rcs librefcount.a refcount.o

example: librefcount.so
	$(CC) example.c ./librefcount.so -o example

clean:
	rm -f librefcount.* *.o example


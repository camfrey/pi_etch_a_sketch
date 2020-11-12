CFLAGS := -g
INCLUDE := -I ~/libsense/include
LDFLAGS := -L ~/libsense/lib -lsense -lm
%.o: %.c
	gcc -c $(CFLAGS) $< $(INCLUDE)

main: main.o input.o output.o
	gcc -o etch $(INCLUDE) main.o input.o output.o $(LDFLAGS) 

outputtest: outputtest.o output.o
	gcc -o outputtest $(INCLUDE) output.o  outputtest.o $(LDFLAGS)

inputtest: inputtest.o
	gcc -o inputtest $(INCLUDE) inputtest.o $(LDFLAGS)

clean:
	rm -f *.o etch inputtest outputtest


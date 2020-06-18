all: dz1

%.o: %.cpp *.h Makefile
	g++ -c $< -o $@

dz1: Set.o BitString.o dz1.o
	g++ -o $@ $^

clean:
	rm *.o

test: all
	./dz1

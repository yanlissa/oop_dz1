all: dz1

%.o: %.cpp *.h Makefile
	g++ -c $< -o $@

dz1: Set.o BitString.o Application.o dz1.o
	g++ -o $@ $^

clean:
	rm *.o

test: all
	cat test_input.txt | ./dz1

build:
	gcc main.c -lSDL2 -o main

clean:
	-rm ./main

run:
	./main

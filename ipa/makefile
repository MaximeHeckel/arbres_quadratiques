arbres_quadratiques: main.o arbre.o bmp.o image.o algos.o
	gcc -Wall -o arbres_quadratiques main.o arbre.o bmp.o image.o algos.o

arbre.o: arbre.c arbre.h
	gcc -Wall -c arbre.c
bmp.o: bmp.c bmp.h
	gcc -Wall -c bmp.c
image.o: image.c image.h
	gcc -Wall -c image.c
algos.o: algos.c algos.h
	gcc -Wall -c algos.c
main.o: main.c
	gcc -Wall -c main.c
clean: 
	rm -v arbres_quadratiques main.o arbre.o bmp.o image.o algos.o

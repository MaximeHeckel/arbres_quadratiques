arbres_quadratiques: main.o arbre.o bmp.o image.o algos.o
	gcc -o arbres_quadratiques main.o arbre.o bmp.o image.o algos.o

arbre.o: arbre.c arbre.h
	gcc -c arbre.c
bmp.o: bmp.c bmp.h
	gcc -c bmp.c
image.o: image.c image.h
	gcc -c image.c
algos.o: algos.c algos.h
	gcc -c algos.c
main.o: main.c
	gcc -c main.c
clean: 
	rm  arbres_quadratiques main.o arbre.o bmp.o image.o algos.o

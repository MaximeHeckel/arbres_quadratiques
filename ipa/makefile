arbres_quadratiques: main.o arbre.o bmp.o 
	gcc -Wall -o arbres_quadratiques main.o arbre.o bmp.o
arbre.o: arbre.c arbre.h
	gcc -Wall -c arbre.c
bmp.o: bmp.c bmp.h
	gcc -Wall -c bmp.c
main.o: main.c
	gcc -Wall -c main.c
clean: 
	rm -v arbres_quadratiques main.o arbre.o bmp.o  

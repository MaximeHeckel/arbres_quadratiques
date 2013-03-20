#include "bmp.h"


RGB** creeMatrice(header my_header)
{
	RGB** Matrice;
	Matrice =malloc (sizeof(RGB*) * my_header.height);
	if(Matrice == NULL)
	{
		perror("Erreur mémoire");
		exit(0);
	}
	int i;
	for(i=0; i<my_header.height; i++)
	{
		Matrice[i]=malloc(sizeof(RGB) * my_header.width);
		if(Matrice[i]==NULL)
		{
			perror("Erreur mémoire");
			exit(0);
		}
	}
	return Matrice;

}


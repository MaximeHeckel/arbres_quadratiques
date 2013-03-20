#include "bmp.h"

void isBMP(FILE* fichier, HEADER header, infoheader my_infoheader)
{
	char type[3];
	int bpp;
	fseek(fichier,0,0);
	fread(type,1,2,fichier);
	type[2]= '\0';
	fseek(fichier,28,0);
	fread(&bpp,1,2,fichier);
	if(strcmp(type,"BM")||(bpp !=24))
	{
		perror("Ce fichier n'est pas un BMP");
		exit(0);
	}
}

RGB** creeMatrice(infoheader my_infoheader)
{
	RGB** Matrice;
	Matrice =malloc (sizeof(RGB*) * my_infoheader.height);
	if(Matrice == NULL)
	{
		perror("Erreur mémoire");
		exit(0);
	}
	int i;
	for(i=0; i<my_infoheader.height; i++)
	{
		Matrice[i]=malloc(sizeof(RGB) * my_infoheader.width);
		if(Matrice[i]==NULL)
		{
			perror("Erreur mémoire");
			exit(0);
		}
	}
	return Matrice;

}


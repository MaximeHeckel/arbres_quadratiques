#include "bmp.h"
#include "arbre.h"

int height, width;

bool isBMP(FILE* fichier, HEADER header, infoheader my_infoheader)
{
	bool res = true;
	char type[3];
	int bpp;
	fseek(fichier,0,0);
	fread(type,1,2,fichier);
	type[2]= '\0';
	fseek(fichier,28,0);
	fread(&bpp,1,2,fichier);
	if(strcmp(type,"BM")||(bpp !=24))
	{
		res=false;
	}
	return res;
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

// Source : les internettes => ( à analyser (propriétés bien particulières des BMP))

infoheader readInfo(FILE* arq)
{
    infoheader info;

    // Image Width in pixels
    fseek(arq,18,0);
    fread(&info.width,1,4,arq);

    // Image Height in pixels
    fseek(arq,22,0);
    fread(&info.height,1,4,arq);

    // Color depth, BPP (bits per pixel)
    fseek(arq,28,0);
    fread(&info.bpp,1,2,arq);

    // Compression type
    // 0 = Normmally
    // 1 = 8 bits per pixel
    // 2 = 4 bits per pixel
    fseek(arq,30,0);
    fread(&info.compression,1,4,arq);

    // Image size in bytes
    fseek(arq,34,0);
    fread(&info.imagesize,1,4,arq);

    // Number of color used (NCL)
    // value = 0 for full color set
    fseek(arq,46,0);
    fread(&info.colours,1,4,arq);

    // Number of important color (NIC)
    // value = 0 means all collors important
    fseek(arq,50,0);
    fread(&info.impcolours,1,4,arq);

    return(info);
}

RGB** readFile(FILE* fichier , RGB** Matrice)
{
	int i,j;
	RGB temp;
	int position = 51;
	fseek(fichier,0,0);

	for(i=0; i<height; i++)
	{
		for(j=0; j<width;j++)
		{
			position=3+position;
			fseek(fichier,position,0);
			fread(&temp,(sizeof(RGB)),1,fichier);
			Matrice[i][j] =temp;
		}
	}
	return Matrice;
}

void writeFile(RGB** Matrice, FILE* fichier)
{
	FILE* out;
	int i,j;
	int position = 51;
	RGB temp;
	char header[54];
	fseek(fichier,0,0);
	out = fopen("out.bmp","w");
	fseek(out,0,0);
	fwrite(header,54,1,out);

	for(i=0; i<height;i++)
	{
		for(j=0; j<width;j++)
		{
			position = position +3;
			fseek(out,position,0);
			temp = Matrice[i][j];
			fwrite(&temp,(sizeof(RGB)),1,out);
		}
	}
	fflush(out);
	fclose(out);

}

void freeMatrice(RGB** Matrice,infoheader info )
{
	int i,j;
	for(i=0; i<info.height;i++)
	{

			free(Matrice[i]);

	}
	free(Matrice);
}

RGB** MatriceToCell(RGB**Matrice ,int sizew, int sizeh, int zone)
{

	/*

	|	1	|	2	|
	|_______|_______|
	|		|		|
	|	3	|	4	|

	*/
	RGB** resMatrice;
	RGB** SubMatrice1;
	RGB** SubMatrice2;
	RGB** SubMatrice3;
	RGB** SubMatrice4;
	int h2= sizeh/2;
	int w2=sizew/2;
	int i;
	int j;
	if(zone==3)
	{
		for(i=0; i<h2;i++)
		{
			for(j=0;j<w2; j++)
			{
				SubMatrice3[i][j]=Matrice[i][j];
				resMatrice = SubMatrice3;
			}
		}
	}
	else if(zone==1)
	{
		for(i=h2; i<sizeh;i++)
		{
			for(j=0;j<w2; j++)
			{
				SubMatrice1[i][j]=Matrice[i][j];
				resMatrice = SubMatrice1;
			}
		}
	}
	else if(zone==2)
	{
		for(i=h2; i<sizeh;i++)
		{
			for(j=w2;j<sizew; j++)
			{
				SubMatrice2[i][j]=Matrice[i][j];
				resMatrice = SubMatrice2;
			}
		}
	}
	else if(zone==2)
	{
		for(i=0; i<h2;i++)
		{
			for(j=w2;j<sizew; j++)
			{
				SubMatrice4[i][j]=Matrice[i][j];
				resMatrice = SubMatrice4;

			}
		}
	}
	else
	{
		perror("Zone indisponible" );
	}
	return resMatrice;
}

/* DANS LE MAIN

FILE* arq; /* the bitmap file 24 bits
RGB** Matrix_aux, Matrix;
INFOHEADER info;
info = readInfo(FILE* arq);
height = info.height;
width = info.width;

Matrix_aux = createMatrix();
Matrix = loadImage(arq,Matrix_aux);

*/

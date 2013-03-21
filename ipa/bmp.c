#include "bmp.h"

// ********** Verify if the file exist **********
FILE* exist(char *name)
{
	FILE *tmp;
	tmp = fopen(name,"r+b");
	if (!tmp)
	{
		printf("\nERROR: Incorrect file or not exist!\n");
		exit(0);
	}
	fseek(tmp,0,0);
	return(tmp);
}

// ********** Verify if the file is BMP *********
void isBMP(FILE* arq, HEADER head, INFOHEADER info){
        char type[3];
        unsigned short int bpp;
        fseek(arq,0,0);
        fread(type,1,2,arq);
        type[2] = '\0';

        fseek(arq,28,0);
        fread(&bpp,1,2,arq);

        if (strcmp(type,"BM") || (bpp != 24)){
                printf("\nThe file is not BMP format or is not 24 bits\n");
                exit(0);
        }
}

// ********** Read BMP info from file **********
INFOHEADER readInfo(FILE* arq){
        INFOHEADER info;

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

void loadImage(FILE* arq, RGB** Matrix){
        int i,j;
        RGB tmp;
        long pos = 51;

        fseek(arq,0,0);

        for (i=0; i<height; i++){
                for (j=0; j<width; j++){
                        pos+= 3;
                        fseek(arq,pos,0);
                        fread(&tmp,(sizeof(RGB)),1,arq);
                        Matrix[i][j] = tmp;
                }
        }
}

// ********** Create Matrix **********
RGB** createMatrix(){
        RGB** Matrix;
        int i;
        Matrix = (RGB **) malloc (sizeof (RGB*) * height);
        if (Matrix == NULL){
                perror("***** No memory available *****");
                exit(0);
        }
        for (i=0;i<height;i++){
                Matrix[i] = (RGB *) malloc (sizeof(RGB) * width);
                if (Matrix[i] == NULL){
                perror("***** No memory available *****");
                        exit(0);
                }
        }
        return(Matrix);
}

// ********** Image Output **********
void writeBMP(RGB **Matrix, HEADER head, FILE* arq){
	FILE* out;
	int i,j;
	RGB tmp;
	long pos = 51;

	char header[54];
	fseek(arq,0,0);
	fread(header,54,1,arq);
	out = fopen("out.bmp","w");

	fseek(out,0,0);
	fwrite(header,54,1,out);

	printf("\nMatrix = %c\n",Matrix[0][0].RGB[0]);
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			pos+= 3;
			fseek(out,pos,0);
			tmp = Matrix[i][j];
			fwrite(&tmp,(sizeof(RGB)),1,out);
		}
	}
	fflush(out);
	fclose(out);
}

// ********** Free memory allocated for Matrix **********
void freeMatrix(RGB** Matrix,INFOHEADER info)
{
	int i;
	int lines = info.height;

	for (i=0;i<lines;i++){
		free(Matrix[i]);
	}
	free(Matrix);
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

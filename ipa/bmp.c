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
void isBMP(FILE* arq){
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
RGB** createMatrix(int h,int w)
{

        int i;
        RGB ** Matrix = (RGB **) malloc (sizeof (RGB*) * h);
        if (Matrix == NULL){
                perror("***** No memory available 1*****");
                exit(0);
        }
        for (i=0;i<h;i++){
                Matrix[i] = (RGB *) malloc (sizeof(RGB) * w);
                if (Matrix[i] == NULL){
                perror("***** No memory available 2*****");
                        exit(0);
                }
        }
        return(Matrix);
}

// ********** Image Output **********
void writeBMP(RGB **Matrix, FILE* arq){
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
	assert(Matrice != NULL);

	int h2= sizeh/2;
	int w2=sizew/2;
	RGB** resMatrice = createMatrix(h2,w2);
    assert(resMatrice != NULL);

	//Si on a atteint le "fond" de l'image, ie un pixel (qui est indivisible), on return NULL (signal d'arrret)
	if( (h2 == 0) || (w2 && 0) )
	{
	    return NULL;
	}

	int i;
	int j;
	switch(zone)
	{
	    // SE
	    case 4:
            for(i=h2; i<sizeh;i++)
            {
                for(j=0;j<w2; j++)
                {
                    resMatrice[i-h2][j] =Matrice[i][j];
                }
            }
            break;
        // SO
	    case 3:
            for(i=h2; i<sizeh;i++)
            {
                for(j=w2;j<sizew; j++)
                {
                    resMatrice[i-h2][j-w2] =Matrice[i][j];
                }
            }
            break;
        // NO
        case 1:
            for(i=0; i<h2;i++)
            {
                for(j=0;j<w2; j++)
                {
                    RGB var = Matrice[i][j];
                    resMatrice[i][j] = var;
                }
            }
            break;
        // NE
        case 2:
            for(i=0; i<h2;i++)
            {
                for(j=w2;j<sizew; j++)
                {
                    resMatrice[i][j-w2] =Matrice[i][j];
                }
            }
            break;

        default:
            perror("Zone indisponible" );
	}

	return resMatrice;
}

void printMatrix(RGB** Matrix, int h, int w)
{
    assert(Matrix != NULL);
    int i,j;
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
            printf("%d.%d.%d   ",Matrix[i][j].RGB[0],Matrix[i][j].RGB[1],Matrix[i][j].RGB[2]);
        printf("\n");
    }
}


RGB ** fusionner(RGB ** sousMatriceNO,RGB **  sousMatriceNE,RGB **  sousMatriceSO,RGB **  sousMatriceSE, int h, int w)
{
        assert(sousMatriceNO != NULL);
        assert(sousMatriceNE != NULL);
        assert(sousMatriceSO != NULL);
        assert(sousMatriceSE != NULL);


        RGB ** Matrice = createMatrix(h,w);
        assert(Matrice != NULL);

        int i,j;
        int h2 = h/2;
        int w2 = w/2;
//Traitement SO
            for(i=h2; i<h;i++)
            {
                for(j=0;j<w2; j++)
                {
                    Matrice[i][j] = sousMatriceSO[i-h2][j];
                }
            }
//Traitement SE
            for(i=h2; i<h-1;i++)
            {
                for(j=w2;j<w; j++)
                {
                    Matrice[i][j] = sousMatriceSE[i-h2][j-w2];
                }
            }
//Traitement NO
            for(i=0; i<h2;i++)
            {
                for(j=0;j<w2; j++)
                {
                    Matrice[i][j] = sousMatriceNO[i][j];
                }
            }
//Traitement NE
            for(i=0; i<h2;i++)
            {
                for(j=w2;j<w; j++)
                {
                    Matrice[i][j] = sousMatriceNE[i][j-w2];
                }
            }
            return Matrice;
}

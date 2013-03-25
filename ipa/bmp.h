#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

typedef struct
    {
        char        type[2];    // file type
        unsigned int    size;       // file size in bytes
        unsigned short int reserved1,reserved2;
        unsigned int    offset;     // offset to image data
    }HEADER;


typedef struct
        {
                unsigned char RGB[3];
        }RGB;

typedef struct
        {
                unsigned int size;
                int width,height;
                unsigned short int planes;
                unsigned short int bpp;
                unsigned int compression;
                unsigned int imagesize;
                int xresolution,yresolution;
                unsigned int colours;
                unsigned int impcolours;
        }INFOHEADER;
typedef struct INFOHEADER infoheader;
/* Global */
int height, width;

FILE* exist(char *name);
void isBMP(FILE* arq);
INFOHEADER readInfo(FILE* arq);
RGB** createMatrix();
//void loadImage(FILE* arq, RGB** Matrix);
//void writeBMP(RGB **Matrix, HEADER head, FILE* arq);
void freeMatrix(RGB **Matrix,int h);
RGB** MatriceToCell(RGB**Matrice ,int sizew, int sizeh, int zone);
void printMatrix(RGB** Matrix, int h, int w);
RGB ** fusionner(RGB ** sousMatriceNO,RGB **  sousMatriceNE,RGB **  sousMatriceSO,RGB **  sousMatriceSE, int h, int w);
#endif // BMP_H_INCLUDED

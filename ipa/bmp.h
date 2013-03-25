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
#endif // BMP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct
	{
		char		type[2]; 	// file type
		unsigned int	size; 		// file size in bytes
		unsigned short int reserved1,reserved2;
		unsigned int	offset; 	// offset to image data
	}HEADER;

typedef struct
    {
        unsigned char RGB[3];
    }RGB;
 
struct INFOHEADER
    {
        unsigned int size;
        int width,height;
        unsigned short int planes;
        unsigned short int bpp; //bitperpixel
        unsigned int compression;
        unsigned int imagesize;
        int xresolution,yresolution;
        unsigned int colours;
        unsigned int impcolours;  //importantcolours
    };
typedef struct INFOHEADER header;
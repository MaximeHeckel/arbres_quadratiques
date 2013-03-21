#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
enum bool {false, true};

typedef enum bool bool;

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
typedef struct INFOHEADER infoheader;

bool isBMP(FILE* fichier, HEADER header, infoheader my_infoheader);
RGB** creeMatrice(infoheader my_infoheader);
infoheader readInfo(FILE* arq);
RGB** readFile(FILE* fichier , RGB** Matrice);
void writeFile(RGB **Matrix, FILE* fichier);
void freeMatrice(RGB** Matrice,infoheader info );
RGB** MatriceToCell(RGB**Matrice ,int sizew, int sizeh, int zone);
/*
 * @File : main.c
 *
 * @Author :Philippe Gaultier, Maxime Heckel
 *
 * @Summary : compress 24 bits .bmp files, whose size is 2^n.
 *
 * @Version : 2013/03/26
 *
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 *  wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "image.h"
#include "bmp.h"

int main(int argc, char * argv[])
{
    FILE *arq; // the bitmap file 24 bits
    INFOHEADER info;
    assert(argc == 3);

    char * name = argv[1];
    char * out = argv[2];


    arq = exist(name);
    isBMP(arq);
    info = readInfo(arq);
    prepareBMP(out,info,arq);

    fclose(arq);

    printf("\n %d %d",info.height,info.width);
    Arbre pere = loadImage(name,info.height);


<<<<<<< HEAD:main.c

    pere=unification(pere);
    print(pere);
    writeBMP(pere,out,info);
=======
    //pere=unification(pere);
    //writeBMP(pere,out,info);
>>>>>>> 847d351485c4529b4bdb25d7537eb265c785cf77:ipa/main.c
    freeArbre(&pere);

	return 0;
}

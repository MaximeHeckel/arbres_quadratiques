/*
 * @File : test.c
 *
 * @Author :
 *
 * @Summary :
 *
 * @Version : 2013/03/14
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

int main()
{
    FILE *arq; // the bitmap file 24 bits
    INFOHEADER info;

    char name[15];

    printf("Entrez le nom du fichier à traiter : ");
    scanf("%s",name);

    arq = exist(name);
    isBMP(arq);
    info = readInfo(arq);
    prepareBMP("out.bmp",info,arq);
    prepareBMP("out1.bmp",info,arq);
    fclose(arq);
    printf("\n %d %d",info.height,info.width);
    Arbre pere = loadImage(name,info.height);

    writeBMP(pere,"out.bmp",info);
    pere=unification(pere);
    writeBMP(pere,"out1.bmp",info);
    freeArbre(&pere);

	return 0;
}

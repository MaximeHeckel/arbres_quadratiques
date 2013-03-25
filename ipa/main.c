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
    RGB  **Matrix;
    INFOHEADER info;
    HEADER head;
    char name[]="orca.bmp";

   /* printf("Entrez le nom du fichier à traiter : ");
    scanf("%s",name);*/

    arq = exist(name);
    isBMP(arq,head,info);
    info = readInfo(arq);


    Arbre pere=creerArbre();
    pere = loadImage(arq,info.height,info.width,0,pere);
    print(pere);

    freeArbre(&pere);

    fclose(arq);




	return 0;


}


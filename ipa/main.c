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
#include "algos.h"
#include "image.h"
#include "bmp.h"

int main(int argc, char * argv[])
{
/*
    //Arbre mon_fils = creerArbre(Feuille);
    Arbre pere = inserer(NULL,SO,NOIR);
    print(pere);
    Arbre fils = inserer(pere,SE,BLANC);
    print(pere);
    //free(pere);
    printf("\n%d",nb_feuille(pere));

    freeArbre(pere);*/

    FILE *arq; /* the bitmap file 24 bits */
    RGB  **Matrix;
    INFOHEADER info;
    HEADER head;
    char name[15];

    printf("Veuillez entrer le nom du fichier à traiter : ");
    scanf("%s",name);

    arq = exist(name);
    isBMP(arq,head,info);
    info = readInfo(arq);
    height = info.height;
    width = info.width;

    Matrix = createMatrix(info);
    printf("\nMatrix = %c\n",Matrix[0][0].RGB[0]);
    loadImage(arq,Matrix);
    printf("\nMatrix = %c\n",Matrix[0][0].RGB[0]);
    writeBMP(Matrix,head,arq);
    freeMatrix(Matrix,info);
    fclose(arq);
    /*Image image = creerImage(4,4);
    colorier(image,0,2,2);
    colorier(image,0,3,3);
    print_image(image);

    freeImage(image);*/



	return 0;
}


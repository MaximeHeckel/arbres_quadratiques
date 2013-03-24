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
    FILE *arq; /* the bitmap file 24 bits */
    RGB  **Matrix;
    INFOHEADER info;
    HEADER head;
    char name[15];

    printf("Type the image's name : ");
    scanf("%s",name);

    arq = exist(name);
    isBMP(arq,head,info);
    info = readInfo(arq);
    height = info.height;
    width = info.width;

    Matrix = createMatrix(info);
    Arbre newArbre = creerArbre();
    //printf("\nMatrix = %c\n",Matrix[0][0].RGB[0]);
    loadImage(arq,Matrix);
    MatriceToArbre(Matrix,newArbre, info.height, info.width);
    printf("\n %d", hauteur(newArbre));
    //print(newArbre);
    RGB ** res = ArbreToMatrice(newArbre);
    int h = calcDimensionMatrice(newArbre);
    printMatrix(res,h,h);

    //printf("\nMatrix = %c\n",Matrix[0][0].RGB[0]);
    //writeBMP(Matrix,head,arq);
    return(0);
}


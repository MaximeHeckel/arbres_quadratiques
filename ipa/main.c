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
    char name[15];

    printf("Entrez le nom du fichier à traiter : ");
    scanf("%s",name);

    arq = exist(name);
    isBMP(arq,head,info);
    info = readInfo(arq);
    height = info.height;
    width = info.width;

    //RGB** Matrice = createMatrix(info);
    //Matrice[2][2].RGB[0] = 111;
    //Matrice[0][1].RGB[2] = 222;
    //Matrice[1][3].RGB[1]=44;
    //Matrice[3][1].RGB[1]=33;
    //printMatrix(Matrice,4,4);
    //Arbre newArbre = creerArbre();
    //writeBMP(Matrice,head,arq);
    //loadImage(arq,Matrix);
    //printMatrix(Matrix, height, width);
    //MatriceToArbre(Matrix,newArbre, info.height, info.width);
    //printf("\n %d", hauteur(newArbre));
    //print(newArbre);
    //RGB ** res = ArbreToMatrice(newArbre);
    
    //printf("\n %d", calcDimensionMatrice(newArbre));



	return 0;


}


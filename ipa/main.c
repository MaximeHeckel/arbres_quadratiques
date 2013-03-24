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



   /* FILE *arq; // the bitmap file 24 bits
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
    width = info.width;*/



  //printMatrix(Matrix,info.height,info.width);
    //printf("\nMatrix = %c\n",Matrix[0][0].RGB[0]);
    Arbre pere = creerArbre();

    RGB ** Matrice = createMatrix(4,4);
    pere = MatriceToArbre(Matrice,pere,4,4);
    print(pere);
    printf("\n\n**************\n");
    //unification(pere);
    freeArbre(&pere);
    print(pere);
  //  printf("\n\n %d",isUni(pere->fils[NO]));
//    RGB ** Matrice2 = ArbreToMatrice(pere);

    //pere = MatriceToArbre(Matrix,pere,info.height,info.width);
    //print(pere);
    //unification(pere);

   // Matrix = ArbreToMatrice(pere);


   /* writeBMP(Matrix,arq);
    freeMatrix(Matrix,info);
    fclose(arq);*/


	return 0;


}


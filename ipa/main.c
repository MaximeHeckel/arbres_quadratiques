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
    Matrix = createMatrix(info);

    width = info.width;




    //writeBMP(Matrice,head,arq);
     loadImage(arq,Matrix);
   // printMatrix(Matrix, height, width);
    //MatriceToArbre(Matrix,newArbre, info.height, info.width);
    //free(newArbre);
    //printf("\n %d", hauteur(newArbre));
    //print(newArbre);

   // RGB ** res = ArbreToMatrice(newArbre);



  //printMatrix(Matrix,info.height,info.width);

    Arbre pere = creerArbre();
    Matrix = createMatrix();

    printMatrix(Matrix,height,width);
    pere = MatriceToArbre(Matrix,pere,height,width);
    //print(pere);
    printf("\n\n**************\n");
    unification(pere);
    //print(pere);


    printf("\n\n**************\n");
    RGB ** Matrice2 = ArbreToMatrice(pere);

    //printMatrix(Matrice2,height,width);
    writeBMP(Matrice2,head,arq);


    freeArbre(&pere);
    freeMatrix(Matrix,height);
    freeMatrix(Matrice2,height);
    fclose(arq);


   /* writeBMP(Matrix,arq);
    freeMatrix(Matrix,info);
    fclose(arq);*/


	return 0;


}


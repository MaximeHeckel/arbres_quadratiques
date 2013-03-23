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
/*
    //Arbre mon_fils = creerArbre(Feuille);
    Arbre pere = inserer(NULL,SO,NOIR);
    print(pere);
    Arbre fils = inserer(pere,SE,BLANC);
    print(pere);
    //free(pere);
    printf("\n%d",nb_feuille(pere));

    freeArbre(pere);*/

    FILE *arq; // the bitmap file 24 bits
   // RGB  **Matrix;
    INFOHEADER info;
    //HEADER head;
    char name[]="orca.bmp";

   /* printf("Veuillez entrer le nom du fichier à traiter : ");
    scanf("%s",name);*/


    /*arq = exist(name);
    isBMP(arq);
    info = readInfo(arq);
    height = info.height;
    width = info.width;
    Matrix = createMatrix(info.height,info.width);
   // printf(" %d %d",info.height,info.width);
   // printf("\nMatrix = %c\n",Matrix[0][0].RGB[0]);
    loadImage(arq,Matrix);
    Arbre newArbre = creerArbre();
    MatriceToArbre(Matrix,newArbre, info.height, info.width);
   // printf("\n %d", hauteur(newArbre));
    RGB ** res = ArbreToMatrice(newArbre);
    int h = calcDimensionMatrice(newArbre);
    printMatrix(res,h,h);*/
   // print(newArbre);
  //printMatrix(Matrix,info.height,info.width);
    //printf("\nMatrix = %c\n",Matrix[0][0].RGB[0]);
   /* Arbre pere = creerArbre();
    MatriceToArbre(Matrix,pere,info.height,info.width);
    print(pere);*/

   /* RGB** Matrice = createMatrix(4,4);
    Matrice[2][2].RGB[0] = 111;
    Matrice[0][1].RGB[2] = 222;

    printMatrix(Matrice,4,4);

    RGB ** sousMatriceNO = MatriceToCell(Matrice,4,4,1);
    RGB ** sousMatriceNE = MatriceToCell(Matrice,4,4,2);
    RGB ** sousMatriceSO = MatriceToCell(Matrice,4,4,4);
    RGB ** sousMatriceSE = MatriceToCell(Matrice,4,4,3);
    printf("\n\n\n");
    printMatrix(sousMatriceSO,2,2);

    RGB ** Matrice2 = fusionner(sousMatriceNO,sousMatriceNE,sousMatriceSO,sousMatriceSE,4,4);
    printf("\n\n\n");
    printMatrix(Matrice2, 4, 4);*/




/*
    Arbre pere = creerArbre();
    pere = MatriceToArbre(Matrix,pere,4,4);
    print(pere);*/

   // writeBMP(Matrix,head,arq);
    //freeMatrix(Matrix,info);
    //fclose(arq);
    /*Image image = creerImage(4,4);
    colorier(image,0,2,2);
    colorier(image,0,3,3);
    print_image(image);

    freeImage(image);*/



	return 0;
}


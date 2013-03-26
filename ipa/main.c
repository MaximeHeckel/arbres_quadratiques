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
   // HEADER head;
    char name[]="test.bmp";

   /* printf("Entrez le nom du fichier à traiter : ");
    scanf("%s",name);*/

    arq = exist(name);
    isBMP(arq);
    info = readInfo(arq);

    //Arbre pere = loadImage(arq,info.height,info.width);
    //print(pere);
   // pere=unification(pere);
    //print(pere);
    Arbre pere = creerArbre();
    pere->couleur = NON_UNI;

    Arbre filsNO = creerArbre();
    filsNO->couleur = BLANC;

    Arbre filsNE = creerArbre();
    filsNO->couleur = NOIR;

    Arbre filsSO = creerArbre();
    filsNO->couleur = BLANC;

    Arbre filsSE = creerArbre();
    filsNO->couleur = NOIR;

    pere->fils[NO]=filsNO;
    pere->fils[NE]=filsNE;
    pere->fils[SO]=filsSO;
    pere->fils[SE]=filsSE;

  // writeBMP(pere,"out.bmp",info,arq);
  //printf(" \n %d",is_feuille(pere->fils[NO]));
 // writeBMP2(pere->fils[NO],"out.bmp",info.height/2,info.height/2,info.height/2);
    //writeBMP( pere->fils[NE],"out.bmp",info,arq);
   //  writeBMP( pere->fils[SO],"out.bmp",info,arq);
    //  writeBMP( pere->fils[SE],"out.bmp",info,arq);
    prepareBMP("out.bmp",info,arq);
    int i,j;
    for(i=0;i<32;i++)
        for(j=0;j<32;j++)
            writeCouleur("out.bmp",NOIR,i,j,64);
    freeArbre(&pere);
    fclose(arq);

	return 0;
}

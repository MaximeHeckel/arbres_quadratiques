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
#include "arbre.h"
#include "algos.h"
#include "image.h"

int main(int argc, char * argv[])
{
    /*
    //Arbre mon_fils = creerArbre(Feuille);
    Arbre pere = inserer(NULL,SO,NOIR);
  //  print(pere);
    Arbre fils = inserer(pere,SE,BLANC);
    print(pere);
    //free(pere);
    printf("\n%d",nb_feuille(pere));

    freeArbre(pere);*/

    Image image = creerImage(4,4);
    colorier(image,0,2,2);
    print_image(image);

    freeImage(image);



	return 0;
}


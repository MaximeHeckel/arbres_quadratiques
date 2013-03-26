/*
 * @File : exo_rotation.c
 *
 * @Author : 
 *
 * @Summary :  
 *
 * @Version : 2013/03/20
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

struct arbre
{
    int val;
    struct arbre * filsg;
    struct arbre * filsd;
};
typedef struct arbre * Arbre;



Arbre creer()
{
    Arbre nouveau = NULL;
    nouveau = malloc(sizeof(struct arbre));

    nouveau->val = 0;

    nouveau->filsg = NULL;
    nouveau->filsg = NULL;

    return nouveau;
}
Arbre inserer(Arbre pere, int val,int direction)
{
    Arbre nouveau = creer();

    nouveau->val = val;

    if(pere == NULL)
    { return nouveau; }

    if(direction == 0)
    pere->filsg = nouveau;
    else
    pere->filsd = nouveau;


    return pere;
}
void print(Arbre arbre,int i)
{
    if(arbre == NULL)
    return ;
    
    int j;
    for(j=0;j<i;j++)
    printf("\t");

    printf("|%d",arbre->val);
    if(arbre->filsg != NULL)
    {	
    	printf("\n");
    	print(arbre->filsg,i+1);
    }
    if(arbre->filsd != NULL)
    {	
    	printf("\n");
    	print(arbre->filsd,i+1);
    }
}

Arbre rotationG(Arbre arbre)
{
	Arbre pivot = arbre->filsd;
	arbre->filsd = pivot->filsg;
	pivot->filsg = arbre;
	arbre = pivot;
	return arbre;

}

Arbre rotationD(Arbre arbre)
{
	Arbre pivot = arbre->filsg;
	arbre->filsg = pivot->filsd;
	pivot->filsd = arbre;
	arbre = pivot;
	return arbre;

}


int main(int argc, char * argv[])
{
	Arbre pere = inserer(NULL,5,0);
        	Arbre filsg = inserer(NULL,2,0);
        		Arbre filsgd = inserer(NULL,4,1);
				Arbre filsgdg = inserer(filsgd,3,0);
		        Arbre filsgg = inserer(filsg,1,0);
        	Arbre filsd = inserer(pere,6,1);


        pere->filsg = filsg;
	filsg->filsd = filsgd;

	print(pere,1);
	printf("\n\n\n\n");
	print(rotationD(pere),1);
	return 0;
}


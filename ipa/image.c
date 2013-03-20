#include "image.h"

Image tracerImage(int hauteur, int largeur)
{
	Image picture=malloc(sizeof(struct image));
	picture->largeur=largeur;
	picture->hauteur=hauteur;
	picture->pixel_tab=malloc(sizeof(struct pixel)*largeur);
	int i,j = 0;
	for(j=0; j<largeur; j++)
	{
		picture->pixel_tab[j]=malloc(sizeof(struct pixel)*hauteur);
	}
	for(j=0;j<largeur; j++ )
	{
		for(i=0;i<hauteur;i++)
		{
			picture->pixel_tab[i][j].col=BLANC;
		}
	}
	return picture;
}

Image colorier(Image picture, Couleur couleur,int i,int j)
{
	assert(picture !=NULL);
	if(i < picture->hauteur && j < picture->largeur)
	{
		picture->pixel_tab[i][j].col=couleur;
	}
	else
	{
		perror("Le pixel choisi est en dehors de l'image");
	}
	return picture;
}


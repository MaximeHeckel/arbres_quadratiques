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
		    Coordonnnee c = {i,j};
		    Pixel p = {c,BLANC};
			picture->pixel_tab[i][j]=p;
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

void print_pixel(Pixel p)
{
    printf(" (%d,%d, %d) ",p.coord.x, p.coord.y, p.col);
}
void print_image(Image img)
{
    int i,j;
    for(i=0; i<img->hauteur; i++)
    {
        for(j=0; j<img->largeur; j++)
        {
            print_pixel(img->pixel_tab[i][j]);
        }
        printf("\n");
    }
}

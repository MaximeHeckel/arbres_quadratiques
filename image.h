#include "const.h"


struct coord
{
	int x;
	int y;
};

typedef struct coord Coordonnnee;

struct pixel
{
	Coordonnnee coord;
	Couleur col;
};
typedef struct pixel Pixel;

struct image
{
	Pixel **pixel_tab;
	int hauteur;
	int largeur;

};

typedef struct image *Image;

void print_image(Image img);
void print_pixel(Pixel p);
void colorier(Image picture, Couleur couleur,int i,int j);
Image creerImage(int hauteur, int largeur);
void freeImage(Image img);

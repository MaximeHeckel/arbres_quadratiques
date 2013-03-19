#include "arbre.h"
struct coord
{
	float x;  //Ou int ?????
	float y;
};

typedef struct coord Coordonnnee;

struct rect
{
	float hauteur;
	float largeur;
};

typedef struct rect Quadrant;

struct image
{	
	int nb_pixels;
	Quadrant contour;
};

typedef struct image Image;

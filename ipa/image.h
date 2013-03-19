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
	Coordonnee pixels;
	Quadrant contour;
};

typedef struct image Image;

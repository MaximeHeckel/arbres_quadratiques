#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum coul {NOIR,BLANC,NON_UNI};
enum dir {NO,NE,SO,SE};
enum genre { Feuille, Noeud };
enum bool {false, true};

typedef enum coul Couleur;
typedef enum dir Direction;
typedef enum genre Genre;
typedef enum bool bool;
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

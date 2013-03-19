#include "image.h"

Image tracerImage(float hauteur, float largeur)
{
	Image picture;
	picture.contour.largeur=largeur;
	picture.contour.hauteur=largeur;
	picture.nb_pixels = 0; // Histoire de mettre quelque chose
	return picture;
}
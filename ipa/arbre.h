#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED


#include "bmp.h"
#include "algos.h"
#include "const.h"


struct arbre
{
    Direction direction;
    Couleur couleur;
    Genre genre;
    struct arbre * fils[NB_FILS];
};
typedef struct arbre * Arbre;


Direction getDirection(Arbre arbre);
Couleur getCouleur(Arbre arbre);
Arbre getFils(Arbre arbre,Direction dir);


void setDirection(Arbre arbre, Direction direction);
void setCouleur(Arbre arbre, Couleur couleur);
void setFils(Arbre pere,Arbre fils, Direction dir);


bool is_feuille(Arbre arbre);
bool is_noeud(Arbre arbre);


void print(Arbre arbre);

Arbre inserer(Arbre arbre, Direction direction, Couleur couleur);

Arbre creerArbre();


void freeArbre(Arbre arbre);

Arbre MatriceToArbre(RGB** Matrice,Arbre pere, int h, int w);

#endif // ARBRE_H_INCLUDED




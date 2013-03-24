#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED


#include "bmp.h"
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
void printArbre(Arbre arbre,int i);

Arbre inserer(Arbre arbre, Direction direction, Couleur couleur);

Arbre creerArbre();


void freeArbre(Arbre * arbre);

Arbre MatriceToArbre(RGB** Matrice,Arbre pere, int h, int w);

int max(int a, int b);
int countLevelBranch(Arbre arbre,Direction dir);
Couleur getCouleurBranches(Arbre arbre, Direction dir);
Arbre goToLevel(Arbre arbre, Direction dir,int level);
bool isUni(Arbre arbre);
void unification(Arbre arbre);
int hauteur (Arbre arbre);
int nb_feuille(Arbre arbre);
bool is_equilibre(Arbre arbre);

float moyenne(int a,int b, int c);
int rgb_to_nb(int r, int g, int b);

RGB** ArbreToMatrice(Arbre arbre);
int calcDimensionMatrice(Arbre arbre);

#endif // ARBRE_H_INCLUDED




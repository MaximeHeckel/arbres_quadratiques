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
Couleur getCouleurBranches(Arbre arbre, Direction dir);

void setDirection(Arbre arbre, Direction direction);
void setCouleur(Arbre arbre, Couleur couleur);
void setFils(Arbre pere,Arbre fils, Direction dir);

bool isEquilibre(Arbre arbre);
bool isUni(Arbre arbre);
bool is_feuille(Arbre arbre);
bool is_noeud(Arbre arbre);
bool isUni(Arbre arbre);
bool is_equilibre(Arbre arbre);

int hauteur(Arbre arbre);
int nb_feuille(Arbre arbre);
int countLevelBranch(Arbre arbre,Direction dir);

void print(Arbre arbre);

Arbre inserer(Arbre arbre, Direction direction, Couleur couleur);
Arbre unification(Arbre arbre);
Arbre creer();

Arbre goToLevel(Arbre arbre, Direction dir,int level);

void free_arbre(Arbre arbre);

Arbre MatriceToArbre(RGB** Matrice, int precision,Arbre newArbre);

#endif // ARBRE_H_INCLUDED




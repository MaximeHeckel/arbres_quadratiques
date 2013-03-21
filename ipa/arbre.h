#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bmp.h"

#define NB_FILS 4

enum coul {NOIR,BLANC,NON_UNI};
enum dir {NO,NE,SO,SE};
enum genre { Feuille, Noeud };
enum bool {false, true};

typedef enum coul Couleur;
typedef enum dir Direction;
typedef enum genre Genre;
typedef enum bool bool;

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
bool isEquilibre(Arbre arbre);
bool isUni(Arbre arbre);
void print(Arbre arbre);
Arbre inserer(Arbre arbre, Direction direction, Couleur couleur);

bool is_feuille(Arbre arbre);
bool is_noeud(Arbre arbre);
int hauteur(Arbre arbre);
int nb_feuille(Arbre arbre);
int countLevelBranch(Arbre arbre,Direction dir);
Couleur getCouleurBranches(Arbre arbre, Direction dir);
Arbre goToLevel(Arbre arbre, Direction dir,int level);
bool isUni(Arbre arbre);
Arbre unification(Arbre arbre);
bool is_equilibre(Arbre arbre);
void free_arbre(Arbre arbre);
Arbre copie(Arbre arbre);
Arbre creer();
Arbre MatriceToArbre(RGB** Matrice, int precision,Arbre newArbre);

#endif // ARBRE_H_INCLUDED




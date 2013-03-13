#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NB_FILS 4

enum coul {NOIR,BLANC,NON_UNI};
enum dir {NO,NE,SO,SE};
enum bool {false, true};

typedef enum coul Couleur;
typedef enum dir Direction;
typedef enum bool bool;

struct arbre
{
    Direction direction;
    Couleur couleur;
    struct arbre* fils[NB_FILS];
};
typedef struct arbre * Arbre;


Direction getDirection(Arbre arbre);
Couleur getCouleur(Arbre arbre);
Arbre getFils(Arbre arbre, int numero);
void setDirection(Arbre arbre, Direction direction);
void setCouleur(Arbre arbre, Couleur couleur);
void setFils(Arbre pere,Arbre fils, int numero);
bool isEquilibre(Arbre arbre);
bool isUni(Arbre arbre);
void print(Arbre arbre);
Arbre inserer(Arbre arbre, Direction direction, Couleur couleur,int numero);


#endif // ARBRE_H_INCLUDED

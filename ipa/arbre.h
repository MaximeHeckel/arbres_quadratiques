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
/*typedef enum dir Direction;
typedef enum bool bool;

struct arbre
{
    Direction direction;
    Couleur couleur;
    struct arbre ** fils;
};
typedef struct arbre * Arbre;*/

/* NOUVELLE STRUCTURE */
enum cas_arbre{Feuille,Noeud};

union union_arbre {
	int couleur;
	arbre_quadratique *filsNO, *filsNE, *filsSO, *filsSE;
};

typedef struct donnee_arbre Arbre;

struct donnee_arbre{
	enum cas_arbre genre;
	union union_arbre valeur;
};

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

bool is_feuille(Arbre arbre);
bool is_noeud(Arbre arbre);
void free_arbre(Arbre arbre);
Arbre copie(Arbre arbre);
Arbre creer();

#endif // ARBRE_H_INCLUDED




#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED


#include "bmp.h"
#include "const.h"


struct arbre
{
    Couleur couleur;
    struct arbre * fils[NB_FILS];
};
typedef struct arbre * Arbre;




bool is_feuille(Arbre arbre);
bool is_noeud(Arbre arbre);

void print(Arbre arbre);
void printArbre(Arbre arbre,int i);

Arbre inserer(Arbre arbre, Direction direction, Couleur couleur);

Arbre creerArbre();


void freeArbre(Arbre * arbre);

Arbre MatriceToArbre(RGB** Matrice,Arbre pere, int h, int w);

int max(int a, int b);
bool isUni(Arbre arbre);
void unification(Arbre arbre);
int hauteur (Arbre arbre);
int nb_feuille(Arbre arbre);

float moyenne(int a,int b, int c);
int rgb_to_nb(int r, int g, int b);

RGB** ArbreToMatrice(Arbre arbre);
int calcDimensionMatrice(Arbre arbre);
Arbre loadImage2(FILE* arq,int h, int w, int i,Arbre pere);
Arbre loadImage(FILE* arq,int h, int w);
void writeCouleur(char* name, Couleur col, int pos);
void writeBMP2(Arbre arbre,char* name,int pos,int h);
void writeBMP(Arbre arbre,char * name,INFOHEADER info,FILE* arq);
void prepareBMP(char * name,INFOHEADER info, FILE* arq);
#endif // ARBRE_H_INCLUDED




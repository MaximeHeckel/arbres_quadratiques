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

int max(int a, int b);
bool isUni(Arbre arbre);
Arbre unification(Arbre arbre);
int hauteur (Arbre arbre);
int nb_feuille(Arbre arbre);

float moyenne(int a,int b, int c);
int rgb_to_nb(int r, int g, int b);

Arbre loadImage2(char * name,int h_img, int x,int y,int h,Arbre pere);
Arbre loadImage(char * name,int h_img);
void writeCouleur(char* name, Couleur col, int i,int j,int pos);
void writeBMP2(Arbre arbre,char* name,int x,int y,int h,int h_img);
void writeBMP(Arbre arbre,char * name,INFOHEADER info);
void prepareBMP(char * name,INFOHEADER info, FILE* arq);
Couleur readCouleur(char* name, int i,int j,int h);
#endif // ARBRE_H_INCLUDED




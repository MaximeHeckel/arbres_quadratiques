#ifndef CONST_H_INCLUDED
#define CONST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



#define NB_FILS 4

enum coul {NOIR,BLANC,NON_UNI};
enum dir {NO,NE,SO,SE};
enum genre { Feuille, Noeud };
enum bool {false, true};

typedef enum coul Couleur;
typedef enum dir Direction;
typedef enum genre Genre;
typedef enum bool bool;

#endif // CONST_H_INCLUDED

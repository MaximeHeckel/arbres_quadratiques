#include "arbre.h"

bool is_feuille(Arbre arbre)
{
    assert(arbre != NULL);

    return (arbre->genre == Feuille);
}
bool is_noeud(Arbre arbre)
{
    assert(arbre != NULL);

    return (arbre->genre == Noeud);
}


Direction getDirection(Arbre arbre)
{
    assert(arbre != NULL);
    return arbre->direction;
}
Couleur getCouleur(Arbre arbre)
{
    assert(arbre != NULL);

    return arbre->couleur;
}
Arbre getFils(Arbre arbre, Direction dir)
{
    assert(arbre != NULL);

    return arbre->fils[dir];

}

void setDirection(Arbre arbre, Direction direction)
{
    assert(arbre != NULL);
    arbre->direction = direction;
}
void setCouleur(Arbre arbre, Couleur couleur)
{
    assert(arbre != NULL);

    arbre->couleur = couleur;
}
void setFils(Arbre pere,Arbre fils, Direction dir)  // <=== int numero -> dir Direction
{
    assert(pere != NULL);
    pere->fils[dir] = fils;
}

/*bool isUni(Arbre arbre)
{
    assert(arbre != NULL);
    return (getCouleur(arbre) != NON_UNI);
}*/
void print(Arbre arbre)
{
    printf("\n\n");
    printArbre(arbre,0);
}

void printArbre(Arbre arbre,int nb)
{
    if( arbre == NULL)
    { return; }

    int j;
    for(j=0; j<nb; j++)
               {printf("\t");}
     printf("|_");

    if(getCouleur(arbre) == NOIR)
    { printf("NOIR"); }
    else if(getCouleur(arbre) == BLANC)
    { printf("BLANC"); }
    else
    { printf("NON UNI"); }

    printf(" - ");

    if(getDirection(arbre) == NE)
    { printf("NE"); }
    else if(getDirection(arbre) == NO)
    { printf("NO"); }
    else if(getDirection(arbre) == SO)
    { printf("SO"); }
    else
    { printf("SE"); }

    printf(" - ");

    if(is_feuille(arbre))
    { printf("Feuille");}
    else
    { printf("Noeud");}


    for(j=0; j<NB_FILS; j++)
    {
        if(arbre->fils[j] != NULL)
        {
            printf("\n");
            printArbre(arbre->fils[j],nb+1);
        }

    }

}
Arbre inserer(Arbre pere, Direction direction, Couleur couleur)
{
    Arbre nouveau = creerArbre();

    nouveau->direction = direction;
    nouveau->couleur = couleur;
    nouveau->genre = Feuille;

    if(pere == NULL)
    { return nouveau; }

    pere->fils[direction] = nouveau;
    pere->genre = Noeud;

    return pere;
}

void freeArbre(Arbre arbre)
{
   // printf("\n***Free***");
    if(arbre == NULL)
    { return; }

    int i;
    for(i=0; i<NB_FILS; i++)
    {
       // printf("\n\t |_ ");
        freeArbre(arbre->fils[i]);
    }
   // printf("\t*Free fils*");

    free(arbre);

}


Arbre creerArbre()
{
    Arbre nouveau = NULL;
    nouveau = malloc(sizeof(struct arbre));
    assert(nouveau != NULL);

    nouveau->direction = 0;
    nouveau->couleur = NON_UNI;
    nouveau->genre=Feuille;

    int i;
    for(i=0; i<NB_FILS; i++)
    { nouveau->fils[i] = NULL; }

    return nouveau;
}

Arbre MatriceToArbre(RGB** Matrice,Arbre pere, int h, int w)
{
//Cas d'erreur
        if(Matrice == NULL)
        {
            printf("\nCas d'erreur");
            return NULL;
        }
//CAS D'ARRET: Si on est arrivé au niveau du pixel on affecte la couleur
        //Matrice est en fait un tableau 2D de hauteur 1 et largeur 1 -> 1 case
        if(h == 1 || w == 1)
        {
            printf("\nCas d'arret h: %d w: %d",h,w);
            Arbre feuille = creerArbre();
            feuille->couleur = rgb_to_nb(Matrice[0][0].RGB[0],Matrice[0][0].RGB[1],Matrice[0][0].RGB[2]);
            feuille->genre = Feuille;

            return feuille;
        }
//CAS GENERAL: récursivité
        printf("\nCas recursif . h: %d w: %d",h,w);
        RGB** subMatrice1 =MatriceToCell(Matrice ,h,w, 1);
        RGB** subMatrice2 =MatriceToCell(Matrice ,h,w, 2);
        RGB** subMatrice3 =MatriceToCell(Matrice ,h,w,3);
        RGB** subMatrice4 =MatriceToCell(Matrice ,h,w,4);

        //Affectation des fils (recursif)
        if(subMatrice1 != NULL)
        {
            pere->fils[NO] = creerArbre();
            pere->fils[NO]->genre = Noeud;
            pere->fils[NO] = MatriceToArbre(subMatrice1,pere->fils[NO],h/2,w/2);
        }
        if(subMatrice2 != NULL)
        {
            pere->fils[NE] = creerArbre();
            pere->fils[NE]->genre = Noeud;
            pere->fils[NE] = MatriceToArbre(subMatrice2,pere->fils[NE],h/2,w/2);
        }
        if(subMatrice3 != NULL)
        {
            pere->fils[SO] = creerArbre();
            pere->fils[SO]->genre = Noeud;
            pere->fils[SO] = MatriceToArbre(subMatrice3,pere->fils[SO],h/2,w/2);
        }
        if(subMatrice4 != NULL)
        {
            pere->fils[SE] = creerArbre();
            pere->fils[SE]->genre = Noeud;
            pere->fils[SE] = MatriceToArbre(subMatrice4,pere->fils[SE],h/2,w/2);
        }


        return pere;
}

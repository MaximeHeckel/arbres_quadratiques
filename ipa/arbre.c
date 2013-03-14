#include "arbre.h"

bool is_feuille(Arbre arbre)
{
    bool res=false;
    if(arbre.genre==Feuille)
    {
        res=true;
    }
    return res;
}
bool is_noeud(Arbre arbre)
{
    bool res=false;
    if(arbre.genre==Noeud)
    {
        res=true;
    }
    return res;
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
Arbre getFilsNO(Arbre arbre)
{
    assert(arbre != NULL);
    return arbre->filsNO;
}
Arbre getFilsNE(Arbre arbre)
{
    assert(arbre != NULL);
    return arbre->filsNE;
}
Arbre getFilsSO(Arbre arbre)
{
    assert(arbre != NULL);
    return arbre->filsSO;
}
Arbre getFilsSE(Arbre arbre)
{
    assert(arbre != NULL);
    return arbre->filsSE;
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
void setFils(Arbre pere,Arbre fils, int numero)
{
    assert(pere != NULL);
    pere->fils[numero] = fils;
}

bool isUni(Arbre arbre)
{
    assert(arbre != NULL);
    return getCouleur(arbre) != NON_UNI;
}

void print(Arbre arbre)
{
    if( arbre == NULL)
    { return; }

   // printf("\n");

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

    int i;
    for(i=0; i<NB_FILS; i++)
    {
        if(arbre->fils[i] != NULL)
        {
             printf("\n\t |_ ");
             print(arbre->fils[i]);
        }

    }

}
Arbre inserer(Arbre arbre, Direction direction, Couleur couleur, int numero)
{
    Arbre nouveau = creer();

    nouveau->direction = direction;
    nouveau->couleur = couleur;

    if(arbre == NULL)
    { return nouveau; }

    arbre->fils[numero] = nouveau;

    return arbre;
}

void free_arbre(Arbre arbre)
{
    printf("***Free***");
    if(arbre == NULL)
    { return; }

    int i;
    for(i=0; i<NB_FILS; i++)
    {
        printf("\n\t |_ ");
        free_arbre(arbre->fils[i]);
    }
    printf("\t*Free fils*");
    free(arbre->fils);
    free(arbre);

}

Arbre copie(Arbre arbre)
{
    assert(arbre != NULL);

    Arbre res = creer();

    res->couleur = arbre->couleur;
    res->direction = arbre->direction;

    int i;
    for(i=0; i<NB_FILS; i++)
    {
        if(arbre->fils[i] != NULL)
        res->fils[i] = copie(arbre->fils[i]);
    }
    return res;
}

Arbre creer()
{
    Arbre nouveau = NULL;
    nouveau = (Arbre) malloc(sizeof(Arbre));
    assert(nouveau != NULL);

    nouveau->direction = 0;
    nouveau->couleur = 0;
    nouveau->fils = (Arbre) malloc(NB_FILS * sizeof(Arbre));
    int i;
    for(i=1; i<=NB_FILS; i++)
    { nouveau->fils[i] = NULL; }

    return nouveau;
}

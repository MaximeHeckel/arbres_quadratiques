#include "arbre.h"

bool is_feuille(Arbre arbre)
{
    bool res=false;
    if(arbre->genre==Feuille)
    {
        res=true;
    }
    return res;
}
bool is_noeud(Arbre arbre)
{
    bool res=false;
    if(arbre->genre==Noeud)
    {
        res=true;
    }
    return res;
}


/*Couleur getFeuille(Arbre arbre)
{
    assert(arbre!=NULL);
    Arbre NO = arbre->fils[NO];
    Arbre SO = arbre->fils[SO];
    Arbre NE = arbre->fils[NE];
    Arbre SE = arbre->fils[SE];

    while(arbre != Feuille)
    {
        getFeuille(NO);
        getFeuille(SO);
        getFeuille(NE);
        getFeuille(SE);
    }

}*/
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

bool isUni(Arbre arbre)
{
    assert(arbre != NULL);
    return (getCouleur(arbre) != NON_UNI);
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
Arbre inserer(Arbre pere, Direction direction, Couleur couleur)
{
    Arbre nouveau = creer();

    nouveau->direction = direction;
    nouveau->couleur = couleur;

    if(pere == NULL)
    { return nouveau; }

    pere->fils[direction] = nouveau;

    return pere;
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
    /*if(arbre->fils != NULL)
    {free(arbre->fils);}*/
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
    //nouveau->fils = (Arbre) malloc(NB_FILS * sizeof(Arbre));
    int i;
    for(i=0; i<NB_FILS; i++)
    { nouveau->fils[i] = NULL; }

    return nouveau;
}

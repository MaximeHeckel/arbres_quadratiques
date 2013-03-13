#include "arbre.h"

bool is_feuille(Arbre arbre)
{
    if(arbre->fils[]!=NULL)
    {
        return false;
    }
    else true;
}
bool is_noeud(Arbre arbre)
{
    if(arbre->fils[]!=NULL)
    {
        return true;
    }
    else false;
}
couleur contenu_elem(Abre arbre)
{
    Arbre temp=arbre;
    while(temp->fils[]!=NULL)
    {
        return temp->couleur;
        temp=temp->fils[];
    }
    return temp->couleur;
}
Arbre sous_arbre_NO(Arbre arbre){
    Arbre res=malloc(sizeof(Arbre));
    if(is_noeud(arbre)){
        res=arbre.NO;
        res=res->fils[];  /* Pas sur s'il faut utilisé la structure comme ca ou pas */
    }
    return res;
}
Arbre sous_arbre_NE(Arbre arbre){
    Arbre res=malloc(sizeof(Arbre));
    if(is_noeud(arbre)){
        res=arbre.NE;
        res=res->fils[];  /* Pas sur s'il faut utilisé la structure comme ca ou pas */
    }
    return res;
}
Arbre sous_arbre_SO(Arbre arbre){
    Arbre res=malloc(sizeof(Arbre));
    if(is_noeud(arbre)){
        res=arbre.SO;
        res=res->fils[];  /* Pas sur s'il faut utilisé la structure comme ca ou pas */
    }
    return res;
}
Arbre sous_arbre_SE(Arbre arbre){
    Arbre res=malloc(sizeof(Arbre));
    if(is_noeud(arbre)){
        res=arbre.SE;
        res=res->fils[];  /* Pas sur s'il faut utilisé la structure comme ca ou pas */
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
Arbre getFils(Arbre arbre, int numero)
{
    assert(arbre != NULL);
    return arbre->fils[numero-1];
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
    pere->fils[numero-1] = fils;
}

bool isEquilibre(Arbre arbre);
bool isUni(Arbre arbre)
{
    assert(arbre != NULL);
    return getCouleur(arbre) != NON_UNI;
}

void print(Arbre arbre)
{
    if( arbre == NULL)
    { return; }

    printf("\n");

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
    for(i=1; i<=NB_FILS; i++)
    {
        if(getFils(arbre,i) != NULL)
        {
             printf("\n\t |_ ");
             print(getFils(arbre,i));
        }

    }

}
Arbre inserer(Arbre arbre, Direction direction, Couleur couleur, int numero)
{
    Arbre nouveau = NULL;
    nouveau = (Arbre) malloc(sizeof(Arbre));
    assert(nouveau != NULL);

    nouveau->direction = direction;
    nouveau->couleur = couleur;
    nouveau->fils = (Arbre) malloc(NB_FILS * sizeof(Arbre));
    int i;
    for(i=1; i<=NB_FILS; i++)
    { nouveau->fils[i] = NULL; }

    if(arbre == NULL)
    { return nouveau; }

    arbre->fils[numero] = nouveau;

    return arbre;
}

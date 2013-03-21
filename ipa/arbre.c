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

    printf(" - ");

    if(is_feuille(arbre))
    { printf("Feuille");}
    else
    { printf("Noeud");}

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
    nouveau->genre = Feuille;

    if(pere == NULL)
    { return nouveau; }

    pere->fils[direction] = nouveau;
    pere->genre = Noeud;

    return pere;
}

void free_arbre(Arbre arbre)
{
   // printf("\n***Free***");
    if(arbre == NULL)
    { return; }

    int i;
    for(i=0; i<NB_FILS; i++)
    {
       // printf("\n\t |_ ");
        free_arbre(arbre->fils[i]);
    }
   // printf("\t*Free fils*");

    free(arbre);

}

Arbre copie(Arbre arbre)
{
    assert(arbre != NULL);

    Arbre res = creer();

    res->couleur = arbre->couleur;
    res->direction = arbre->direction;
    res->genre = arbre->genre;

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
    nouveau = malloc(sizeof(struct arbre));
    assert(nouveau != NULL);

    nouveau->direction = 0;
    nouveau->couleur = 0;
    nouveau->genre=Feuille;

    int i;
    for(i=0; i<NB_FILS; i++)
    { nouveau->fils[i] = NULL; }

    return nouveau;
}

Arbre MatriceToArbre(RGB** Matrice, int precision,Arbre newArbre)
{
     int k=1;
     while(k!=precision)
     {
        RGB** subMatrice1 =MatriceToCell(Matrice ,sizeof(RGB*),sizeof(RGB*), 1);
        RGB** subMatrice2 =MatriceToCell(Matrice ,sizeof(RGB*),sizeof(RGB*), 2);
        RGB** subMatrice3 =MatriceToCell(Matrice ,sizeof(RGB*),sizeof(RGB*), 3);
        RGB** subMatrice4 =MatriceToCell(Matrice ,sizeof(RGB*),sizeof(RGB*), 4);
        newArbre->fils[NO] = (Arbre)subMatrice1; //Affectation des fils 
        newArbre->fils[NE] = (Arbre)subMatrice2;
        newArbre->fils[SO] = (Arbre)subMatrice3;
        newArbre->fils[SE] = (Arbre)subMatrice4;
        MatriceToArbre(MatriceToCell(subMatrice1 ,sizeof(RGB*)/2,sizeof(RGB*)/2, 1),precision,(Arbre)subMatrice1);
        MatriceToArbre(MatriceToCell(subMatrice2 ,sizeof(RGB*)/2,sizeof(RGB*)/2, 2),precision,(Arbre)subMatrice2);
        MatriceToArbre(MatriceToCell(subMatrice3 ,sizeof(RGB*)/2,sizeof(RGB*)/2, 3),precision,(Arbre)subMatrice3);
        MatriceToArbre(MatriceToCell(subMatrice4 ,sizeof(RGB*)/2,sizeof(RGB*)/2, 4),precision,(Arbre)subMatrice4);
        k++;
     }

    //!!!! Prendre en compte les feuilles et leur couleur !!!!
     return newArbre;
}
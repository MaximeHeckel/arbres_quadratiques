#include "arbre.h"

bool is_feuille(Arbre arbre)
{
    assert(arbre != NULL);
    int i=0;
    while(arbre->fils[i] != NULL)
        i++;

    return (i == 3) ? true:false;
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
          //  printf("\nCas d'erreur");
            return NULL;
        }
//CAS D'ARRET: Si on est arrivé au niveau du pixel on affecte la couleur
        //Matrice est en fait un tableau 2D de hauteur 1 et largeur 1 -> 1 case
        if(h == 1 || w == 1)
        {
          //  printf("\nCas d'arret h: %d w: %d",h,w);
            Arbre feuille = creerArbre();
            feuille->couleur = rgb_to_nb(Matrice[0][0].RGB[0],Matrice[0][0].RGB[1],Matrice[0][0].RGB[2]);
            feuille->genre = Feuille;

            return feuille;
        }
//CAS GENERAL: récursivité
       // printf("\nCas recursif . h: %d w: %d",h,w);
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


int max(int a, int b)
{
    return (a>b) ? a:b;
}


int countLevelBranch(Arbre arbre,Direction dir)
{
    assert(arbre != NULL);
    int i;
    while(getFils(arbre,dir)->genre !=Feuille)
    {
        i++;
        arbre=getFils(arbre,dir);
    }
    return i;
}

Couleur getCouleurBranches(Arbre arbre, Direction dir)
{
	assert(arbre != NULL);
	int i;
	int count = countLevelBranch(arbre,dir);
	Arbre temp = arbre;
	for(i=0;i<count;i++)
	{
		temp=getFils(temp,dir);
	}
	return getCouleur(temp);

}

Arbre goToLevel(Arbre arbre, Direction dir,int level)
{
	assert(arbre != NULL);
	int i;
	Arbre temp = arbre;
	for(i=0; i<level; i++)
	{
		temp=getFils(temp,dir);
	}
	return temp;
}

bool isUni(Arbre arbre)
{
	assert(arbre != NULL);

	Couleur couleur_no = getCouleur(getFils(arbre,NO));
	Couleur couleur_ne = getCouleur(getFils(arbre,NE));
	Couleur couleur_so = getCouleur(getFils(arbre,SO));
	Couleur couleur_se = getCouleur(getFils(arbre,SE));

    if(couleur_no == couleur_ne
    && couleur_so == couleur_se
    && couleur_no == couleur_so)
    { return true; }
	else
	{ return false; }
}

Arbre unification(Arbre arbre)
{

	assert(arbre != NULL);
	if(isUni(arbre))
	{
		Couleur temp = getCouleur(getFils(arbre,NO));
		freeArbre(getFils(arbre,NO));
		freeArbre(getFils(arbre,NE));
		freeArbre(getFils(arbre,SO));
		freeArbre(getFils(arbre,SE));
		arbre->couleur= temp;

	}
	return arbre;
}

int hauteur (Arbre arbre){

	int res=0;
	if(arbre == NULL || is_feuille(arbre) )
	{
		res=0;
	}
	else
	{
        int hauteur1 = max(hauteur(getFils(arbre,NO)),hauteur(getFils(arbre,SE)));
        int hauteur2 = max(hauteur(getFils(arbre,NO)),hauteur(getFils(arbre,NE)));
		res=1+max(hauteur1,hauteur2);
	}
	return res;
}

int nb_feuille(Arbre arbre){
	int res=0;
	if(arbre == NULL || is_feuille(arbre))
	{
		res=1;
	}
	else
	{
		res += nb_feuille(getFils(arbre,SO)) + nb_feuille(getFils(arbre,SE)) + nb_feuille(getFils(arbre,NO)) + nb_feuille(getFils(arbre,NE));
	}
	return res;
}

bool is_equilibre(Arbre arbre){
	int res=false;

	if(is_feuille(arbre))
	{
		res=true;
	}
	else
	{
	    int hNO = hauteur(getFils(arbre,NO));
	    int hNE = hauteur(getFils(arbre,NE));
	    int hSO = hauteur(getFils(arbre,SO));
	    int hSE = hauteur(getFils(arbre,SE));

		if(abs(hNO - hNE) <=1
        && abs(hSO - hSE) <=1
        && abs(hNO - hNE)<=1)
		{
				res=true;
        }
	}
	return res;
}
float moyenne(int a,int b, int c)
{
 return (float) (a+b+c)/3.;
}

int rgb_to_nb(int r, int g, int b)
{
// Si la moyenne des 3 couleurs est < 127 (moitié de 255) alors on renvoie blanc (0) sinon noir (1)
  return (moyenne(r,g,b) < 127) ? 0 : 1;
}
RGB** ArbreToMatrice(Arbre arbre)
{
//Cas d'erreur
        if(arbre == NULL)
        {
          //  printf("\nCas d'erreur");
            return NULL;
        }
        int h = hauteur(arbre);
        int hsize=1;
        int i;
        //Pow : hauteur matrice = 2^(hauteur arbre + 1);
        for(i=1; i<=h+1; i++)
        {
            hsize *= 2;
        }

        RGB ** Matrice = createMatrix(h,h);



        return Matrice;
}

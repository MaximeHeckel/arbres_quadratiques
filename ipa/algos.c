#include "arbre.h"
#include "algos.h"

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
        i=i++;
        arbre=getFils(arbre,dir);
    }
    return i;
}

Couleur getCouleurBranches(Arbre arbre, Direction dir)
{
	assert(arbre != NULL);
	int i;
	for(i=0;i<countLevelBranch(arbre,dir);i++)
	{
		arbre=getFils(arbre,dir);
	}
	return getCouleur(arbre);

}

Arbre goToLevel(Arbre arbre, Direction dir,int level)
{
	assert(arbre != NULL);
	int i;
	for(i=0; i<level; i++)
	{
		arbre=getFils(arbre,dir);
	}
	return arbre;
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
		free_arbre(getFils(arbre,NO));
		free_arbre(getFils(arbre,NE));
		free_arbre(getFils(arbre,SO));
		free_arbre(getFils(arbre,SE));
		arbre->couleur= temp;

	}
	return arbre;
}

int hauteur (Arbre arbre){

	int res;
	if(arbre == NULL || is_feuille(arbre) )
	{
		res=0;
	}
	else
	{
        int hauteur1 = max(hauteur(getFils(arbre,NO)),hauteur(getFils(arbre,SE)));
        int hauteur2 = (max(hauteur(getFils(arbre,NO)),hauteur(getFils(arbre,NE))));
		res=1+max(hauteur1,hauteur2);
	}
	return res;
}

int nb_feuille(Arbre arbre){
	int res;
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
	int i;
	if(is_feuille(arbre))
	{
		res=true;
	}
	else
	{
		if((abs(hauteur(getFils(arbre,NO))-hauteur(getFils(arbre,NE)))<=1)
			&& (abs(hauteur(getFils(arbre,SO)))-hauteur(getFils(arbre,SE)))<=1)
		{
			if((abs(hauteur(getFils(arbre,NO))-(hauteur(getFils(arbre,SO)))))<=1);
			{
				res=true;
			}
		}
	}
	return res;
}

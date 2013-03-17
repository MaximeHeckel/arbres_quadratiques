#include "arbre.h"

static int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


int countLevelBranch(Arbre arbre,Direction dir)
{
    assert(arbre.genre!=Null);
    int i;
    while(getFils(arbre,dir).genre !=Feuille)
    {
        i=i++;
        arbre=getFils(arbre,dir);
    }
    return i;
}

Couleur getCouleurBranches(Arbre arbre, Direction dir)
{
	assert(arbre.genre!=Null);
	int i;
	for(i=0;i<countLevelBranch(arbre,dir);i++)
	{
		arbre=getFils(arbre,dir);
	}
	return getCouleur(arbre);

}

Arbre goToLevel(Arbre arbre, Direction dir,int level)
{
	assert(arbre.genre!=Null); // Null est juste un genre que j'ai mis pour que ca compile 
	int i;
	for(i=0; i<level; i++)
	{
		arbre=getFils(arbre,dir);
	}
	return arbre;
}

bool isUni(Arbre arbre)
{
	bool res=false;
	assert(arbre.genre!=Null);
	if(getFils(arbre,NO).valeur.couleur==getFils(arbre,NE).valeur.couleur)
	{
		if(getFils(arbre,SO).valeur.couleur==getFils(arbre,SE).valeur.couleur)
		{
			res=true;
		}
	}
	return res;
}

Arbre unification(Arbre arbre)
{

	assert(arbre.genre!=Null);
	if(isUni(arbre))
	{
		arbre.valeur.couleur=getFils(arbre,NO).valeur.couleur;
		free_arbre(getFils(arbre,NO));
		free_arbre(getFils(arbre,NE));
		free_arbre(getFils(arbre,SO));
		free_arbre(getFils(arbre,SE));

	}
	return arbre;
}

int hauteur (Arbre arbre){
	int res;
	if( is_feuille(arbre))
	{
		res=0;
	}
	else
	{
		res=1+max(max(hauteur(getFils(arbre,NO)),hauteur(getFils(arbre,SE))),(max(hauteur(getFils(arbre,NO)),hauteur(getFils(arbre,NE)))));
	}
	return res;
}

int nb_feuille(Arbre arbre){
	int res;
	if(is_feuille(arbre))
	{
		res=1;
	}
	else
	{
		res=nb_feuille(getFils(arbre,SO))+nb_feuille(getFils(arbre,SE))+nb_feuille(getFils(arbre,NO))+nb_feuille(getFils(arbre,NE));
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
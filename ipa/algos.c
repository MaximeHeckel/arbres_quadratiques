#include "arbre.h"

static int max(int a, int b){
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int hauteur (Arbre arbre){
	int res;
	if( is_feuille(arbre))
	{
		res=0;
	}
	else
	{
		res=1+max(hauteur(sous_arbre_NO(arbre)),hauteur(sous_arbre_NE(arbre)),hauteur(sous_arbre_SO(arbre)),hauteur(sous_arbre_SE(arbre)));
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
		res=nb_feuille(sous_arbre_NO(arbre))+nb_feuille(sous_arbre_NE(arbre))+nb_feuille(sous_arbre_SO(arbre))+nb_feuille(sous_arbre_SE(arbre));
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
		if((abs((hauteur(getFils(arbre, 1)-hauteur(getFils(arbre,2)))<=1)
			&&(abs((hauteur(getFils(arbre,3))-hauteur(getFils(arbre,4)))<=1)))))
		{
			if((abs((hauteur(getFils(arbre, 1)-hauteur(getFils(arbre,3)))<=1)
			{
				res = true;
			}
		}
			
	}
	return res;
}
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
		res=1+max(hauteur(getFilsSO(arbre)),hauteur(getFilsSE(arbre)),hauteur(getFilsNO(arbre)),hauteur(getFilsNE(arbre)));
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
		res=nb_feuille(getFilsSO(arbre))+nb_feuille(getFilsSE(arbre))+nb_feuille(getFilsNO(arbre))+nb_feuille(getFilsNE(arbre));
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
		if((abs(hauteur(getFilsNO(arbre))-hauteur(getFilsNE(arbre)))<=1) 
			&& (abs(hauteur(getFilsSO))-hauteur(getFilsSE(arbre)))<=1)
		{
			if((abs(hauteur(getFilsNO(arbre))-(hauteur(getFilsSO(arbre)))))<=1);
			{
				res=true
			}
		}	
	}
	return res;
}
TODO:

- Corriger la fonction print() pour afficher correctement l'arbre (à la manière de "ps aux --forest"), peut-être faire une sous-fonction print(int niveau) pour savoir à quel niveau on est
- Faire plein de fonctions utiles aux arbres
- Faire la fonction estEquilibre()
- Modifier structure ( pas de couleur au NOEUD seulement au FEUILLE)
Struct proposée :

enum cas_arbre { Feuille, Noeud};

union union_arbre {
    
	int feuille;
	arbre_binaire_strict *filsNO, *filsNE *filsSO *filsSE;
};


struct donnee_arbre
{
	enum cas_arbre genre;
	union union_arbre valeur;
};

typedef struct donnee_arbre arbre_binaire_strict;

- Fonction est_régulier + conv

- Structure image ?

- Fonction colorer

- Fonction read_image 

- Faire une image noir et blanc sur paint!

- Fonction niveau de gris
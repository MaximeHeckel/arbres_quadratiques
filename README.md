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

###### Update : 14-03-13 :

- Nouvelle structure : fait

- Correction sur les fonctions déjà implémentées : fait

- Fonction is_Equilibré : fait

- Ajout de getFilsNO getFilsSO getFils NE et getFils NE : fait

- Reflexion sur la fonction profondeur( ou niveau ) : en cours

###### Update : 16-03-13 : 

- Ajout nouvelle structure 

- Correction de certains algos ( La majorité des tiens, Phillipe ne fonctionnent plus il faut les modifier)

- Ajout getToLevel getColorBranches getDepthBranches
 
###### Update : 18-03-13 : 

- Ajout des fonctions isUni et Unification 

- Code trouvé sur StackOverFlow pour la conversion d'une image en quadtree : 

				void divideAndConquer(Mat im, QuadTree &tree, int parent){
  				if(parent<0) 
    				return;
  				double min,max;
  				minMaxLoc(im,&min,&max);
  				if(max-min<0.01)
    				tree.addNode(parent,closed);
  				else{
    				tree.addNode(parent,open);
    				Mat im0=Mat(im,Range(0,image.rows/				2-1),Range(0,image.cols/2-1));
    				Mat im1=Mat(im,Range(image.rows/				2,image.rows),Range(0,image.cols/2-1));
    				Mat im2=Mat(im,Range(0,image.rows/				2-1),Range(image.cols/2,image.cols));
    				Mat im3=Mat(im,Range(image.rows/				2,image.rows),Range(image.cols/2-1,image.cols));
    				divideAndConquer(im0, tree, parent/4);
    				divideAndConquer(im1, tree, parent/4+1);
    				divideAndConquer(im2, tree, parent/4+2);
    				divideAndConquer(im3, tree, parent/4+3);
  				}
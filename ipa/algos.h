#ifndef ALGOS_H_INCLUDED
#define ALGOS_H_INCLUDED

int max(int a, int b);
int countLevelBranch(Arbre arbre,Direction dir);
Couleur getCouleurBranches(Arbre arbre, Direction dir);
Arbre goToLevel(Arbre arbre, Direction dir,int level);
bool isUni(Arbre arbre);
Arbre unification(Arbre arbre);
int hauteur (Arbre arbre);
int nb_feuille(Arbre arbre);
bool is_equilibre(Arbre arbre);

#endif // ALGOS_H_INCLUDED

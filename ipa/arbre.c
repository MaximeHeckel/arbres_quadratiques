#include "arbre.h"

bool is_feuille(Arbre arbre)
{
    assert(arbre != NULL);
    int i,j=0;
    for(i=0; i<NB_FILS; i++)
    {
        if(arbre->fils[i] == NULL)
            j++;
    }

    return (j == 4) ? true:false;
}
bool is_noeud(Arbre arbre)
{
    assert(arbre != NULL);

    return (!is_feuille(arbre));
}

void print(Arbre arbre)
{
    printf("\n\n");
    printArbre(arbre,0);
}

void printArbre(Arbre arbre,int nb)
{
    if( arbre == NULL)
    {
        return;
    }

    int j;
    for(j=0; j<nb; j++)
               {printf("\t");}
     printf("|_");

    if(arbre->couleur == NOIR)
    { printf("NOIR"); }
    else if(arbre->couleur == BLANC)
    { printf("BLANC"); }
    else
    { printf("NON UNI"); }

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

    nouveau->couleur = couleur;

    if(pere == NULL)
    { return nouveau; }

    pere->fils[direction] = nouveau;

    return pere;
}

void freeArbre(Arbre * arbre)
{

    //printf("\n***Free***");
    if(*arbre == NULL)
    { return; }

   // printf("\t*Free fils*");
     int i;
     for(i=0; i<NB_FILS; i++)
     {
       // printf("\n\t |_ ");
        freeArbre(&(*arbre)->fils[i]);
        //(*arbre)->fils[i] = NULL;
     }
    free(*arbre);
    *arbre = NULL;

}


Arbre creerArbre()
{
    Arbre nouveau = NULL;
    nouveau = malloc(sizeof(struct arbre));
    assert(nouveau != NULL);

    nouveau->couleur = NON_UNI;

    int i;
    for(i=0; i<NB_FILS; i++)
    { nouveau->fils[i] = NULL; }

    return nouveau;
}
/*
Arbre MatriceToArbre(RGB** Matrice,Arbre pere, int h, int w)
{
        assert(pere != NULL);
//Cas d'erreur
        if(Matrice == NULL)
        {
           fprintf(stderr,"\nCas d'erreur");
            return NULL;
        }
//CAS D'ARRET: Si on est arrivé au niveau du pixel on affecte la couleur
        //Matrice est en fait un tableau 2D de hauteur 1 et largeur 1 -> 1 case
        if(h == 1 || w == 1)
        {
          //  printf("\nCas d'arret h: %d w: %d",h,w);
            pere->couleur = rgb_to_nb(Matrice[0][0].RGB[0],Matrice[0][0].RGB[1],Matrice[0][0].RGB[2]);
           //pere->couleur = Matrice[0][0].RGB[0];

            return pere;
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
            pere->fils[NO] = MatriceToArbre(subMatrice1,pere->fils[NO],h/2,w/2);
        }
        if(subMatrice2 != NULL)
        {
            pere->fils[NE] = creerArbre();
            pere->fils[NE] = MatriceToArbre(subMatrice2,pere->fils[NE],h/2,w/2);
        }
        if(subMatrice3 != NULL)
        {
            pere->fils[SO] = creerArbre();
            pere->fils[SO] = MatriceToArbre(subMatrice3,pere->fils[SO],h/2,w/2);
        }
        if(subMatrice4 != NULL)
        {
            pere->fils[SE] = creerArbre();
            pere->fils[SE] = MatriceToArbre(subMatrice4,pere->fils[SE],h/2,w/2);
        }


        return pere;
}


int max(int a, int b)
{
    return (a>b) ? a:b;
}

bool isUni(Arbre arbre)
{
    assert(arbre != NULL);

    if(is_feuille(arbre))
        return true;


    Couleur couleur_no = arbre->fils[NO]->couleur;
    Couleur couleur_ne = arbre->fils[NE]->couleur;
    Couleur couleur_so = arbre->fils[SO]->couleur;
    Couleur couleur_se = arbre->fils[SE]->couleur;

    if(couleur_no == couleur_ne
    && couleur_so == couleur_se
    && couleur_no == couleur_so
    && couleur_no != NON_UNI)
    { return true; }
    else
    { return false; }
}

void unification(Arbre arbre)
{
	if(arbre == NULL)
        return;
    //printf("\n %d %d",isUni(arbre),arbre->couleur);

	if(isUni(arbre))
	{
		arbre->couleur = arbre->fils[NO]->couleur;
       // printf(" %d  ",arbre->couleur);
        freeArbre(&arbre->fils[NO]);
        freeArbre(&arbre->fils[NE]);
        freeArbre(&arbre->fils[SO]);
        freeArbre(&arbre->fils[SE]);
    }
    else
    {
        unification(arbre->fils[NO]);
        unification(arbre->fils[NE]);
        unification(arbre->fils[SO]);
        unification(arbre->fils[SE]);
        unification(arbre);
    }


}

int hauteur (Arbre arbre){

    int res=0;
    if(arbre == NULL || is_feuille(arbre) )
    {
        res=0;
    }
    else
    {
        int hauteur1 = max(hauteur(arbre->fils[NO]),hauteur(arbre->fils[SE]));
        int hauteur2 = max(hauteur(arbre->fils[NO]),hauteur(arbre->fils[NE]));
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
        res += nb_feuille(arbre->fils[SO]) + nb_feuille(arbre->fils[SE]) + nb_feuille(arbre->fils[NO]) + nb_feuille(arbre->fils[NE]);
    }
    return res;
}
*/
float moyenne(int a,int b, int c)
{
 return (float) (a+b+c)/3.;
}

int rgb_to_nb(int r, int g, int b)
{
// Si la moyenne des 3 couleurs est < 127 (moitié de 255) alors on renvoie noir (0) sinon blanc (1)
    //printf("\n%d %d %d",r,g,b);
  return (moyenne(r,g,b) > 127) ? 0 : 1;
}
/*
RGB** ArbreToMatrice(Arbre arbre)
{
//Cas d'erreur
        assert(arbre != NULL);

//Cas d'arret
        if(is_feuille(arbre))
        {
            Couleur col = arbre->couleur;
            RGB ** Matrice = createMatrix(1,1);
            Matrice[0][0].RGB[0] = col;
            Matrice[0][0].RGB[1] = col;
            Matrice[0][0].RGB[2] = col;
            return Matrice;
        }

        int hsize = calcDimensionMatrice(arbre);


        RGB ** Matrice = createMatrix(hsize,hsize);
        RGB ** sousMatriceNO;
        RGB ** sousMatriceNE;
        RGB ** sousMatriceSO;
        RGB ** sousMatriceSE;

        if(arbre->fils[NO] != NULL)
            sousMatriceNO = ArbreToMatrice(arbre->fils[NO]);

        if(arbre->fils[NE] != NULL)
            sousMatriceNE = ArbreToMatrice(arbre->fils[NE]);

        if(arbre->fils[SO] != NULL)
            sousMatriceSO = ArbreToMatrice(arbre->fils[SO]);

        if(arbre->fils[SE] != NULL)
            sousMatriceSE = ArbreToMatrice(arbre->fils[SE]);

        Matrice = fusionner(sousMatriceNO,sousMatriceNE,sousMatriceSO,sousMatriceSE,hsize,hsize);

        return Matrice;
}

int calcDimensionMatrice(Arbre arbre)
{
        int h = hauteur(arbre);
        int hsize=1;
        int i;

        //Pow : hauteur matrice = 2^(hauteur arbre + 1);
        for(i=1; i<=h+1; i++)
        {
            hsize *= 2;
        }
        return hsize;
}
*/
Arbre loadImage2(FILE* arq,int h, int w, int i,Arbre pere){
        assert(pere != NULL);

        long offset = 54;
        fseek(arq,SEEK_SET+offset,i);
        unsigned char tmp[3];


        if(h == 1 || w == 1)
        {
             fread(&tmp,sizeof(unsigned char)*3,1,arq);
             Couleur col = rgb_to_nb(tmp[0],tmp[1],tmp[2]);
             Arbre res = creerArbre();
             res->couleur = col;
             return res;
        }
        pere->fils[NO] = creerArbre();
        pere->fils[NE] = creerArbre();
        pere->fils[SO] = creerArbre();
        pere->fils[SE] = creerArbre();

        pere->fils[NO] = loadImage2(arq,h/2,w/2,1*h/4, pere->fils[NO]);
        pere->fils[NE] = loadImage2(arq,h/2,w/2,2*h/4, pere->fils[NE]);
        pere->fils[SO] = loadImage2(arq,h/2,w/2,3*h/4, pere->fils[SO]);
        pere->fils[SE] = loadImage2(arq,h/2,w/2,4*h/4, pere->fils[SE]);

        return pere;
}

Arbre loadImage(FILE* arq,int h, int w)
{
    Arbre pere = creerArbre();
    pere = loadImage2(arq,h,w,0,pere);
    return pere;
}

void writeBMP2(Arbre arbre,char* name,int pos,int h)
{
    assert(arbre != NULL);
    if(is_feuille(arbre))
    {
        writeCouleur(name,arbre->couleur,pos,pos,pos);
    }

    writeCouleur(name,arbre->fils[NO]->couleur,pos+1*h/4,pos,pos);
    writeCouleur(name,arbre->fils[NE]->couleur,pos + 2*h/4,pos,pos);
    writeCouleur(name,arbre->fils[SO]->couleur,pos + 3*h/4,pos,pos);
    writeCouleur(name,arbre->fils[SE]->couleur,pos + 4*h/4,pos,pos);

}
void writeBMP(Arbre arbre,char * name,INFOHEADER info,FILE* arq)
{
    prepareBMP("out.bmp",info,arq);
    writeBMP2(arbre,name,0,info.height);
}
void writeCouleur(char* name,Couleur col, int i,int j,int h)
{
    int pos = i * h + j;
    printf("\n %d %d %d    %d", i,j,h,pos);
    FILE * file = fopen(name,"r+");
    assert(file != NULL);

    long offset = 54;
    fseek(file, SEEK_SET + offset + 3*pos, 0);

    unsigned char tmp[3];

    if(col == NOIR)
    {
        tmp[0] = 0;
        tmp[1] = 0;
        tmp[2] = 0;
    }
    else
    {
        tmp[0] = 255;
        tmp[1] = 255;
        tmp[2] = 255;
    }
    fwrite(&tmp,sizeof(unsigned char)* 3,1,file);
   // printf("\n %d",res);
    fclose(file);
}
void prepareBMP(char * name, INFOHEADER info, FILE* arq)
{
    FILE* out=NULL;
	long pos = 51;

	char header[54];
	fseek(arq,0,0);
	fread(header,54,1,arq);
	out = fopen(name,"w");
    assert(out != NULL);
	fseek(out,0,0);
	fwrite(header,54,1,out);


    unsigned char tmp[3]={255,255,255};
    int i,j;
    for(i=0;i<info.height;i++){
		for(j=0;j<info.width;j++){
			pos+= 3;
			fseek(out,pos,0);
			fwrite(&tmp,(sizeof(unsigned char) * 3),1,out);
		}
	}
	fflush(out);
	fclose(out);
}

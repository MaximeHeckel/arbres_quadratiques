#include "arbre.h"

bool is_feuille(Arbre arbre)
{
    assert(arbre != NULL);

    return (arbre->fils[NO] == NULL)
    && (arbre->fils[NE] == NULL)
    && (arbre->fils[SO] == NULL)
    && (arbre->fils[SE] == NULL);
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


int max(int a, int b)
{
    return (a>b) ? a:b;
}

bool isUni(Arbre arbre)
{
    assert(arbre != NULL);

  //  if(is_feuille(arbre))
    //    return true;


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

Arbre unification(Arbre arbre)
{
    assert(arbre != NULL);
    //printf("\n %d %d",isUni(arbre),arbre->couleur);
    if(is_feuille(arbre))
        return arbre;

	if(isUni(arbre))
	{
		arbre->couleur = arbre->fils[NO]->couleur;
       // printf(" %d  ",arbre->couleur);
        freeArbre(&arbre->fils[NO]);
        freeArbre(&arbre->fils[NE]);
        freeArbre(&arbre->fils[SO]);
        freeArbre(&arbre->fils[SE]);
        return arbre;
    }
    else
    {
        unification(arbre->fils[NO]);
        unification(arbre->fils[NE]);
        unification(arbre->fils[SO]);
        unification(arbre->fils[SE]);
        return arbre;
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

float moyenne(int a,int b, int c)
{
 return (float) (a+b+c)/3.;
}

int rgb_to_nb(int r, int g, int b)
{
// Si la moyenne des 3 couleurs est < 127 (moitié de 255) alors on renvoie noir (0) sinon blanc (1)
    //printf("\n%d %d %d",r,g,b);
  return (moyenne(r,g,b) < 127) ? 0 : 1;
}

Arbre loadImage2(char * name,int h_img, int x,int y,int h,Arbre pere)
{
        assert(pere != NULL);

        if(h == 1)
        {
             Arbre res = creerArbre();
             res->couleur = readCouleur(name,x,y,h_img);

             return res;
        }
        pere->fils[NO] = creerArbre();
        pere->fils[NE] = creerArbre();
        pere->fils[SO] = creerArbre();
        pere->fils[SE] = creerArbre();

        pere->fils[NO] = loadImage2(name,h_img,x,y+h/2, h/2,pere->fils[NO]);
        pere->fils[NE] = loadImage2(name,h_img,x+h/2,y+h/2, h/2,pere->fils[NE]);
        pere->fils[SO] = loadImage2(name,h_img,x,y,h/2, pere->fils[SO]);
        pere->fils[SE] = loadImage2(name,h_img,x+h/2,y, h/2,pere->fils[SE]);

        return pere;
}

Arbre loadImage(char * name,int h_img)
{
    Arbre pere = creerArbre();
    pere = loadImage2(name,h_img,0,0,h_img,pere);
    return pere;
}


void writeBMP2(Arbre arbre,char* name,int x,int y,int h,int h_img)
{
    if(arbre == NULL)
        return;
    if(is_feuille(arbre) || arbre->couleur != NON_UNI || h == 1)
    {
        //printf("\n ***Bottom***");
        int i,j;
        for(i=0;i<h;i++)
            for(j=0;j<h;j++)
                writeCouleur(name,arbre->couleur,x+j,y+i,h_img);
        return;
    }
    //printf("\n %d %d %d",x,y,h);
    writeBMP2(arbre->fils[NO],name,x,y+h/2,h/2,h_img);
    writeBMP2(arbre->fils[NE],name,x+h/2,y+h/2,h/2,h_img);
    writeBMP2(arbre->fils[SO],name,x,y,h/2,h_img);
    writeBMP2(arbre->fils[SE],name,x+h/2,y,h/2,h_img);
}
void writeBMP(Arbre arbre,char * name,INFOHEADER info)
{
    //prepareBMP("out.bmp",info,arq);
    writeBMP2(arbre,name,0,0,info.height,info.height);
}
void writeCouleur(char* name,Couleur col, int x,int y,int h)
{

    int pos = y * h + x;
    //printf("\n %d %d %d    %d", i,j,h,pos);
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
Couleur readCouleur(char* name, int x,int y,int h)
{
    int pos = y * h + x;
    //printf("\n %d %d %d    %d", i,j,h,pos);
    FILE * file = fopen(name,"r");
    assert(file != NULL);

    long offset = 54;
    fseek(file, SEEK_SET + offset + 3*pos, 0);

    unsigned char tmp[3];

    fread(&tmp,sizeof(unsigned char)* 3,1,file);
   // printf("\n %d",res);
    fclose(file);

    Couleur col=rgb_to_nb(tmp[0],tmp[1],tmp[2]);
    return col;
}

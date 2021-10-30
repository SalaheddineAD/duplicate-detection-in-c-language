#include "hashtable.h"

#define true 0
#define false 1
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

char *TrouverMatches(char * txt,int *bl)
{
	int i,j;
	char *res=malloc(256*sizeof(char));
	char ctmp='a';
	for (i=0;i<256;i++)
	{res[i]=0;}
	i=0,j=0;
	while (ctmp!=0)
	{
		ctmp=txt[i];
		if (bl[i]==true)
		{
			res[j]=ctmp;
			j++;
		}
		i++;
	}
	return res;
}

double JaroWinkler(char *t1,char *t2)
{
	int ecartMax,l1,l2,compteMatching,compteTransposition,longueurPrefix,i,j;
	char *t1Matche,*t2Matche;
	int *b1,*b2;
	double distanceJaro;
	if (t1[0]==0 || t2[0]==0)
		return 0.0;
	l1=strlen(t1);
	l2=strlen(t2);
	ecartMax=(max(l1,l2)/2)-1;
	compteMatching=0;
	b1=malloc((l1+2)*sizeof(int));
	b2=malloc((l2+2)*sizeof(int));
	for (i=0;i<l1;i++)
		b1[i]=false;
	for (i=0;i<l2;i++)
		b2[i]=false;

	for (i=0;i<l1;i++)
	{
		for (j=max(i-ecartMax,0);j<=min(i+ecartMax,l2);j++)
		{
			if (t1[i]==t2[j])
			{
				b1[i]=true; //Indique qu'on a bien trouvé ce caractère
				b2[j]=true;
				compteMatching++; //Incrémente le nombre de caractères correspondants
				break;
			}

		}

	}

	if (compteMatching==0)
		return 0.0;

	t1Matche=TrouverMatches(t1,b1); //Génére la liste des caractères communs dans l'ordre de t1
	t2Matche=TrouverMatches(t2,b2);

	compteTransposition=0;
	if (strcmp(t1Matche,t2Matche)!=0)
	{
		for (i=0;i<strlen(t1Matche);i++)
			if (t1Matche[i]!=t2Matche[i])
				compteTransposition++; //Calcul le nombre de transpositions
	}
	else
		compteTransposition=0;

	free(t1Matche);
	free(t2Matche);

	distanceJaro=(((double)compteMatching/l1)+((double)compteMatching/l2)+((compteMatching-compteTransposition/2.0)/compteMatching))/3.0;

	longueurPrefix=0;
	for (i=0;i<min(3,min(l1,l2))+1;i++) //longueur max : 4
	{
		if (t1[i]==t2[i])
			longueurPrefix++;
		else
			break;

	}
	return distanceJaro+(longueurPrefix*0.1*(1-distanceJaro));
}

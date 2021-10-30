#include "set.h"
#define max2(a,b)  (((a) > (b)) ? (a) : (b))
/////////////////////////////////////////////////
void WriteStuffInTheFile(char *s, int fd)
{
   int	i=0;
	 if (s)
	 	while (s[i] != '\0')
		{write(fd, &s[i], 1);
         i++;
	    }
	    write(fd, "\n", 1);
}
/////////////////////////////////////////////////
char	*JoinStrings(char const *s1, char const *s2)
{
	char	*s3;
	int i=0,j=0;
	if (!s1 || !s2)
		return (NULL);
    s3 = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (i < strlen(s1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < strlen(s2))
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
/////////////////////////////////////////////////
void Swap_2_Array_Elements(char **array ,int i , int j)
{
   char *temp;
   temp = strdup(array[i]);
   array[i] = strdup(array[j]);
   array[j]= strdup(temp);

}
/////////////////////////////////////////////////
void ajout(char **tableau,char *valeur,int position )
{
	tableau[position]=strdup(valeur);
	int i=position;
	while(i>1 && strcmp(tableau[i/2],tableau[i])==1)
		{
			Swap_2_Array_Elements(tableau,i,i/2);
			i=i/2;
		}
}
/////////////////////////////////////////////////
char *extraire_min(char **tas,int *p)
{
    char *min;
    int i;
    min = strdup(tas[1]);
    free(tas[1]);
    tas[1] = strdup(tas[*p]);
    (*p)--;
    i = 1;
    while (i <= (*p)/2 && (strcmp(tas[i],tas[2*i]) > 0 || strcmp(tas[i],tas[2*i+1]) > 0))
    {

        if(strcmp(tas[2 * i + 1],tas [2 * i]) > 0)
           {
               Swap_2_Array_Elements(tas,i,2*i);
               i = 2*i;
           }
        else
           {
                Swap_2_Array_Elements(tas,i,2*i+1);
                i = 2*i + 1;
           }
    }
    return (min);
}
/////////////////////////////////////////////////
char **liretotas(char *FileSteam)
{
	char buffer[2];
    char **tas;
    int f = open(FileSteam,O_RDONLY);
    int i=1;
    int j=3;
    char *s;
    tas = malloc(sizeof(char*)*2);
    while(read(f,buffer,1))
        {
            s=strdup("");
            while(strcmp(buffer,"\n"))
            {
			   buffer[1]='\0';
               s=JoinStrings(s,buffer);
			   if(read(f,buffer,1) == 0)
        	        break;
            }
            ajout(tas,s,i);
            tas=realloc(tas,sizeof(char*)*j);
            j++;
            i++;
        }
        last=i-1;
        tas[i]=malloc(sizeof(char));
        tas[i]=NULL;
		close(f);
      	return(tas);
}
/////////////////////////////////////////////////
char **mappingtotable(char *FileSteam)
{
	int i =0;
    char **tas=liretotas(FileSteam);
    char **New_Table=malloc(sizeof(char*));
    while(tas[i+1])
    {
        New_Table[i]=strdup(extraire_min(tas,&last));
        i++;
	    New_Table=realloc(New_Table,sizeof(char*)*(i+1));
    }
    New_Table[i]=NULL;
    free(tas);
    return(New_Table);
}
/////////////////////////////////////////////////

  int ReplaceFileWithNewFile(char *FileStream,char**t)
		{
			int r=remove(FileStream);
			int y = open(FileStream, O_WRONLY | O_CREAT| O_APPEND, 0644);
			int i=0;
			while (t[i])
			{
			WriteStuffInTheFile(t[i], y);
				i++;
			}
			return r;
	 	}
/////////////////////////////////////////////////

char **purge(char*FileStream)
{
    char **tab;
    char **t;
    int i=1;
    int k=2;
    int last=0;
    int change;
    int j;
    char *s;
    char *s1;
    tab=mappingtotable(FileStream);
    t =malloc(sizeof(char*));
	t[0] = strdup(tab[0]);
    while(tab[i])
    {
        j=last;
        change=0;
        while(j>=0)
        {
             if(SelectedDistance == 1)
            {
                init();
                s = strdup(soundex(tab[i]));
                s1 = strdup(soundex(t[j]));
                if(strcmp(s,s1) == 0)
                {
                    change=1;
                    break;
                }
            }
            if(SelectedDistance == 2)
            {
                if (JaroWinkler(tab[i],t[j]) >= 0.84)
                {
                change=1;
                    break;
                }
            }
            if(SelectedDistance == 3)
            {
                if (levenshtein(tab[i],t[j])/(float)max2(strlen(tab[i]),strlen(t[j])) <= 0.4)
                {
                    change=1;
                    break;
                }
            }

            if(SelectedDistance == 4)
            {
                if (ngram_distance(tab[i],t[j],20) >= 0.75)
                {
                change=1;
                    break;
                }
            }
            j--;
        }
        if (change==0)
        {
        	t=realloc(t,sizeof(char*)*k);
			t[k-1] = strdup(tab[i]);
            k++;
		    last++;
        }
        i++;
    }
	t=realloc(t,sizeof(char*)*k);
	t[k-1] = strdup(NULL);
    ReplaceFileWithNewFile(FileStream,t);
    free(t);free(tab);
    return(0);
}

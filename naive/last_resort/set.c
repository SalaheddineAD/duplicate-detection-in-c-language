#include "set.h"

void WriteEndlInFile(char *name, int FileStream)
{
   int	i;

     i = 0;
	 if (name)
	 	while (name[i] != '\0')
		{
	    	write(FileStream, &name[i], 1);
		 	i++;
	    }
	    write(FileStream, "\n", 1);
}
//*********************************************************
char	*Join2Strings(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
//*********************************************************
char **Mappingtoset(char *nom)
  {
   char **set;
   char *tab;
   int FileStream=open(nom,O_RDONLY);
   char stock[2];
   int i=2;
   tab=strdup("");
   while(read(FileStream,stock,1)&&strcmp(stock,"\n"))
       {
           stock[1]='\0';
           tab=Join2Strings(tab,stock);
       }
       set=malloc(sizeof(char*));
       set[0] = strdup(tab);
       while(read(FileStream,stock,1))
         {
               tab=strdup("");
               while(strcmp(stock,"\n"))
               {
                 tab=Join2Strings(tab,stock);
                 if (read(FileStream,stock,1)==0)
                    break;
               }
               set=realloc(set,sizeof(char*)*i);
               set[i-1]=strdup(tab);
               i++;
         }
         set=realloc(set,sizeof(char*)*i);
         set[i-1]=malloc(sizeof(char));
         set[i-1]=NULL;
         close(FileStream);
         return(set);
  }
//*********************************************************
 int RemoveFile(char *FileStream,char**t)
{
		int r=remove(FileStream);
		int y = open(FileStream, O_WRONLY | O_CREAT| O_APPEND, 0644);
		int i=0;
        while (t[i])
		{
		    WriteEndlInFile(t[i], y);
			i++;
		}
		return r;
}
//*********************************************************
void purge(char*FileStream)
{
    char **tab;
    char **t;
    int i=1 ;
    int k=2;
    int last=0;
    int change;
    int j;
    char *s;
    char *s1;

    tab=Mappingtoset(FileStream);
    t = malloc(sizeof(char*));
    t[0]=strdup(tab[0]);
    while(tab[i])
    {
        j=last;
        change=0;
        while(j>=0)
        {
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
                if(SelectedDistance == 4)
                {

                    if(ngram_distance(tab[i], t[j], 20) >=0.75)
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
            t[k-1]= strdup(tab[i]);
            k++;
            last++;
        }
        i++;
    }
    t=realloc(t,sizeof(char*)*k);
	t[k-1] = strdup(NULL);
    RemoveFile(FileStream,t);
}

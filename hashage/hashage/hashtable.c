#include"hashtable.h"
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define max2(a,b) (a>b ? a : b)
void WriteEndlFile(char *s, int fd)
{
   int	i=0;


	 if (s)
	 	while (s[i] != '\0')
		{
	    	write(fd, &s[i], 1);
		 	i++;
	    }
	    write(fd, "\n", 1);
}
///////////////////////////////////////////////////

char	*JoinStrings(char const *s1, char const *s2)
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
//////////////////////////////////////////////////////
int CacluleHashe( char * name){
int hash=0;
for(int i=0;i < strlen(name)+1;i++){
    hash += (int)name[i];
}
hash = hash%6;
return hash;
}
//////////////////////////////////////////////////////
void ajoutMot(struct node *Tab, char *mot)
{
     struct node *Temp ;
     struct node *T;
     int hashcode=CacluleHashe(mot);
    if(strcmp(Tab[hashcode].name,"-1") == 0)
    {
        Tab[hashcode].name=strdup(mot);
    }
    else
    {
        T = &Tab[hashcode];
        Temp = Tab[hashcode].next;
        while(Temp)
        {
            T = Temp;
            Temp = Temp->next ;
        }
        struct node *nv;
        nv = malloc(sizeof(struct node));
        nv->name = strdup(mot);
        nv->next = NULL;
        T->next = nv;

     }
}
/////////////////////////////////////////////////////////
struct node *MappingToHashTable(char *nom_fichier)
{

  char stocker[2];
  char *tab;
  int  i=0;
  struct node *namee = malloc(sizeof(struct node) * 6);
  int fd = open(nom_fichier,O_RDONLY);
  while(i<6)
  {
        namee[i].name="-1";
        namee[i].next=NULL;
        i++;
  }
  while(read(fd,stocker,1))
  {
       tab=strdup("");
        while(strcmp(stocker,"\n"))
        {
           tab=JoinStrings(tab,stocker);

           if(read(fd,stocker,1) == 0)
            break;
        }
        ajoutMot(namee,tab);
  }
  close(fd);
  return(namee);


}
//////////////////////////////////////////////////////
int purge(char *nom_fichier)
{
    struct node *tab =MappingToHashTable(nom_fichier);
    char **tablo;
    struct node *pointerToTab;
    int j=0;
    int i=0;
    int k =2;
    char *s;
    char *s1;

    tablo=malloc(sizeof(char*));
    while(i<6){
            if(strcmp(tab[i].name,"-1")){
                tablo[0] = strdup(tab[i].name);
                break;
            }
            else i++;}
            i=0;
        while (i <6)
    {
        pointerToTab = &tab[i];
        while(pointerToTab)
        {  k = j;

            while (k >= 0)
           {
               if(choice == 1){
                 if(levenshtein(pointerToTab->name,tablo[k])/(float)max2(strlen(pointerToTab->name),strlen(tablo[k])) <= 0.4)
                     break;
                else if (k == 0 && strcmp(pointerToTab->name,"-1") !=0)
                {
                        j++;
                        tablo = realloc(tablo,sizeof(char*) * (j+1));
                        tablo[j] = strdup(pointerToTab->name);
                        break;
                }
                else
                k--;
           }
                else if(choice == 2){
                    if(JaroWinkler(pointerToTab->name,tablo[k]) >= 0.84)
                        break;
                    else if (k == 0 && strcmp(pointerToTab->name,"-1") !=0)
                {
                        j++;
                        tablo = realloc(tablo,sizeof(char*) * (j+1));
                        tablo[j] = strdup(pointerToTab->name);
                        break;
                }
                else
                k--;
           }
                else if(choice == 3){
                init();
                    s = strdup(soundex(pointerToTab->name));
                    s1 = strdup(soundex(tablo[k]));
                    if(strcmp(s,s1) == 0){
                        break;
                    }
                    else if (k == 0 && strcmp(pointerToTab->name,"-1") !=0)
                {
                        j++;
                        tablo = realloc(tablo,sizeof(char*) * (j+1));
                        tablo[j] = strdup(pointerToTab->name);
                        break;
                }
                else
                k--;
           }
                else{
                    if(ngram_distance(pointerToTab->name,tablo[k],20) >= 0.75)
                        break;
                    else if (k == 0 && strcmp(pointerToTab->name,"-1") !=0)
                {
                        j++;
                        tablo = realloc(tablo,sizeof(char*) * (j+1));
                        tablo[j] = strdup(pointerToTab->name);
                        break;
                }
                else
                k--;

                }
            }
           pointerToTab = pointerToTab->next;
        }
        i++;
    }
    j++;
    tablo = realloc(tablo,sizeof(char*) * (j+1));
    tablo[j] = malloc(sizeof(char));
    tablo[j] = NULL;

  if(remove(nom_fichier)==0){
     //  printf("\n ************************* fichier change avec succes ************************ \a \a\a\a\a");
       int y = open( nom_fichier , O_WRONLY | O_CREAT| O_APPEND,0644);
       i=0;
       while(tablo[i])
         {
          WriteEndlFile(tablo[i],y);
          i++;
         }
                          }
else printf("\n Erreur , fichier non editer ");


return 0 ;
}



# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
#include <string.h>

char	*Join2Strings(char const *s1, char const *s2);
char    **Mappingtoset(char *FileStream);
void    purge(char*FileStream);
int     levenshtein(char *s1, char *s2); // la distance
double  JaroWinkler(char *t1,char *t2);
const char* soundex(const char *s);
void init();
int ChoiceOfDistance;

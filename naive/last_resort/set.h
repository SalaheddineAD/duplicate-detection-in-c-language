#ifndef SET_H
# define SET_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
#include <string.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define max2(a,b) (a>b?a:b)

char	*Join2Strings(char const *s1, char const *s2);
char    **Mappingtoset(char *FileStream);
void    purge(char*FileStream);
int     levenshtein(char *s1, char *s2); // la distance
double ngram_distance(const char *source, const char *target, int n);
double  JaroWinkler(char *t1,char *t2);
const char* soundex(const char *s);
void init();
int SelectedDistance;
#endif

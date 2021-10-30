#ifndef SET_H
# define SET_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
#include <string.h>

int     levenshtein(char *s1, char *s2);
double JaroWinkler(char *t1,char *t2);
const char* soundex(const char *s);
void ajout(char **tas,char *x,int p );
char *extraire_min(char **tas,int *lasta);
char **liretotas(char *FileSteam);
double ngram_distance(const char *source, const char *target, int n);
char **mappingtotable(char *FileSteam);
char **purge(char*FileStream);
char	*JoinStrings(char const *s1, char const *s2);
void init();
int last;
int SelectedDistance;
#endif

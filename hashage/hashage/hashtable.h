#ifndef HASHTABLE_H
 #define HASHTABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
struct node
{
               char * name;
               struct node *next;
};
int     levenshtein(char *s1, char *s2);
double JaroWinkler(char *t1,char *t2);
const char* soundex(const char *s);
 void WriteEndlFile(char *s, int fd);
 int levenshtein(char *s1, char *s2);
 char	*JoinStrings(char const *s1, char const *s2);
 double ngram_distance(const char *source, const char *target, int n);
  int CacluleHashe(char *mot);
  void ajoutMot(struct node *Tab, char *mot);
struct node *MappingToHashTable(char *nom_fichier);
int purge(char *nom_fichier);
int choice;

#endif // HASHTABLE_H

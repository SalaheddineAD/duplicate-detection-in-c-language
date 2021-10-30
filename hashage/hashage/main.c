#include"hashtable.h"
     #include <time.h>

int main()
{
  int i;
  		printf("                elimination des redondances \n");
	printf("==================================================================\n");
    printf("||             1- pour utiliser la distance de levenshtein:       ||\n");
	printf("||             2- pour utiliser la distance de JaroWinkler:       ||\n");
	printf("||             3- pour utiliser la distance de soundex:           ||\n");
	printf("||             4- pour utiliser la distance de N-grame:           ||\n");
	printf("||================================================================||\n");
  scanf("%d",&choice);
     clock_t start, end;
     double cpu_time_used;
 		  start = clock();purge("100-1.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("100-2.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("100-3.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("250-1.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("250-2.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("250-3.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("500-1.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("500-2.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("500-3.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("750-1.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("750-2.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("750-3.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("1000-1.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("1000-2.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("1000-3.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("2000-1.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("2000-2.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("2000-3.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("5000-1.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("5000-2.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("5000-3.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
		  start = clock();purge("10000.txt");end = clock();cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;printf("%f\n",cpu_time_used);
return 0;
}

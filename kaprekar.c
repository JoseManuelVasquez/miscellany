#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *, const void *);
int cmpReverse(const void *, const void *);
char * intToString(const int);
int kaprekar(const int);

int main (void)
{

   int aux;

   printf("Number: ");
   scanf("%d",&aux);

   kaprekar(aux);

   return 0;
}

/* Comparing function in ascending order*/
int cmp(const void * a, const void * b)
{

   char *c1=(char*)a;
   char *c2=(char*)b;

   if(*c1>*c2)
      return 1;
   if(*c1<*c2)
      return -1;
   return 0;

}

/* Comparing function in descending order */
int cmpReverse(const void * a, const void * b)
{

   char *c1=(char*)a;
   char *c2=(char*)b;

   if(*c1>*c2)
      return -1;
   if(*c1<*c2)
      return 1;
   return 0;

}

/* Change int variable to char variable */
char * intToString(const int num)
{

   /* Control of the number */
   if(num-9999>=0 || num<1)
   {
      fprintf(stderr, "NUMBER ERROR\n");
      return NULL;
   }


   char *aux;
   /* 4 characters and \0 */
   aux=(char*)malloc(5*sizeof(char));
   aux[0]=(num/1000) + 48;
   aux[1]=((num/100)-(num/1000)*10) + 48;
   aux[2]=((num/10)-(num/100)*10) + 48;
   aux[3]=(num-(num/10)*10) + 48;

   return aux;
}

/* ALgorithm */
int kaprekar(const int kaprekar)
{

   int aux;
   char *num1, *num2;

   /* Beginning of algorithm */
   if(!(num1=intToString(kaprekar))) return -1;
   if(!(num2=intToString(kaprekar))) return -1;
   qsort(num1, 4, sizeof(char), cmpReverse);
   qsort(num2, 4, sizeof(char), cmp);

   /* Not a Kaprekar number */
   if(*num1==*num2)
   {
      fprintf(stderr, "NOT A KAPREKAR NUMBER\n");
      return -1;
   }


   int i=1;
   while(aux!=6174)
   {
      aux=atoi(num1)-atoi(num2);
      printf("Iteration %d: %s - %s = %d\n", i, num1, num2, aux);
      free(num1);
      free(num2);
      num1=intToString(aux);
      num2=intToString(aux);
      qsort(num1, 4, sizeof(char), cmpReverse);
      qsort(num2, 4, sizeof(char), cmp);
      i++;
   }

}

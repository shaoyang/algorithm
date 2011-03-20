#include<stdio.h>
#include<stdlib.h>

int main(){
   char a[30];
   char *b = (char *)malloc(20 * sizeof(char));
   printf("%d\n", sizeof(a));      //30
   printf("%d\n", sizeof(b));      //4
   printf("%d\n", sizeof(a[3]));   //1
   printf("%d\n", sizeof(b+3));    //4
   printf("%d\n", sizeof(*(b+4))); //1
   system("pause");
   return 0;
}

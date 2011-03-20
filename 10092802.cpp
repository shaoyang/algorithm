#include<iostream>
#include<stdio.h>
using namespace std;
union{
   int i;
   char ch[2];
}a;
union{
   int i;
   struct{
      char last;
      char first;
   }inner;
}b;
int main(){
   //a.ch[0] = 1;
   //a.ch[1] = 10;
   //cout<<a.i<<endl;
 
   b.i = 0x4241;
   printf("%c%c\n",b.inner.first,b.inner.last); 
   b.inner.first = 'B';
   b.inner.last = 'A';
   printf("0X%x\n",b.i);
   system("pause");
   return 0;
}

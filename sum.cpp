#include<iostream>
using namespace std;

void test1(){
   char string[10];
   char* str1="0123456789";
   strcpy(string, str1);
   cout<<string<<endl;
}

void test2(){
   char str1[10],str2[10];
   for(int i=0;i<9;i++){
      str1[i] = 'a';
   }
   str1[9] = '\0';
   strcpy(str2,str1);
   cout<<str1<<endl;
   cout<<str2<<endl;
}

void test3(char* str1)
{
    char string[10];
    memset(string,0,10);
    if(strlen(str1)<=10){
       strcpy(string, str1);
    }
    cout<<string<<endl;
}
int sum(int a)
{
   auto int c=0;
   static int b=3;
   c+=1;
   b+=2;
   return(a+b+c);
}
int func(int a){
   int b;
   switch(a){
      case 1: b = 30;break;
      case 2: b = 20;break;
      case 3: b = 16;break;
      default: b = 0;
    }
return b;
}
//不用循环判断一个int是否是2的幂
bool isEven(int i){
   if(i==1)
      return false;
   i = i>>1;
   if(i>1)
      isEven(i);
   
} 
int main(){
    /*
    int a[3];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    int *p,*q;
    p = a;
    q = &a[2];
    cout<<a[q-p]<<endl;
    */
    int **a[3][4];
        //cout<<sizeof(int)<<endl;
    //cout<<sizeof(a)<<endl;
    int i,j;
    for(i=0;i<3;i++)
       for(j=0;j<4;j++){
          int *p;
          int m = i+j;
          p = &m;
          int **q;
          q = &p;
          a[i][j] = q;
          cout<<**a[i][j]<<endl;
       }
    system("pause");
    return 0;
}

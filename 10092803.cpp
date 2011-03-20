#include<iostream>
using namespace std;
char* strcopy(char* strSrc,char* strDest){
   if(strSrc==NULL||strDest==NULL)
      return NULL;
   if(strSrc == strDest)
      return strDest;
   char* tempstr = strDest;
   while((*strDest++ = *strSrc++)!='\0');
   return tempstr;
}
int fn1(){
  // cout<<"excute after main!"<<endl;
   return 0;
}
int main(){
   char*  src = "I am proud of you!";
   char* dest;
   dest = strcopy(src,dest);
   while(cout<<*dest,*dest++!='\0');
   cout<<__FILE__<<endl;
   cout<<__LINE__<<endl;
   //_onexit(fn1);
   #ifdef __cplusplus
   cout<<"c++";
   #else
   cout<<"c";
   #endif
   system("pause");
   return 0;
}


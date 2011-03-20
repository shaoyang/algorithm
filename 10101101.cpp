#include<iostream>
using namespace std;
int val = 3;
int main(){
   int val = 10;
   val++;
   ::val++;
   cout<<::val<<endl;
   cout<<val<<endl;
   system("pause");
   return 0;
} 

#include<iostream>
using namespace std;
int main(){
   int n,m;
   while(cin>>m>>n){
       int r;
       r = m%n;
       while(r!=0){
          m = n;
          n = r;
          r = m%n;
       }
       cout<<n;
   }
   system("pause");
   return 0;
}

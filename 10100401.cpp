#include<iostream>
using namespace std;

int main(){
   int aa[10];
   int i=2,k=0;
   int n;
   while(1){
       cin>>n;
       memset(aa,0,sizeof(aa));
       k = 0;
       i = 2;
       while(i<=n){
          if(n%i==0){
             n = n/i;
             aa[k++] = i;
             i = 2;
          }
          else
             i++;
       }
       /*
       for(i=0;i<k-1;i++)
          cout<<aa[i]<<"*";
       cout<<aa[k-1]<<endl;
       */
   }
   system("pause");
   return 0;
}

#include<iostream>
using namespace std;

int count(int ch){
   int i,num=0;
   if(ch & 0x01)
      num++;
   for(i=0;i<7;i++){
      //cout<<ch<<" ";
      ch = ch >> 1;
      if(ch & 0x01){
         num++;
      }
   }
   return num;
}

int count2(int ch){
   int i,num=0;
   if(ch & 0x80)
      num++;
   for(i=0;i<7;i++){
      //cout<<ch<<" ";
      ch = ch << 1;
      if(ch & 0x80){
         num++;
      }
   }
   return num;
}

int convert(char ch[],int sz){
   int i,res = 0;
   int n = 1;
   int temp; 
   for(i=sz-1;i>=0;i--){
      temp = (int)ch[i] - 48;
      cout<<temp<<endl;
      if(i!=0 && temp == 0)
         res *= 10;
      else
         res += temp*n;
      n = 10*n; 
   }
   return res;
}

int main(){
   /*
   int x = 0xef;
   cout<<count(x)<<endl;
   cout<<count2(x)<<endl;
   */
   char ch[]={'1','2','3','4','5','6','7','8','0','0'};
   int sz = sizeof(ch);
   cout<<"size:"<<sz<<endl;
   cout<<convert(ch,sz)<<endl;
   system("pause");
   return 0;
}



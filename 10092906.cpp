#include <iostream.h>
int &put(int n);
int vals[10];
int error=-1;
int main(){
   put(0)=10; //以put(0)函数值作为左值，等价于vals[0]=10;
   put(9)=20; //以put(9)函数值作为左值，等价于vals[9]=20;
   cout<<vals[0];
   cout<<vals[9];
   system("pause");
   return 0;
}
int &put(int n){
   if (n>=0 && n<=9 ) 
      return vals[n];
   else{ 
      cout<<"subscript error";
      return error; 
   }
}

#include<iostream>
using namespace std;
const int MINNUM = -32767;
int findSecond(int arr[],int len){
   int i;
   int max,smax;
   max = MINNUM;
   for(i=0;i<len;i++){
      if(arr[i]>max){
         smax = max;
         max = arr[i];
      }
   }
   return smax;
}
int main(){
   int arr[] = {1,2,5,3,4,7,9,10,12};
   int len = sizeof(arr)/sizeof(int);
   cout<<findSecond(arr,len);
   system("pause");
   return 0;
}

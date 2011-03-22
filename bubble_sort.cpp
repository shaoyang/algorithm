#include<iostream>
#include<fstream>
using namespace std;

//bubble-sort
void order(int* arr,int len){
  if(arr==NULL)
     return;
  else{
     int i,j,temp;
     for(i=len-1;i>=1;i--){
        for(j=i-1;j>=0;j--){
           if(arr[j]>arr[i]){
              temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
           }
        }
     }
  }
}

int main(){
   int i,len;
   int test[] = {1,9,5,3,7,2,0};
   len = sizeof(test)/sizeof(int);
   order(test,len);
   system("pause");
   return 0;
}

#include<iostream>
using namespace std;

int partition(int arr[],int p,int r)
{
     int i,j,temp;
     i = p-1;
     for(j=p;j<r;j++)
     {
        if(arr[j]<=arr[r])
        {
            i++;
            //交换arr[i]和arr[j]
            temp =arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
     }
     //交换arr[i+1]和arr[r]
     temp =  arr[r];
     arr[r] = arr[i+1];
     arr[i+1] = temp;
     return i+1;
}

int quick_sort(int arr[],int p,int r)
{
    int q;
    if(p<r)
    {
       q = partition(arr,p,r);
       quick_sort(arr,p,q-1);
       quick_sort(arr,q+1,r);
    }
}


int main()
{
   int arr[] = {3,1,5,2,7,19,0,6};
   quick_sort(arr,0,7);
   for(int i=0;i<8;i++)
      cout<<arr[i]<<" ";
   system("pause");
   return 0;
}

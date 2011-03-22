#include<iostream>
using namespace std;
int heap_size = 6;
int length = 10;
 
//在打定队中，heap_ify保证在上面的较小的元素能够被挪到
//下边合适的位置 
void heap_ify(int arr[],int i)
{
   int left,right,largest;
   largest = i;
   left = 2*i;
   right = 2*i + 1;
   if(left<=heap_size && arr[largest]<=arr[left])
   {
      largest = left;
   }     
   
   if(right<=heap_size && arr[largest]<=arr[right])
   {
      largest = right;
   }
   if(i!=largest)
   {
      int temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;
      heap_ify(arr,largest);
   }
}

void heap_build(int arr[])
{
   int nonleaf_size = heap_size/2;
   for(int i=nonleaf_size;i>=1;i--)
   {
      heap_ify(arr,i);
   }     
}

//对已经建好的堆进行排序 
void heap_sort(int arr[])
{
   int temp;
   for(int i=heap_size;i>=2;i--)
   {
      temp = arr[1];
      arr[1] = arr[heap_size];
      arr[heap_size] = temp;
      heap_size--;
      heap_ify(arr,1); 
   }
}

int heap_max(int arr[])
{
   return arr[1];
}

int heap_extract_max(int arr[])
{
   int max = arr[1];
   arr[1] = arr[heap_size];
   heap_size--;
   heap_ify(arr,1);
   return max;
}

void heap_increase_key(int arr[],int i,int key)
{
   arr[i] = key;
   int parent;
   while(i>1)
   {
      parent = i/2;
      if(arr[parent]<arr[i])
      {
         int temp = arr[parent];
         arr[parent] = arr[i];
         arr[i] = temp;
      }
      i = parent; 
   }
}

int main()
{
    int a[10] = {-1,10,5,1,9,2,4};
    heap_build(a);
    for(int i=1;i<=6;i++)
    {
       cout<<a[i]<<endl;
    }
    heap_increase_key(a,4,11); 
    //heap_sort(a);
    for(int i=1;i<=6;i++)
    {
       cout<<a[i]<<endl;
    }
    system("pause");
    return 0;
}

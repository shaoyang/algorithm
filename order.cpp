#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

void order(vector<int>& data){
   int i,j,temp;
   int count = data.size();
   int tag = false;
   for(i=0;i<count;i++){
      for(j=0;j<count-i-1;j++){
         if(data[j]>data[j+1]){
            temp = data[j+1];
            data[j+1] = data[j];
            data[j] = temp;
            tag =true;      
         }
      }
      if(!tag)
         break;
   }
}

int main(){
    vector<int> data;
    int temp,i;
    ifstream in("C:\\data.txt");
    if(!in){
       cout<<"file error"<<endl;
       exit(1);
    }
    while(!in.eof()){
       in>>temp;
       data.push_back(temp);
    }
    in.close();
    ofstream out("C:\\result.txt");
    if(!out){
       cout<<"file error"<<endl;
       exit(1);
    }
    order(data);
    for(i=0;i<data.size();i++)
       out<<data[i]<<" ";
    out.close();
}

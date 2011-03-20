#include<iostream>
using namespace std;
typedef struct Node{
   int data;
   Node* next;
}Node;

Node* reverse(Node* head){
   if(head==NULL)
      return NULL;
   if(head->next == NULL)
      return head;
   Node* prev = head;
   Node* cur = head->next;
   head->next = NULL;
   if(cur==NULL)
      cout<<"NULL"<<endl;
   Node* temp;
   while(cur != NULL){
      //cout<<cur->data;
      temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
   }
   return prev;
}

int main(){
   int i=2;
   Node* head;
   Node* cur;
   head = new Node;
   head->data = 1;
   head->next = NULL;
   cur = head;
   while(i<10){
      Node* temp = new Node;
      temp->data = i;
      temp->next = NULL;
      cur->next = temp;
      cur = temp;
      i++;
   }
   head = reverse(head);
   cur = head;
   while(cur!=NULL){
      cout<<cur->data<<" ";
      cur = cur->next;
   }
   system("pause");
   return 0; 
}

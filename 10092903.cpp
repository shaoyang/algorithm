#include<iostream>
using namespace std;
typedef struct Node{
   int data;
   Node* next;
}Node;

Node* merge(Node* head1,Node* head2){
   if(head1 == NULL)
      return head2;
   if(head2 == NULL)
      return head1;
   Node* cur = head1;
   Node* prev;
   Node* p;
   int temp;
   while(head2 != NULL){
      temp = head2->data;
      while(cur != NULL &&(cur->data <= temp)){
         prev = cur;
         cur = cur->next; 
      }
      p = head2;
      head2 = head2->next;
      prev->next = p;
      p->next = cur;
   }
   return head1;
}
Node* mergeRecursive(Node* head1,Node* head2){
   if(head1 == NULL)
      return head2;
   if(head2 == NULL)
      return head1;
   Node* head = NULL;
   if(head1->data < head2->data){
      head = head1;
      head->next = mergeRecursive(head1->next,head2);
   }
   else{
      head = head2;
      head->next = mergeRecursive(head1,head2->next); 
   }
   
}
int main(){
    Node* head1;
    Node* head2;
    Node *cur1,*cur2;
    int i;
    head1 = new Node;
    head1->data = -1;
    head1->next = NULL;
    cur1 = head1;
    head2 = new Node;
    head2->data = 0;
    head2->next = NULL;
    cur2 = head2;
    for(i=1;i<10;i++){
       Node* tnode = new Node;
       tnode->data = i;
       tnode->next = NULL;
       if(i%2!=0){
          cur1->next = tnode;
          cur1 = tnode;
       }
       else{
          cur2->next = tnode;
          cur2 = tnode;
       }
    }
    cur2 = merge(head1,head2);
    while(cur2 != NULL){
       cout<<cur2->data<<" ";
       cur2 = cur2->next;
    }
    
   cout<<"aaa"<<endl;
   system("pause");
   return 0;
}

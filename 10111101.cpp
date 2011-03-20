#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;
#define m 13		//元素个数
#define n 20		//hash table大小 

struct node{
	int x;
	struct node* next;
};

//使用除法计算key 
int hash(int x){
	int remain = x % m;
	return remain;
}

//插入到hash table中 
void hash_insert(struct node table[],int x){
	int key = hash(x);
	struct node* head;
	if(table[key].x != -1){
		struct node* tnode = new node();
		tnode->x = x;
		head = table[key].next;
		table[key].next = tnode;
		tnode->next = head;
	}
	else{
		table[key].x = x;
	}
}

//在hash table进行搜索,搜索table[h(k)]具有关键字的元素 
int hash_search(struct node table[],int k){
	struct node* head;
	head = &table[k];
	while(head!=NULL){
		if(head->x == k){
			return head->x;
		}
		head = head->next;
	}
	return -1;
}

//从hash table中删除元素
void hash_delete(struct node table[],int x){
	int h = hash(x);
	struct node	*prev,*cur;
	prev = (struct node	*)&table[h];
	cur  =  prev;
	//head为目标元素 
	if(cur->x == x){
		
		cur = cur->next;
		if(cur != NULL){
			prev->x = cur->x;
			prev->next = cur->next;
		}
		else{
			prev->x = -1;
		}
	}
	else{
		cur = cur->next;
		while(cur != NULL){
			if(cur->x ==x){
				prev->next = cur->next;
				break;
			}
			prev =cur;
			cur = cur->next;
		}
	}
}

int main(){
	struct node hash_table[m];
	struct node* head;
	int i,rand_num;
	//初始化hash数组
	for(i=0;i<m;i++){
		hash_table[i].x = -1;
		hash_table[i].next = NULL;
	}
	
	for(i=0;i<n;i++){
/*
		Sleep(1000);
		srand(time(0));
		rand_num = rand();
*/
		hash_insert(hash_table,i);	
	}
	
	//显示所有的元素 
	for(i=0;i<m;i++){
		head = &hash_table[i];
		if(head!=NULL){
			do{
				cout<<head->x<<" ";
				head = head->next;
			}while(head != NULL);
			cout<<endl;
		}
	}
	//查找关键字为6的元素
	if(hash_search(hash_table,0)!=-1){
		hash_delete(hash_table,0);
	}
	cout<<endl;
	//显示所有的元素 
	
	for(i=0;i<m;i++){
		head = &hash_table[i];
		if(head!=NULL){
			do{
				cout<<head->x<<" ";
				head = head->next;
			}while(head != NULL);
			cout<<endl;
		}
	}
	
	system("pause");
	return 0;
}

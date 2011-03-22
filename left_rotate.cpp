#include<iostream>
using namespace std;

typedef struct Node{
	int key;
	int color;
	struct Node* parent;
	struct Node* left;
	struct Node* right;
}*BRNode;

BRNode NIL = new Node();
NIL->key = -1;
NIL->color = -1;
NIL->parent = NULL;
NIL->left = NULL;
NIL->right = NULL;

//×óÐý 
void left_rotate(BRNode head,BRNode x){
	BRNode y,p;
	y = x->right;
	x->right = y->left;
	p = x->parent;
	y->parent = p;
	if(p == NULL)
		head = y;
	else if(x == p->left)
		x->left = y;
	else
		x->right = y;
	y->left = x;
	x->parent = y;
}

int main(){
	int A[] = {10,8,23,15,16,2,9,4,29};
	int len = 9;
	BRNode head = new Node();
}

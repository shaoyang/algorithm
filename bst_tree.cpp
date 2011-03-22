#include<iostream>

typedef struct node{
	int value;
	struct node* parent;
	struct node* lchild;
	struct node* rchild;
}*BSTNode;



//插入元素
void insert(BSTNode head,int value){
    if(head->value == -1){
		head->value = value;
		head->parent = NULL;
		head->lchild = NULL;
		head->rchild = NULL;
	}
	else{
		if(value < head->value){
			if(!head->lchild){
				BSTNode tnode = new node();
				head->lchild = tnode;
				tnode->parent = head;
				tnode->value  = value;
				tnode->lchild = NULL;
				tnode->rchild = NULL;	
			}
			else{
				insert(head->lchild,value);
			}
		}
		else{
			if(!head->rchild){
				BSTNode tnode = new node();
				head->rchild = tnode;
				tnode->parent = head;
				tnode->value = value;
				tnode->lchild = NULL;
				tnode->rchild = NULL;		
			}
			else{
				insert(head->rchild,value);
			}
		}
	}
}


//建树
void create_tree(int A[],int len,BSTNode head){
	int i;
	for(i=0;i<len;i++){
		insert(head,A[i]);
	}
}

//遍历树
void inorder(BSTNode head){
	if(head->lchild != NULL)
		inorder(head->lchild);
	cout << head->value << endl;
	if(head->rchild != NULL)
		inorder(head->rchild);	
}

//搜索树
BSTNode search(BSTNode head,int x){
	if(head->value != -1 && head->value == x){
		return head;
	}
	if(x < head->value && head->lchild != NULL){
		return search(head->lchild,x);
	}
	if(x >= head->value && head->rchild != NULL){
		return search(head->rchild,x);
	}
}

//非递归搜索
BSTNode search2(BSTNode head,int x){
	while(head != NULL && head->value != x){
		if(x < head->value)
			head = head->lchild;
		else
			head = head->rchild;
	}
	return head;
	
}
//查找最小元素
BSTNode minimum(BSTNode head){
	while(head->lchild != NULL)
		head = head->lchild;
	return head;
}

//查找最大元素
BSTNode maxmum(BSTNode head){
	while(head->rchild != NULL)
		head = head->rchild;
	return head;
}

//查找中序遍历下的后继,curr为当前节点 
BSTNode successor(BSTNode curr){
	if(curr->rchild != NULL)
		return minimum(curr->rchild);
	BSTNode pnode = curr->parent;
	while(pnode != NULL && pnode->rchild == curr){
		curr = pnode;
		pnode = pnode->parent;
	}
	return pnode;
}
//查询中序遍历下的前驱，curr为当前节点
BSTNode predecessor(BSTNode curr){
	if(curr->lchild != NULL)
		return maxmum(curr->lchild);
	BSTNode pnode = curr->parent;
	while(pnode != NULL && pnode->lchild == curr){
		curr = pnode;
		pnode = pnode->parent;
	}
	return pnode;
}

//删除指定的节点
BSTNode tree_delete(BSTNode root,BSTNode curr){
	BSTNode y,x;
	//如果curr至多只有一个子女 
	if(curr->lchild == NULL || curr->rchild == NULL){
		y = curr;
	}
	//curr有两个子女 
	else{
		y = successor(curr);
	}
	//x指向子女或者null,不管y是不是curr的后继 
	//如果y是curr的后继的话，那么y肯定没有左子女
	// 
	if(y->lchild != NULL){
		x = y->lchild;
	}
	else{
		x = y->rchild;
	}
	// 
	if(x != NULL){
		x->parent = y->parent;
	}
	//删除根节点 
	if(y->parent == NULL){
		root = x;
	}
	else if(y == y->parent->lchild){
		y->parent->lchild = x;
	}
	else{
		y->parent->rchild = x;		
	}
	if(y != curr){
		curr->value = y->value;
	}
	return y;
}


int main(){
	int A[] = {10,8,23,15,16,2,9,4,29};
	int len = 9;
	BSTNode head = new node();
	head->value = -1;
	head->lchild = NULL;
	head->rchild = NULL;
	create_tree(A,len,head);
//	inorder(head);
	BSTNode tnode = search(head,10);
	tree_delete(head,tnode);
	inorder(head);
	/*
	if(tnode != NULL){
		if(tnode->lchild != NULL)
			cout<<"搜寻1结果的左节点:"<< tnode->lchild->value<<endl;
	}
	BSTNode succ = successor(tnode);
	cout<<"关键字为9的节点的后继为"<<succ->value<<endl; 
	tnode = search(head,15);
	if(tnode != NULL){
		BSTNode prec = predecessor(tnode);
    	cout<<"关键字15的前驱:"<<prec->value<<endl;
    }
	BSTNode tnode2 = search2(head,23);
	if(tnode2 != NULL){
		if(tnode2->lchild != NULL)
			cout<<"搜寻2结果的左节点:"<< tnode2->lchild->value<<endl;
	}
	BSTNode min_node = minimum(head);
	cout<<"最小元素为:"<<min_node->value<<endl;
	BSTNode max_node = maxmum(head);
	cout<<"最大元素为:"<<max_node->value<<endl;
	*/
	system("pause");
	return 0;
}

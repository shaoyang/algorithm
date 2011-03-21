#include<stdio.h>

#define RED 	0
#define BLACK 	1

//定义节点结构体node和指向该结构体的指针 
struct node
{
	struct node* parent;
	struct node* left;
	struct node* right;
	int color;
	int key;
}NIL_NODE = {NULL,NULL,NULL,BLACK,-1};

typedef struct node *nodeptr;
nodeptr NIL= &NIL_NODE;
nodeptr ROOT; 

void creat_tree(nodeptr z);
void left_rotate(nodeptr x);
void right_rotate(nodeptr x);
void insert(nodeptr z);
void insert_fixup(nodeptr z);

main()
{
	int i,num;
	//结构节点数组
	struct node nodes[9] = {
					{NULL ,NIL,NIL,BLACK,11},
					{NULL,NIL,NIL,RED,2},
					{NULL,NIL,NIL,BLACK,14},
					{NULL,NIL,NIL,BLACK,1},
					{NULL,NIL,NIL,BLACK,7},
					{NULL,NIL,NIL,RED,13},
					{NULL,NIL,NIL,RED,15},
					{NULL,NIL,NIL,RED,5},
					{NULL,NIL,NIL,RED,8}
					};
	nodeptr tnode = malloc(sizeof(struct node));
	//构建红黑树
	ROOT = NIL;
	i=0;
	num = 9;
	while(i<num){
		creat_tree(&nodes[i++]);
	}
	tnode->key = 12;
	insert(tnode);
	return 0;
}

void creat_tree(nodeptr z)
{
	nodeptr x,y;
	int i;
	x = ROOT;
	y = NIL;
	while(x != NIL){
		y = x;
		if(z->key <= x->key){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	z->parent = y;
	if( y == NIL){
		ROOT = z;
		ROOT->parent = NIL;
	}else if(y->key > z->key){
		y->left = z;
	}else{
		y->right = z;
	}
	z->left = NIL;
	z->right = NIL;
}

void insert(nodeptr z)
{
	nodeptr x,y;
	int i;
	x = ROOT;
	y = NIL;
	while(x != NIL){
		y = x;
		if(z->key <= x->key){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	z->parent = y;
	if( y == NIL){
		ROOT = z;
	}else if(y->key > z->key){
		y->left = z;
	}else{
		y->right = z;
	}
	z->left = NIL;
	z->right = NIL;
	z->color = RED;
	insert_fixup(z);
}

void insert_fixup(nodeptr z)
{
	nodeptr p,pp,y,left,right;
	//循环不变式 
	while( (p = (nodeptr)(z->parent)) != NIL && (pp = (nodeptr)(p->parent)) != NIL && (p->color == RED)){
		//z父亲为z祖父的左子
		if(p == pp->left){
			y = pp->right;
			//第一种情况 
			if(y->color == RED){
				p->color = BLACK;
				pp->color = RED;
				y->color = BLACK;
				z = pp;					//z上移两层 
			}
			else{
				//第二种情况 
				if(z == p->right){
					z = p;					//z上移一层 
					left_rotate(z);	//z下移一层 
				}
				//第三种情况 
				p->color = BLACK;
				pp->color = RED;
				right_rotate(pp);
			}
		}
		//z父亲为z祖父的左子 
		else{
			y = pp->left;
			if(y->color == RED){
				p->color = BLACK;
				y->color = BLACK;
				pp->color =	RED;
				z = pp;
			}else{ 
				if(z == p->left){
					z = p;					//上移一层 
					right_rotate(z);		//下移一层 
				}
				p->color = BLACK;
				pp->color = RED;
				left_rotate(pp);
			}
		}
	}
	ROOT->color = BLACK;
}

void left_rotate(nodeptr x)
{
	nodeptr y,p;
	y = x->right;
	x->right = y->left;
	p = x->parent;
	y->parent = p;
	if(p == NIL)
		ROOT = y;
	else if(x == p->left)
		p->left = y;
	else
		p->right = y;
	y->left = x;
	x->parent = y;
}

void right_rotate(nodeptr x)
{
	nodeptr y,p;
	y = x->left;
	x->left = y->right;
	p = x->parent;
	y->parent = p;
	if(p == NIL)
		ROOT = y;
	else if(x == p->left)
		p->left = y;
	else
		p->right = y;
	y->right = x;
	x->parent = y;
}

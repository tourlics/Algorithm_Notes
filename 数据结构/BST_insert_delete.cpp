//20191119
//BST insert & delete
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
//定义结点 
typedef struct BSTNode{
	int value;
	struct BSTNode *left;
	struct BSTNode *right;
}BSTNode; 
//函数声明 
void buildBST(int ,int []);
void insertnode(int );
BSTNode* findnode(int );
BSTNode* findparent(int );
void delenode(int );
void InOrder(BSTNode *);
BSTNode* succ(int );
//全局变量root根节点 
BSTNode *root = (BSTNode*)malloc(sizeof(BSTNode));
BSTNode *p = root;

void buildBST(int n,int data[]){
	root->value = data[0];
	root->left = NULL;
	root->right = NULL;
	for(int i=1;i<n;i++){
		insertnode(data[i]);
	}
}
void insertnode(int v){
	p = root;
	BSTNode *t = (BSTNode*)malloc(sizeof(BSTNode));
	t->value = v;
	t->left = NULL; 
	t->right = NULL;
	while(1){
		if(t->value < p->value){
			if(p->left!=NULL){
				p = p->left;	
			}else {
				p->left =t;
				break;
			}
		}else if(t->value >= p->value){
			if(p->right!=NULL){
				p = p->right;	
			}else{
				p->right =t;
				break;
			} 
		}
	}
}
BSTNode* findnode(int t){
	BSTNode *c = root;
	while(1){
		if(t < c->value && c->left!=NULL){
			c = c->left;	
		}else if(t > c->value && c->right!=NULL){
			c = c->right;	
		}else if(t == c->value){
			return c;
		}else return NULL;
	}
} 
BSTNode* findparent(BSTNode *m){
	BSTNode *c = root;
	while(1){
		if((c->left!=NULL && m == c->left) || (c->right!=NULL && m == c->right)){//解决了结点关键码相等的问题 
			return c;
		}else if(m->value < c->value && c->left!=NULL){
			c = c->left;	
		}else if(m->value >= c->value && c->right!=NULL){
			c = c->right;	
		}else return NULL;
	}
} 
BSTNode* succ(BSTNode *m){
	m = m->right;
	while(m->left != NULL){
		m = m->left;
	}
	//cout<<m->value;
	return m;
}

void delenode(BSTNode *m){ 
	BSTNode *pre = findparent(m);
	
	if(m->left!=NULL && m->right!=NULL){//两边都有 
		BSTNode *t =succ(m);//一个结点的后继结点必无左孩子
		pre =findparent(t);//先找父节点，不然出问题 
		m->value = t->value;
		if(t == pre->left){
			pre->left = t->right;
		}else if(t == pre->right){
			pre->right = t->right;
		} 	
	}else if(m == root){//考虑根节点没有父节点的情况 
		if(m->left != NULL) root = m->left;
		if(m->right != NULL) root = m->right;
		if(m->left == NULL && m->right == NULL) cout<<"you can not delete the last vertex!"<<endl;
	}
	else if(m == pre->left){ 
		if(m->left == NULL){
			pre->left = m->right;
		}
		else if(m->right == NULL){
			pre->left = m->left;
		}		
	}else if(m== pre->right){
		if(m->left == NULL){
			pre->right = m->right;
		}
		else if(m->right == NULL){
			pre->right = m->left;
		}	
	}
}
void InOrder(BSTNode *T){
	if(T!=NULL){
	    InOrder(T->left);
	    cout<<T->value<<" ";
	    InOrder(T->right);
	}
}
int main(){
	int data[30];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	buildBST(n,data);
	InOrder(root);
	cout<<endl;
	
	for(;;){
		char t[100];
		cin>>t;
		if(strcmp(t,"exit")==0) return 0;
		int d;
		
		if(strcmp(t,"insert")==0) {
			cin>>d;
			insertnode(d);
		}
		else if(strcmp(t,"delete")==0){
			cin>>d;
			BSTNode *m = findnode(d);
			if(!m) cout<<"it is not exits"<<endl;
			else delenode(m);	
		}
		InOrder(root);
		cout<<endl;
	}
	
	return 0;
}
/*------test-------
10
5 3 2 8 4 1 9 7 0 6
10
6 1 3 0 5 3 9 4 8 2
delete 3
6
2 5 8 7 6 9
*/

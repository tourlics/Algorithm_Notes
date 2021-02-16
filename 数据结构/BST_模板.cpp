//------BST的查找、插入、建立、删除----
//------------20200806----------- 
#include<iostream>
using namespace std;
struct Node{
	int value;
	struct Node *left;
	struct Node *right;
}; 
Node* newNode(int v){ //创建一个新结点，返回指向新结点的指针（新结点的地址） 
	Node* node = new Node;
	node->value = v;
	node->left = NULL;
	node->right = NULL;
	return node;
}
Node* Search(Node* root,int x){ //从根结点开始，查找值为x的结点，返回指向该结点的指针 
	if(root == NULL){ //判断是否为空树 
		return NULL; 
	}
	if(root->value == x){
		return root; //唯一的返回值 
	}else if(x < root->value){
		Search(root->left,x);
	}else{
		Search(root->right,x);
	}
}
void Insert(Node* &root,int x){ //返回指向新插入结点的指针 
//由于要对树进行修改，所以必须加引用& 
	if(root == NULL){ //是空树，创建根结点 
		root = newNode(x);
		return ;
	}
	if(x < root->value){
		Insert(root->left,x);
	}
	if(x >= root->value){
		Insert(root->right,x);
	}
}
Node* Creat(int data[],int n){ //返回BST的根结点 
	Node* root = NULL;
	for(int i=0;i<n;i++){
		Insert(root,data[i]);
	}
	return root;
} 
Node* succ(Node *p){
	p = p->right;
	while(p->left != NULL){
		p = p->left;
	}
	return p;
}
Node* findParent(Node* root,Node *m){
	Node *c = root;
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
void Delete(Node* &root,int x){
	Node* p = Search(root,x);
	if(p->left && p->right){ //左子树右子树均不为空 
		Node* s = succ(p);
		p->value = s->value;
		p = s;
	}
	//上面处理完双分支的情况，下面处理单分支的情况 
	if(p->left && !p->right){
		p->value = p->left->value;
		delete(p->left);
		p->left = NULL; //delete(p->left)以后 (p->left)不一定指向NULL!!! 
		return ;
	}
	if(p->right && !p->left){
		p->value = p->right->value;
		delete(p->right);
		p->right = NULL;
		return ;
	}
	if(!p->left && !p->right){
		Node* pre = findParent(root,p);
		if(pre->left == p) pre->left = NULL;
		if(pre->right == p) pre->right = NULL;
		delete(p);
		return ;
	}
}
void InOrder(Node *T){
	if(T!=NULL){
	    InOrder(T->left);
	    cout<<T->value<<" ";
	    InOrder(T->right);
	}
}
int main(){
	int arr[] = {6,1,9,8,0,3,2,5,3};
	Node* root = Creat(arr,9);
	InOrder(root);
	cout<<endl;
	Node* p = Search(root,5);
	cout<<p->value<<endl;
	Insert(root,4);
	InOrder(root);
	cout<<endl;
	Delete(root,3);
	InOrder(root);
	return 0;
}


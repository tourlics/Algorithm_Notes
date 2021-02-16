//20200211
//AVL Tree
#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int data;
	int height;
	node* left;
	node* right;
};
node* newnode(int v){
	node* p = new node;
	p->data = v;
	p->height = 1;
	p->left = NULL;
	p->right = NULL;
	return p;
}
int getHeight(node* root){
	if(root == NULL) return 0;
	return root->height;
}
int getBalanceFactor(node* root){
	if(root == NULL) return 0;
	return getHeight(root->left) - getHeight(root->right);
}
void updateHeight(node* root){
	root->height = max(getHeight(root->left) , getHeight(root->right)) + 1;
}
node* search(node* root,int v){
	if(root == NULL) return NULL;
	if(root->data == v) return root;
	else if(v < root->data) search(root->left,v);
	else search(root->right,v);
}
void leftrotation(node* &root){
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void rightrotation(node* &root){
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node* &root,int v){
	if(root == NULL){
		root = newnode(v);
		return ;
	}
	if(v >= root->data){
		insert(root->right,v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->right) == -1)
				leftrotation(root);
			else if(getBalanceFactor(root->right) == 1){
				rightrotation(root->right);
				leftrotation(root);
			}
		}
	}else if(v < root->data){
		insert(root->left,v);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->left) == 1)
				rightrotation(root);
			else if(getBalanceFactor(root->left) == -1){
				leftrotation(root->left);
				rightrotation(root);
			}
		}	
	}
	
}
node* buildAVL(int data[],int n){
	node* root = NULL;
	for(int i=0;i<n;i++) insert(root,data[i]);
	return root;
}
void InOrder(node *T){
	if(T!=NULL){
	    InOrder(T->left);
	    cout<<T->data<<" ";
	    InOrder(T->right);
	}
}
void PreOrder(node *T){
    if(T){
        cout<<T->data<<" ";
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

void PostOrder(node *T){
    if(T!=NULL){
	    PostOrder(T->left);
	    PostOrder(T->right);
	    cout<<T->data<<" ";
	}
}
int main(){
	int n,data[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&data[i]);
	node* root = buildAVL(data,n);
	cout<<"InOrder:"<<endl;
	InOrder(root);
	cout<<endl;
	cout<<"PreOrder:"<<endl;
	PreOrder(root);
	cout<<endl;
	cout<<"PostOrder:"<<endl;
	PostOrder(root); 
	return 0;
}
/*----Test---
10
60 50 80 20 55 70 90 10 40 35
*/

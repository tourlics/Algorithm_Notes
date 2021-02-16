//20191116
//BST build & traverse
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct BSTNode{
	int value;
	struct BSTNode *left;
	struct BSTNode *right;
}BSTNode; 
BSTNode *root = (BSTNode*)malloc(sizeof(BSTNode));

void buildBST(int n,int data[]){
	root->value = data[0];
	root->left = NULL;
	root->right = NULL;
	BSTNode *p = root;
	for(int i=1;i<n;i++){
		p = root;
		BSTNode *t = (BSTNode*)malloc(sizeof(BSTNode));
		t->value = data[i];
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
}
void InOrder(BSTNode *T){
	if(T!=NULL){
	    InOrder(T->left);
	    cout<<T->value<<" ";
	    InOrder(T->right);
	}
}
void PreOrder(BSTNode *T){
    if(T){
        cout<<T->value<<" ";
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

void PostOrder(BSTNode *T){
    if(T!=NULL){
	    PostOrder(T->left);
	    PostOrder(T->right);
	    cout<<T->value<<" ";
	}
}

int main(){
	int data[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	buildBST(n,data);
	cout<<"InOrder:"<<endl;
	InOrder(root);//中序遍历结果按从小到大顺序输出
	cout<<endl;
	cout<<"PreOrder:"<<endl;
	PreOrder(root);
	cout<<endl;
	cout<<"PostOrder:"<<endl;
	PostOrder(root); 
	return 0;
}
/*------test-------
10
5 3 2 8 4 1 9 7 0 6
10
6 1 3 0 5 3 9 4 8 2
*/

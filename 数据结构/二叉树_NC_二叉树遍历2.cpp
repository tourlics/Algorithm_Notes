//create on 20210204
//牛客网-二叉树遍历
//由带#的先序序列构建二叉树
#include<iostream>
#include<string>
using namespace std;
struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}; 
Node* newNode(char v){ //创建一个新结点，返回指向新结点的指针（新结点的地址） 
	Node* node = new Node;
	node->value = v;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void InOrder(Node *T){ //后序遍历，左右中
    if(T!=NULL){
	    InOrder(T->left);
        cout<<T->value<<" ";
	    InOrder(T->right);
	}
}
int pos;
string s;
Node* build(){
    char x = s[pos++];
    if(x == '#') return NULL;
    Node* root = newNode(x);
    root->left = build();
    root->right = build();
    return root;
}

int main(){
    while(cin>>s){
        Node* root = build();
        InOrder(root);
        s.clear();
    }
    return 0;
}
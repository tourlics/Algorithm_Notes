//create on 20210204
//牛客网-二叉树遍历
//由先序遍历、中序遍历求后序遍历
#include<iostream>
#include<string>
using namespace std;
struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}; 
string prenode; //保存先序遍历的结果
string innode; //保存中序遍历的结果

Node* newNode(char v){ //创建一个新结点，返回指向新结点的指针（新结点的地址） 
	Node* node = new Node;
	node->value = v;
	node->left = NULL;
	node->right = NULL;
	return node;
}
Node* build(int sp,int ep,int si,int ei){ //sp表示先序数组的起始点，ep表示先序数组的终止点
    Node* root = newNode(prenode[sp]); //创建一个结点
    int pos = innode.find(prenode[sp]);
    if(pos != si){ //以该结点作为所在子树的根结点，且左子树不为空
        root->left = build(sp+1,sp+pos-si,si,pos-1); //注意理解每个参数的确定方法
    }
    if(pos != ei){
        root->right = build(sp+pos-si+1,ep,pos+1,ei);
    }
    return root;
}
void PostOrder(Node *T){ //后序遍历，左右中
    if(T!=NULL){
	    PostOrder(T->left);
	    PostOrder(T->right);
	    cout<<T->value;
	}
}

int main(){
	while(cin>>prenode){
		cin>>innode;
		int prelen = prenode.length();
        int inlen = innode.length();
        Node* root = build(0,prelen-1,0,inlen-1);
        PostOrder(root);
        cout<<endl;
		prenode.clear();
        innode.clear();
	}
	return 0;
}


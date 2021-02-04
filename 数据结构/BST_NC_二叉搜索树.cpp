//create on 20210204
//牛客网-二叉搜索树
//判断两个序列构成的BST是否是同一颗BST：判断其先序序列是否相等
#include<iostream>
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

void Insert(Node* &root,char x){ //返回指向新插入结点的指针 
//由于要对树进行修改，所以必须加引用& 
	if(root == NULL){ //是空树，创建根结点 
		root = newNode(x);
		return ;
	}
	if(x < root->value){
		Insert(root->left,x);
	}
	if(x > root->value){
		Insert(root->right,x);
	}
}
Node* Creat(string data){ //返回BST的根结点 
	Node* root = NULL;
    int n = data.size();
	for(int i=0;i<n;i++){
		Insert(root,data[i]);
	}
	return root;
} 

//注意不要将check的返回值设置为bool，而应该在外面弄一个flag，不然在返回的时候会很混乱
bool flag = 1;
void check(Node* a,Node* b){ //判断先序序列是否相等
    if(a!=NULL && b!= NULL){
        if(a->value != b->value) flag = 0;
        check(a->left,b->left);
        check(a->right,b->right);
    }
    else if(a!=NULL || b!=NULL) flag = 0;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        string arr;
        cin>>arr;
        Node* root = Creat(arr);
        for(int i=0;i<n;i++){
            flag = 1;
            string tmp;
            cin>>tmp;
            Node* judge = Creat(tmp);
            check(root,judge);
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
	return 0;
}


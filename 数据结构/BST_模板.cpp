//------BST�Ĳ��ҡ����롢������ɾ��----
//------------20200806----------- 
#include<iostream>
using namespace std;
struct Node{
	int value;
	struct Node *left;
	struct Node *right;
}; 
Node* newNode(int v){ //����һ���½�㣬����ָ���½���ָ�루�½��ĵ�ַ�� 
	Node* node = new Node;
	node->value = v;
	node->left = NULL;
	node->right = NULL;
	return node;
}
Node* Search(Node* root,int x){ //�Ӹ���㿪ʼ������ֵΪx�Ľ�㣬����ָ��ý���ָ�� 
	if(root == NULL){ //�ж��Ƿ�Ϊ���� 
		return NULL; 
	}
	if(root->value == x){
		return root; //Ψһ�ķ���ֵ 
	}else if(x < root->value){
		Search(root->left,x);
	}else{
		Search(root->right,x);
	}
}
void Insert(Node* &root,int x){ //����ָ���²������ָ�� 
//����Ҫ���������޸ģ����Ա��������& 
	if(root == NULL){ //�ǿ�������������� 
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
Node* Creat(int data[],int n){ //����BST�ĸ���� 
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
		if((c->left!=NULL && m == c->left) || (c->right!=NULL && m == c->right)){//����˽��ؼ�����ȵ����� 
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
	if(p->left && p->right){ //����������������Ϊ�� 
		Node* s = succ(p);
		p->value = s->value;
		p = s;
	}
	//���洦����˫��֧����������洦����֧����� 
	if(p->left && !p->right){
		p->value = p->left->value;
		delete(p->left);
		p->left = NULL; //delete(p->left)�Ժ� (p->left)��һ��ָ��NULL!!! 
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


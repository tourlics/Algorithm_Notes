//-----------有头结点单向链表搭建（头插法）20200806-------------------
#include<iostream>
using namespace std;
//链表的结点有两部分构成：数据域和指针域
typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node* Creat(int arr[],int n){ //创建单向链表，返回头结点指针 
	//创建头结点 
    Node* head = new Node; //new+类型名 申请动态内存空间 
    head->value = -1;
    head->next = NULL;
    Node *pre = head;//复制指向头结点的指针，pre的作用是指向当前节点的前驱结点 
    for(int i=0;i<n;i++){
    	//根据arr数组创建结点
        Node *t = new Node;
        t->value = arr[i];
        t->next = NULL; 
        //更新pre结点 
        pre->next = t;//当前结点的前驱结点的指针域指向当前结点 
        pre = pre->next;//当前结点为下一结点的前驱结点 
    } //执行到这里到了最后一个结点pre->next为NULL
    return head;//返回头结点指针 
} 
Node* Search(Node* head,int x){ //查找链表中指定的值，返回指向该值所在结点的指针 
	Node* p = head->next; //从第一个结点开始
	while(p != NULL){
		if(p->value == x){
			break;
		}
		p = p->next;
	} 
	return p;
}
Node* Insert(Node* head,int pos,int x){ //将值为x的结点插入第pos个位置，返回插入节点指针 
	//定位到第pos个位置 
	Node* p = head; 
	for(int i=0;i<pos-1;i++){ //定位到pos的前一个位置 
		p = p->next;
	}
	//新建结点 
	Node* np = new Node;
	np->value = x;
	np->next = p->next;
	p->next = np; 
	return np;
}
Node* Delete(Node* head,int x){ //删除链表中第一个值为x的结点，返回下一结点指针
	Node* p = head->next;
	Node* pre = head;
	//定位到要删除的结点 
	while(p){
		if(p->value == x){
			pre->next = p->next;
			delete(p); //指针变量p本身并没有消失，p指向了NULL，但p指向的内存释放了 
			p = pre->next; 
			break;
		}
		pre = p;
		p = p->next;
	} 
	return p;
}
void show(Node* head){
	Node* p = head->next;
	while(p){
		printf("%d ",p->value);
		p = p->next;
	}
	cout<<endl;
}
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	Node* head = Creat(arr,9);
	show(head);
	Node* s = Search(head,4);
	printf("%d\n",s->value);
	Node* in = Insert(head,3,12);
	printf("%d\n",in->value);
	show(head);
	Node* de = Delete(head,5);
	printf("%d\n",de->value);
	show(head);
	
    return 0;
}
/*//注意C语言中malloc申请动态内存也应该掌握 
	#include<stdlib.h>  //malloc函数
	Node *head = (Node*)malloc(sizeof(Node));
	//即 typename* p = (typename*)malloc(sizeof(typename)); 
	//返回指向这块空间（申请的空间）的指针 
*/

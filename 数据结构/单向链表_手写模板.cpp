//-----------��ͷ��㵥��������ͷ�巨��20200806-------------------
#include<iostream>
using namespace std;
//����Ľ���������ֹ��ɣ��������ָ����
typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node* Creat(int arr[],int n){ //����������������ͷ���ָ�� 
	//����ͷ��� 
    Node* head = new Node; //new+������ ���붯̬�ڴ�ռ� 
    head->value = -1;
    head->next = NULL;
    Node *pre = head;//����ָ��ͷ����ָ�룬pre��������ָ��ǰ�ڵ��ǰ����� 
    for(int i=0;i<n;i++){
    	//����arr���鴴�����
        Node *t = new Node;
        t->value = arr[i];
        t->next = NULL; 
        //����pre��� 
        pre->next = t;//��ǰ����ǰ������ָ����ָ��ǰ��� 
        pre = pre->next;//��ǰ���Ϊ��һ����ǰ����� 
    } //ִ�е����ﵽ�����һ�����pre->nextΪNULL
    return head;//����ͷ���ָ�� 
} 
Node* Search(Node* head,int x){ //����������ָ����ֵ������ָ���ֵ���ڽ���ָ�� 
	Node* p = head->next; //�ӵ�һ����㿪ʼ
	while(p != NULL){
		if(p->value == x){
			break;
		}
		p = p->next;
	} 
	return p;
}
Node* Insert(Node* head,int pos,int x){ //��ֵΪx�Ľ������pos��λ�ã����ز���ڵ�ָ�� 
	//��λ����pos��λ�� 
	Node* p = head; 
	for(int i=0;i<pos-1;i++){ //��λ��pos��ǰһ��λ�� 
		p = p->next;
	}
	//�½���� 
	Node* np = new Node;
	np->value = x;
	np->next = p->next;
	p->next = np; 
	return np;
}
Node* Delete(Node* head,int x){ //ɾ�������е�һ��ֵΪx�Ľ�㣬������һ���ָ��
	Node* p = head->next;
	Node* pre = head;
	//��λ��Ҫɾ���Ľ�� 
	while(p){
		if(p->value == x){
			pre->next = p->next;
			delete(p); //ָ�����p����û����ʧ��pָ����NULL����pָ����ڴ��ͷ��� 
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
/*//ע��C������malloc���붯̬�ڴ�ҲӦ������ 
	#include<stdlib.h>  //malloc����
	Node *head = (Node*)malloc(sizeof(Node));
	//�� typename* p = (typename*)malloc(sizeof(typename)); 
	//����ָ�����ռ䣨����Ŀռ䣩��ָ�� 
*/

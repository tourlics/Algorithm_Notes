//20191207
//解码：二进制转字符
// Internal nodes and leaf nodes are represented by the same classes(struct)
#include<iostream>
#include<stdlib.h>
#define inf 99999
using namespace std;
int n;
int k;
typedef struct Node{
	char data;
	int weight;
	Node* left;
	Node* right;
	int state;//0:leaf&unbook; 1:inter&unbook; 2:book;//3:inter&book
}Node;
Node leaf[201];
Node* root = (Node*)malloc(sizeof(Node));
Node* cur = (Node*)malloc(sizeof(Node));
int minimal(){
	int minn = inf;
	int index;
	for(int i=0;i<2*n;i++){
		if((leaf[i].state!=2) && leaf[i].weight<minn) {
			minn = leaf[i].weight;
			index = i;
		}
	}
	leaf[index].state = 2;
	return index;
}

void merge(){
	int min1 = minimal();
	int min2 = minimal();
	leaf[n+k].weight = leaf[min1].weight + leaf[min2].weight;
	leaf[n+k].left = &leaf[min1];
	leaf[n+k].right = &leaf[min2];
	root = &leaf[n+k];
	k++;
}

bool finish(){
	for(int i=0;i<n;i++)
		if(leaf[i].state==0) 
			return false;
	return true;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) {
		int t;
		cin>>t;
		leaf[i].weight = t;
		leaf[i].state = 0;
	}
	for(int i=n;i<2*n;i++) leaf[i].weight=inf;
	for(int i=0;i<n;i++){
		char t;
		cin>>t;
		leaf[i].data=t;
	} 
	while(!finish()){
		merge();
	}
	int m;
	cin>>m;
	cur = root;
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		if(t==0){
			cur = cur->left;
			if(cur->data!='\0') {
				cout<<cur->data<<" ";
				cur = root;
				continue;
			}
		}else{
			cur = cur->right; 
			if(cur->data!='\0') {
				cout<<cur->data<<" ";
				cur = root;
				continue;
			}
		}
	}
	return 0;
}
/*-----Test-------
8
2 7 24 32 37 42 42 120
z k m c u d l e
10
1 0 1 1 0 1 1 0 0 0
//test1 
9
2 7 24 32 37 42 42 120 307
b i r y a d p h t
55
0 0 0 1 0 0 0 1 1 0 0 1 1 0 0 1 1 1 0 0 1 1 1 1 0 0 0 1 1 1 1 0 1 0 1 1 1 1 1 1 0 0 0 1 0 1 0 1 0 0 0 1 1 1 0
//00 0100 0110 0110 01110 0111100 0111101 01111 1 100 0101 0100 01110
//test2- from notes(unsolved)
8
2 3 10 10 10 15 20 20
Q Z F M T S O E
3
0 0 0
*/

//20200210
//编码：字符转二进制
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
struct Node{
	char data;
	int weight;
	Node* left;
	Node* right;
	friend bool operator < (Node a,Node b){
		if(a.weight == b.weight) return a.data > b.data;
		else return a.weight > b.weight;
	}
};

priority_queue<Node>q;
int main(){
	int n; // the number of char
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		Node temp;
		scanf("%d %c\n",&temp.weight,&temp.data);
		q.push(temp);
	}
	char str[1000];
	fgets(str,1000,stdin);
	while(q.size()>1){
		Node* t1 = new Node;
		*t1 = q.top();
		q.pop();
		Node* t2 = new Node;
		*t2 = q.top();
		q.pop();
		Node tn;
		tn.weight = t1->weight + t2->weight;
		tn.left = t1;
		tn.right = t2;
		q.push(tn);
	}
	Node* root = new Node;
	*root = q.top();
	Node* cur = root;
	for(int i=0;i<strlen(str);i++){
		if(str[i] == '0' ){
			cur = cur->left;
			if(cur->data != '\0'){
				printf("%c",cur->data);
				cur = root;
			}
		}
		else if(str[i] == '1' ){
			cur = cur->right;
			if(cur->data != '\0'){
				printf("%c",cur->data);
				cur = root;
			}
		}
	}
	return 0;
}
/*-----Test-------
//ddue
8
2 z
7 k
24 m
32 c
37 u
42 d
42 l
120 e
1011011000
//happybirthday 
9
2 b
7 i
24 r
32 y
37 a
42 d
42 p
120 h
307 t
0001000110011001110011110001111010111111000101010001110
//test2- from notes E
8
2 Q
3 Z
10 F
10 M
10 T
15 S
20 O
20 E
000
*/

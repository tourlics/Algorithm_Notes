#include<iostream>
#include<algorithm>

using namespace std;

typedef struct {
	int a;
	double b;
}Node;
bool cmp1(Node t1,Node t2){
	return t1.a < t2.a;
}
bool cmp2(Node t1,Node t2){
	return t1.b < t2.b;
}

int main(){
	Node arr[100] = {
		{9,3.5},
		{4,1.2},
		{6,8.2},
		{3,3.7},
		{1,2.1}
	};
	sort(arr,arr+5,cmp1);
	for(int i=0;i<5;i++){
		cout<<arr[i].a<<" "<<arr[i].b;
		cout<<endl;
	}
	cout<<endl;
	sort(arr,arr+5,cmp2);
	for(int i=0;i<5;i++){
		cout<<arr[i].a<<" "<<arr[i].b;
		cout<<endl;
	}
	cout<<endl;
	return 0;
} 

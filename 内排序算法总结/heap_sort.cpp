//create on 20191120
#include<iostream>
#include<math.h>

using namespace std;
int data[100];
int n ;

void swap(int& ,int& );
int lastinternal();
bool Inheap(int );//判断是否为内部结点 
int parenti(int );
int lefti(int );
int righti(int );
void buildheap();
void showbt();
void percolateDown(int );
void heapsort();

void swap(int &a,int &b){
	int t;
	t = a;
	a = b;
	b = t;
}
int lastinternal(){
	return ceil((n-1)/2);
}
bool Inheap(int index){
	if(data[lefti(index)]<n);
}
int parenti(int v){//传入的都是下标 
	int t = floor((v-1)/2);
	if(t>=0) return t;
	else return -1;
}
int lefti(int v){
	return 2*v+1;
}
int righti(int v){
	return 2*v+2;
}

void percolateDown(int index){
	while((data[index] < data[lefti(index)])||(data[index] < data[righti(index)])){
		if(righti(index) >= n) break;//由于共用一块内存，所以一定要划定边界 
		if(data[lefti(index)]>data[righti(index)]){
			swap(data[lefti(index)],data[index]);
			index = lefti(index);
		} else {
			swap(data[index],data[righti(index)]);
			index = righti(index);
		}
	}
}

void heapsort(){//percolateDown
	while(n!=1){
		swap(data[0] , data[n-1]);//@override deleMax
		n--;//用最后一个元素代替堆顶元素，然后下滤
		percolateDown(0);
		showbt();
	}
	
}
void buildheap(){//Floyd算法 
	for(int i =lastinternal();i>=0;i--){
		if(Inheap(i)) 
			percolateDown(i);
	}
}
void showbt(){
	for(int i=0;i<n;i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
}


int main(){
	cin>>n;
	int t = n;
	for(int i =0;i<n;i++) cin>>data[i];
	buildheap();
	showbt();
	heapsort();
	for(int i=0;i<t;i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;

	return 0;
}
/*--------Test----------
9
6 3 5 1 4 3 2 1 3
*/

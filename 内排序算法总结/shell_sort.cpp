//create on 20191123;update on 20210129
//希尔排序
#include<iostream>
using namespace std;
int seq[100] = {}; //增量序列
void make_seq_Hibbard(int n){ //生成增量序列 2^k-1,...,1
	int i = 0;
	for(int k=1;k<=n/2;k=k*2+1){
		seq[i++] = k;
	}
	for(int j=0;j<i/2;j++){ //反转数组
		int temp = seq[j];
		seq[j] = seq[i-j-1];
		seq[i-j-1] = temp;
	}
	for(int j=0;j<i;j++) cout<<seq[j]<<" "; //输出增量序列
	cout<<endl;
}
void make_seq_double(int n){ //生成增量序列 n/2,n/4,...,1
	int i = 0;
	while(n!=1){
		n = n/2;
		seq[i++] = n;
	}
	for(int j=0;j<i;j++) cout<<seq[j]<<" "; //输出增量序列
	cout<<endl;
}
void swap(int A[],int a,int b){
	int t;
	t = A[a];
	A[a] = A[b];
	A[b] = t;
}

void subsort(int a[], int n, int incre) { //对每一个sublist进行排序
	for(int i=incre;i<n;i+=incre){ //实质就是插入排序
		for(int j=i;j>0&&(a[j]<a[j-incre]);j-=incre){
			swap(a,j,j-incre);	 
		}
	}
}

void shellsort(int a[], int n) { // Shellsort
	for(int i=0;seq[i]!=0;i++){ // For each increment(i),当增量序列到0时停止
		subsort(a, n, seq[i]);
		for(int k=0;k<n;k++) cout<<a[k]<<" "; //输出每一轮排序结果
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	//make_seq_double(n);
	make_seq_Hibbard(n);
	int a[1000];
	for(int i=0;i<n;i++) cin>>a[i];
	shellsort(a,n);
	return 0;
}
/*test
20
1 3 4 32 8 73 0 23 89 4 43 7 54 98 5 7 32 10 8 43
*/
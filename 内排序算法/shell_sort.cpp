//write on 20191123
//update on 20210129
//????
#include<iostream>
using namespace std;
void swap(int A[],int a,int b){
	int t;
	t = A[a];
	A[a] = A[b];
	A[b] = t;
}

void subsort(int a[], int n, int incre) {
	for(int i=incre;i<n;i+=incre){ //????????
		for(int j=i;j>0&&(a[j]<a[j-incre]);j-=incre){
			swap(a,j,j-incre);	 
		}
	}
}

void shellsort(int a[], int n) { // Shellsort
	for (int i=n/2; i>2; i/=2) // For each increment(i)
		subsort(a, n, i);
	subsort(a, n, 1);
	for(int k=0;k<n;k++) cout<<a[k]<<" ";
		cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++) cin>>a[i];
	shellsort(a,n);
	return 0;
}

//write on 20191201
//带有阈值的归并排序：当小于一定阈值时，直接调用快速排序 
#include<iostream>
#define threshold 3
using namespace std;
int n;

void quicksort(int a[],int left,int right){
	int i,j,temp;
	if(left>right) return ; 
	
	temp = a[left];//temp是基准数，选取数列中最左侧的数为基准数 
	i = left;//i负责从左往右搜索比基准数大的数 
	j = right;//j负责从右往左搜索比基准数小的数 
	while(i != j){
		while(i < j && a[j] >= temp) j--;//注意顺序，先从右往左搜索 
		while(i < j && a[i] <= temp) i++;
		if(i < j){//交换两数的位置 
			int t;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//结束循环后，i==j 
	a[left] = a[i];
	a[i] = temp;
	//上述两步交换了基准数的位置 
	
	quicksort(a,left,i-1);//递归对i左侧的数进行同样操作 
	quicksort(a,i+1,right);//递归对i右侧的数进行同样操作 
	
}

void mergesort(int A[],int temp[], int left, int right) {
	if (right - left <= threshold) { //当小于一定阈值时，直接调用快速排序 
		quicksort(A,left,right);
		return; // List of one element
	}
	int mid = (left+right)/2;
	mergesort(A, temp, left, mid);
	mergesort(A, temp, mid+1, right);
	for (int i=left; i<=right; i++) // Copy subarray to temp
		temp[i] = A[i];// Do the merge operation back to A
	int i1 = left; int i2 = mid + 1;
	for (int curr=left; curr<=right; curr++) {
		if (i1 == mid+1) // Left sublist exhausted
			A[curr] = temp[i2++];
		else if (i2 > right) // Right sublist exhausted
			A[curr] = temp[i1++];
		else if (temp[i1]<temp[i2])
			A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
	for(int i=0;i<n;i++) cout<<A[i]<<" ";
	cout<<endl;
}

int main(){
	cin>>n;
	int a[20];
	for(int i =0;i<n;i++) cin>>a[i];
	int temp[20] = {0};
	mergesort(a,temp,0,n-1);
	return 0;
}

/*-------Test-------
14
17 5 0 88 21 35 5 3 8 56 34 54 66 10
25
17 5 0 88 21 35 5 3 8 56 34 54 66 10 38 75 67 58 98 65 22 45 60 81 40
*/

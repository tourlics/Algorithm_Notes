//write on 20191201
//������ֵ�Ĺ鲢���򣺵�С��һ����ֵʱ��ֱ�ӵ��ÿ������� 
#include<iostream>
#define threshold 3
using namespace std;
int n;

void quicksort(int a[],int left,int right){
	int i,j,temp;
	if(left>right) return ; 
	
	temp = a[left];//temp�ǻ�׼����ѡȡ��������������Ϊ��׼�� 
	i = left;//i����������������Ȼ�׼������� 
	j = right;//j����������������Ȼ�׼��С���� 
	while(i != j){
		while(i < j && a[j] >= temp) j--;//ע��˳���ȴ����������� 
		while(i < j && a[i] <= temp) i++;
		if(i < j){//����������λ�� 
			int t;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//����ѭ����i==j 
	a[left] = a[i];
	a[i] = temp;
	//�������������˻�׼����λ�� 
	
	quicksort(a,left,i-1);//�ݹ��i����������ͬ������ 
	quicksort(a,i+1,right);//�ݹ��i�Ҳ��������ͬ������ 
	
}

void mergesort(int A[],int temp[], int left, int right) {
	if (right - left <= threshold) { //��С��һ����ֵʱ��ֱ�ӵ��ÿ������� 
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

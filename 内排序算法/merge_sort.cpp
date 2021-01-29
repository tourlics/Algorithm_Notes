//create on 20191201
#include<iostream>
using namespace std;
int n;
void mergesort(int A[],int temp[], int left, int right) {
	if (left == right) return; // List of one element
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
7
17 5 0 88 21 35 5
14
17 5 0 88 21 35 5 3 8 56 34 54 66 10
*/

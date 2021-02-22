//create on 20200123
//相对于上一版本，将递归函数的返回值改成了int型，使代码更简洁
#include<iostream>
using namespace std;
int arr[100];
int findpivot(int left,int right){
	return (left+right)/2;
}
void swap(int a,int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int quickselect(int left,int right,int k){
	//if(left >= right) return arr[right];
	int index = findpivot(left,right);
	int pivot = arr[index];
	swap(index,right);
	int lp = left;
	int rp = right;
	while(lp < rp){
		while((lp < rp) && (arr[lp] <= pivot)) lp++;
		while((lp < rp) && (arr[rp] >= pivot)) rp--;
		swap(lp,rp);
	}
	swap(right,lp);
	index = lp;
	if(k == index + 1) return arr[index];
	if(k < index + 1) return quickselect(left,index-1,k);
	if(k > index + 1) {
		//k = k - index - 1;
		return quickselect(index+1,right,k);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	cout<<quickselect(0,n-1,n/2)<<endl;
	
	return 0;
}

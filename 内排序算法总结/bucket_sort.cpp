//create on 20191201
#include<iostream>
#include<math.h>
using namespace std;
int n;
int k =15;//划分为15等分
int A[14][20];
int getmin(int temp[]){
	int min = 99999;
	for(int i =0;i<n;i++){
		if(temp[i]<min) min = temp[i];
	}
	return min;
}
int getmax(int temp[]){
	int max = 0;
	for(int i =0;i<n;i++){
		if(temp[i]>max) max = temp[i];
	}
	return max;
}
void swap(int a[],int i,int j){ //交换两个数的位置 
	int temp;
	temp = a[j];
	a[j] = a[i];
	a[i] = temp;
}
void insert_sort(int a[],int m){
	for(int i=1;i<m;i++){  
		for(int j=i;j>0&&(a[j]<a[j-1]);j--){
		//注意一旦a[j]>=a[j-1]就不用继续比较了，因为前面是排好序的 
			swap(a,j,j-1);	 
		}
	}
}
void bucket(int temp[],int num[],int gap){
	int t = getmin(temp);
	for(int i=0;i<n;i++){
		A[(temp[i]-t)/gap][num[(temp[i]-t)/gap]++] = temp[i];
	}
	for(int s=0;s<=k;s++) insert_sort(A[s],num[s]);//为了出现下面示例这种情况，k要取等号 
}
void show(int num[],int temp[],int gap){
	for(int i=0;i<=k;i++){
		cout<<getmin(temp)+i*gap<<"--"<<getmin(temp)+(i+1)*gap-1<<": ";
		if(i!=0&&A[i][0]==0){
			cout<<0<<endl;
			continue;
		}
		for(int j = 0;j<num[i];j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<=k;i++){
		for(int j = 0;j<num[i];j++){
			if(A[i][j] != 0)cout<<A[i][j]<<" ";
		}
	}
}
int main(){
	int num[20] = {0};
	int temp[300];
	cin>>n;
	for(int i=0;i<n;i++) cin>>temp[i];
	int gap = ceil((double)(getmax(temp)-getmin(temp))/k); //每一个区间长度 
	cout<<"gap = "<<gap<<endl;
	bucket(temp,num,gap);
	show(num,temp,gap);
	return 0;
}
/*---Test----
19
43 54 89 24 30 65 23 90 75 34 20 83 19 10 49 18 98 99 100
*/

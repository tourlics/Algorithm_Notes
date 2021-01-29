//create on 20191104;update on 20210129
// 三大基础排序算法：插入排序；冒泡排序；选择排序
#include<iostream>
using namespace std;
void swap(int a[],int i,int j){ //交换两个数的位置 
	int temp;
	temp = a[j];
	a[j] = a[i];
	a[i] = temp;
}
int mini_num(int data[],int s,int n){ //找出a[s]到a[n]区间最小元素下标 
	int minn = data[s];
	int index;
	for(int i=s+1;i<n;i++){
		if(data[i] < minn) {
			minn = data[i];
			index = i;
		}
	}
	return index;
}
void insert_sort(int a[],int n){
	cout<<"----Insert sort----"<<endl;
	for(int i=1;i<n;i++){  
		for(int j=i; j>0 && (a[j]<a[j-1]); j--){
		//注意一旦a[j]>=a[j-1]就不用继续比较了，因为前面是排好序的 
			swap(a,j,j-1);	 
		}
		for(int k=0;k<n;k++) cout<<a[k]<<" "; //输出每一轮排序的结果
		cout<<endl;
	}	
	cout<<"-----The END-----"<<endl;
}
void bubble_sort(int a[],int n){
	cout<<"----Bubble sort----"<<endl;
	for(int i=0;i<n-1;i++){ //外层循环，执行n论排序
		for(int j=0;j<n-1;j++){ //内层循环，每两个之间相比较
			if(a[j]>a[j+1]) {
				swap(a,j,j+1);	
			}	
		}
		for(int k=0;k<n;k++) cout<<a[k]<<" "; //输出每一轮排序的结果
		cout<<endl;
	}	
	cout<<"-----The END-----"<<endl;
}
void selection_sort(int a[],int n){
	cout<<"----Selection sort----"<<endl;
	for(int i=0;i<n;i++){  
		swap(a,i,mini_num(a,i,n)); //把无序序列中最小的同无序序列中第一个元素交换 
		for(int k=0;k<n;k++) cout<<a[k]<<" ";
		cout<<endl;
	}	
	cout<<"-----The END-----"<<endl;
}

int main(){
	int n;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<"choose which sorting"<<endl;
	cout<<"1.Insert sorting"<<endl;
	cout<<"2.Bubble sorting"<<endl;
	cout<<"3.Selection sorting"<<endl;
	
	int c;
	cin>>c;
	if(c==1) insert_sort(a,n);
	if(c==2) bubble_sort(a,n);
	if(c==3) selection_sort(a,n);
		
	return 0;
}
/*
-----test-----
10
2 4 1 5 0 7 8 2 5 3
*/


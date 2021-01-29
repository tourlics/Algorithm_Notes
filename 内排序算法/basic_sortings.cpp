//create on 20191104;update on 20210129
// ������������㷨����������ð������ѡ������
#include<iostream>
using namespace std;
void swap(int a[],int i,int j){ //������������λ�� 
	int temp;
	temp = a[j];
	a[j] = a[i];
	a[i] = temp;
}
int mini_num(int data[],int s,int n){ //�ҳ�a[s]��a[n]������СԪ���±� 
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
		//ע��һ��a[j]>=a[j-1]�Ͳ��ü����Ƚ��ˣ���Ϊǰ�����ź���� 
			swap(a,j,j-1);	 
		}
		for(int k=0;k<n;k++) cout<<a[k]<<" "; //���ÿһ������Ľ��
		cout<<endl;
	}	
	cout<<"-----The END-----"<<endl;
}
void bubble_sort(int a[],int n){
	cout<<"----Bubble sort----"<<endl;
	for(int i=0;i<n-1;i++){ //���ѭ����ִ��n������
		for(int j=0;j<n-1;j++){ //�ڲ�ѭ����ÿ����֮����Ƚ�
			if(a[j]>a[j+1]) {
				swap(a,j,j+1);	
			}	
		}
		for(int k=0;k<n;k++) cout<<a[k]<<" "; //���ÿһ������Ľ��
		cout<<endl;
	}	
	cout<<"-----The END-----"<<endl;
}
void selection_sort(int a[],int n){
	cout<<"----Selection sort----"<<endl;
	for(int i=0;i<n;i++){  
		swap(a,i,mini_num(a,i,n)); //��������������С��ͬ���������е�һ��Ԫ�ؽ��� 
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


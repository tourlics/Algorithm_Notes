#include<iostream>
#include<algorithm>

using namespace std;
int a[10]={1,5,3,8,5,9,4,0,2};//��������9��Ԫ�� 
bool cmp(int a,int b){ //���� 
	return a > b;
} 
int main(){
	for(int i=0;i<9;i++) cout<<a[i];
	cout<<endl; 
	sort(a,a+9,cmp);//�������������(cmp1Ϊ����) 
	for(int i=0;i<9;i++) cout<<a[i];
	cout<<endl; 
	sort(a,a+8);//������ǰ8��Ԫ�ؽ�������Ĭ��Ϊ���� 
	for(int i=0;i<9;i++) cout<<a[i];
	cout<<endl;
	sort(a,a+9);//����������������� 
	for(int i=0;i<9;i++) cout<<a[i];
	cout<<endl;
	sort(a,a+9,greater<int>());//����������������򣨽��� 
	for(int i=0;i<9;i++) cout<<a[i];
	cout<<endl;
	
	return 0;
}

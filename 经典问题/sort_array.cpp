#include<iostream>
#include<algorithm>

using namespace std;
int a[10]={1,5,3,8,5,9,4,0,2};//该数组有9个元素 
bool cmp(int a,int b){ //降序 
	return a > b;
} 
int main(){
	for(int i=0;i<9;i++) cout<<a[i];
	cout<<endl; 
	sort(a,a+9,cmp);//对数组进行排序(cmp1为降序) 
	for(int i=0;i<9;i++) cout<<a[i];
	cout<<endl; 
	sort(a,a+8);//对数组前8个元素进行排序（默认为升序） 
	for(int i=0;i<9;i++) cout<<a[i];
	cout<<endl;
	sort(a,a+9);//对整个数组进行排序 
	for(int i=0;i<9;i++) cout<<a[i];
	cout<<endl;
	sort(a,a+9,greater<int>());//对整个数组进行排序（降序） 
	for(int i=0;i<9;i++) cout<<a[i];
	cout<<endl;
	
	return 0;
}

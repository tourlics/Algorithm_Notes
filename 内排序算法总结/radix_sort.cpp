//create on 20191201
#include<iostream>
#include<math.h>
using namespace std;
int n;
int getmax(int a[]){
	int max = 0;
	for(int i =0;i<n;i++){
		int b = 1;
		while(a[i]/(int)pow(10,b)!=0) b++;
		if(b>max) max = b;
	}
	return max;
}
void swap(int a[],int i,int j){ //交换两个数的位置 
	int temp;
	temp = a[j];
	a[j] = a[i];
	a[i] = temp;
}
int getbit(int x,int b){
	return x % (int)pow(10,b) / (int)pow(10,b-1);
}
void inssort2(int a[],int b){ //注意一定要是稳定排序
	for(int i=1;i<n;i++){  
		for(int j=i;j>0&&(getbit(a[j],b)<getbit(a[j-1],b));j--){ 
			swap(a,j,j-1);	 
		}
	}	
}

void radixsort(int a[]){
	int bits = getmax(a);
	for(int i =1;i<=bits;i++){
		inssort2(a,i);
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}

int main(){
	int a[20];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	radixsort(a);
	return 0;
}

/*----Test-----
15
2 43 543 23 54 654 65 34 6544 65 3 9 79 465 236
*/

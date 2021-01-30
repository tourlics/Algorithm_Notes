//create on 20191227
#include<iostream>
using namespace std;
int arr[100] = {2,4,6,9,10,16,19,23,36,43,54,65,89,103,185};//sorted
int n=15;

int bin(int c){ //return the index of the array 
	int l = 0;
	int r = n-1;
	int mid;
	while(l<=r){
		mid = (l+r)/2;
		if(c < arr[mid]) r = mid-1; //注意取左区间时是-1
		else if(c > arr[mid]) l = mid+1;
		else return mid;
	}
	return -1;
}

int main(){
	cout<<bin(2)<<endl;
	cout<<bin(15)<<endl;
	cout<<bin(185)<<endl;
	return 0;
}


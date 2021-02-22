//create on 20200123
#include<iostream>
using namespace std;
int arr[100];

void swap(int* swarr,int a,int b){
	int temp = swarr[a];
	swarr[a] = swarr[b];
	swarr[b] = temp;
}
void insert_sort(int* sarr,int n){
	for(int i=1;i<n;i++){  
		for(int j=i;j>0&&(sarr[j]<sarr[j-1]);j--){
			swap(sarr,j,j-1);	 
		}
	}
}
int midOfmid(int *midarr,int left,int right){
	int tarr[10];
	int k = 0;
	for(int i=left;i<=right;i++) tarr[k++] = midarr[i];
	insert_sort(tarr,k);
	return tarr[k/2];
}
int findpivot(int left,int right){
	int findarr[20];
	int m = 0;
	if(right - left < 4) findarr[m++] = midOfmid(arr,left,right);
	else {
		for(int i = left;i<=right;i+=5)
		findarr[m++] = midOfmid(arr,i,i+4);
	}
	return midOfmid(findarr,0,m-1);
}
int lookindex(int d){ //寻找pivot的下标，pivot的重复虽然对下标有影响，但对划分无影响 
	for(int i=0;i<100;i++)
		if(arr[i]==d)
			return i;
}
int quickselect(int left,int right,int k){
	int pivot = findpivot(left,right);
	int index = lookindex(pivot);
	//cout<<index<<" "<<pivot<<endl;
	swap(arr,index,right);
	int lp = left;
	int rp = right;
	while(lp < rp){
		while((lp < rp) && (arr[lp] <= pivot)) lp++;
		while((lp < rp) && (arr[rp] >= pivot)) rp--;
		swap(arr,lp,rp);
	}
	swap(arr,right,lp);
	index = lp;
	if(k == index + 1) return arr[index];
	if(k < index + 1) return quickselect(left,index-1,k);
	if(k > index + 1) return quickselect(index+1,right,k);
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<quickselect(0,n-1,n/2)<<endl;
	return 0;
}

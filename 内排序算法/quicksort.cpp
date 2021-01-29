//write on 20200123
//update on 20210129
//本写法参考了英文教材；区别于《啊哈算法》中的写法，这种写法本质上选取
//最右侧元素为pivot（因为无论怎么选取pivot，都要和最右侧元素进行交换，因此扫描顺序是先左后右
#include<iostream>
#include<cmath>
using namespace std;
int arr[100];

int findpivot(int left,int right){ //寻找pivot
	return ceil((left+right)/2); //去数组中间值为pivot；当然，也可以选择最左侧元素为pivot（选法不唯一）
}
void swap(int a,int b){ //交换数组中下标为a,b两个数
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void quicksort(int left,int right){ //left为要进行快速排序的序列的左端点
	if(left >= right) return ;
	int index = findpivot(left,right);
	int pivot = arr[index]; //寻找pivot的值
	swap(index,right);
	int lp = left;
	int rp = right;
	while(lp < rp){ //lp为左侧指针；rp为右侧指针
		while((lp < rp) && (arr[lp] <= pivot)) lp++; //左侧指针从左往右扫描，找到第一个比pivot大的元素
		while((lp < rp) && (arr[rp] >= pivot)) rp--; //右侧指针从右往左扫描，找到第一个比pivot小的元素
		swap(lp,rp); //交换左右指针所指的元素
	}
	index = lp; //lp==rp将原序列分解为两个子序列，左侧子序列都是比pivot小的元素，右侧子序列都是比pivot大的元素
	swap(right,index);
	quicksort(left,brkp-1); //对左侧子序列进行快速排序
	quicksort(brkp+1,right); //对右侧子序列进行快速排序
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	quicksort(0,n-1);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	
	return 0;
}
/*
10
25 93 42 51 89 68 6 14 30 77
*/

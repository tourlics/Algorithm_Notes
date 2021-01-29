//write on 20190722
//参考《啊哈算法》，注意这种写法只能选取最左侧元素为基准数，因此指针扫描的顺序是先右后左
//快速排序（从小到大），平均时间复杂度nlgn 
//如要从大到小排序，倒序输出即可 
#include<stdio.h>
int a[101];
void quicksort(int left,int right){
	int i,j,temp;
	if(left>right) return ; 
	
	temp = a[left];//temp是基准数，选取数列中最左侧的数为基准数 
	i = left;//i负责从左往右搜索比基准数大的数 
	j = right;//j负责从右往左搜索比基准数小的数 
	while(i != j){
		while(i < j && a[j] >= temp) j--;//注意顺序，先从右往左搜索 
		while(i < j && a[i] <= temp) i++;
		if(i < j){//交换两数的位置 
			int t;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//结束循环后，i==j 
	a[left] = a[i];
	a[i] = temp;
	//上述两步交换了基准数的位置 
	
	quicksort(left,i-1);//递归对i左侧的数进行同样操作 
	quicksort(i+1,right);//递归对i右侧的数进行同样操作 
	
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){ 
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);//从a[0]到a[n-1]排序 
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}

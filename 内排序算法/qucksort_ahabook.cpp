//write on 20190722
//�ο��������㷨����ע������д��ֻ��ѡȡ�����Ԫ��Ϊ��׼�������ָ��ɨ���˳�������Һ���
//�������򣨴�С���󣩣�ƽ��ʱ�临�Ӷ�nlgn 
//��Ҫ�Ӵ�С���򣬵���������� 
#include<stdio.h>
int a[101];
void quicksort(int left,int right){
	int i,j,temp;
	if(left>right) return ; 
	
	temp = a[left];//temp�ǻ�׼����ѡȡ��������������Ϊ��׼�� 
	i = left;//i����������������Ȼ�׼������� 
	j = right;//j����������������Ȼ�׼��С���� 
	while(i != j){
		while(i < j && a[j] >= temp) j--;//ע��˳���ȴ����������� 
		while(i < j && a[i] <= temp) i++;
		if(i < j){//����������λ�� 
			int t;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//����ѭ����i==j 
	a[left] = a[i];
	a[i] = temp;
	//�������������˻�׼����λ�� 
	
	quicksort(left,i-1);//�ݹ��i����������ͬ������ 
	quicksort(i+1,right);//�ݹ��i�Ҳ��������ͬ������ 
	
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){ 
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);//��a[0]��a[n-1]���� 
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}

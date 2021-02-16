#include<stdio.h>
#define inf 9999999

int main(){
	int e[10][10],k,n,m,t1,t2,t3;
	scanf("%d %d",&n,&m);
	//�����ʼ�� 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=inf;
		}
	}
	//�����
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&t1.&t2,&t3);
		e[t1][t2]=t3;
	}
	
	//Floyd�㷨
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(e[i][j]>e[i][k]+e[k][j]) {
					e[i][j]=e[i][k]+e[k][j]
				}
			}
		}
	} 
	//���
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%10d",e[i][j]);
		}
		printf("\n");
	} 
	
	return 0;
}

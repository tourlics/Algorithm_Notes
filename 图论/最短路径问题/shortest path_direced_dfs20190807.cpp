#include<stdio.h>
#define inf 9999999
using namespace std;
int min = inf;
int book[2510],e[2510][2510],n,start,end;
void dfs(int cur,int dis){
	int j;
	if(dis>min) {
		return;	
	}
	if(cur==end){
		if(dis<min){
			min = dis;		 
		} 
		return ;
	}
	for(j=1;j<=n;j++){
		if(e[cur][j]!=inf && book[j]==0){
			book[j]=1;
			dfs(j,dis+e[cur][j]);
			book[j]=0;//一条路径全部走完才book[j]=0; 
		}
	}
	return ;
}

int main(){
	int i,j,m,a,b,c;
	scanf("%d %d %d %d",&n,&m,&start,&end);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=inf;
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		e[a][b]=c;
		e[b][a]=c;
	}
	book[start]=1;
	dfs(start,0);
	printf("%d\n",min);
	return 0;
}
/*------Test-------
7 12 1 4
1 2 12
2 3 10
3 4 3
4 5 4
3 5 5
5 6 2
3 6 6
2 6 7
1 6 16
6 7 9
5 7 8
1 7 14
//
6 9 
1 2 4
1 3 2
2 3 3
2 4 5
3 4 8
3 5 10
4 5 2
5 6 3
4 6 6
//5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/ 

//create on 20191206
//MST prim算法
//不用使用并查集判断是否有回路，因为加入的最小边关联的结点不能都在已选结点集合中
#include<iostream>
#define inf 999999
using namespace std;
int book[310],e[301][310],n,count;
int maxm = -inf;
int Prim(int cur){
	book[cur] = 1;
	count++;
	int minn = inf;
	int index;
	int node;
	for(int j=1;j<=n;j++){
		if(book[j]==1){
			for(int i=1;i<=n;i++){
				if(book[i]==0 && e[j][i]<minn) {
					minn = e[j][i];
					node = j;
					index = i;//find the smallest distance of two vertices
				}
			}
		}
		
	}
	if(e[node][index]>maxm) maxm = e[node][index];
	return index;
}
int main(){
	int i,j,m,a,b,c;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=inf;
		}
	}
	for(i=1;i<=m;i++){
		cin>>a>>b>>c;
		e[a][b]=c;
		e[b][a]=c;//undirected graph
	}
	int next = Prim(1);
	while(count!=n-1){ //count used to judge if all vertices are in the tree
		next = Prim(next);
	}
	cout<<count<<" "<<maxm<<endl;
	return 0;
}
/*----------Test-------
6 8 3
1 3 7
2 3 5
3 4 1
1 5 9
5 6 1
2 6 6
3 6 2
4 6 2
//homework
6 9 3
1 2 10
2 4 5
1 6 2
2 3 3
4 5 11
6 5 3
3 5 15
4 6 10
1 4 20
*/


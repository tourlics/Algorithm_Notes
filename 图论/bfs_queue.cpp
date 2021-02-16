//create on 20191204
//based on queue, view the notes for pseuodo code
#include<iostream>
#include<queue>
#define inf 999999
using namespace std;

int main(){
	int n,m,a,b,cur,book[101]={0},e[101][101],start;
	queue<int> q;
	cin>>n>>m>>start;//n vertices, m edges,start from vertxt start
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		e[a][b]=1;
		e[b][a]=1;
	}
	cur = start;//start from vertex cur
	q.push(cur);
	book[cur]=1;
	while(!q.empty()){
		cur = q.front();
		cout<<cur<<" ";
		q.pop();
		for(int i=1;i<=n;i++){
			if(e[cur][i]==1&&book[i]==0){
				q.push(i);
				book[i]=1;
			}
		}	
	}
	
	return 0;
}
/*--------Test-------
9 11 2
1 2
1 3
2 4
2 5
3 6
7 8
6 8
1 5
5 7
3 8
8 9
*/


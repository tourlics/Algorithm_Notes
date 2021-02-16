//20191204
#include<iostream>
#include<stack>
#define inf 999999
//此题和递归思想高度契合，因此用递归代码更简洁。为加深理解，此处用栈实现 
using namespace std;
int n,m,a,b,cur,book[101],e[101][101];
stack<int> s;
void dfs(int cur){
	if(!book[cur]) cout<<cur<<" ";
	book[cur]=1;
	for(int i=1;i<=n;i++){
		if(e[cur][i]==1&&book[i]==0){
			s.push(i);
			break;
		}
		if(i==n&!(e[cur][i]==1&&book[i]==0)) s.pop();
		//当这个结点去dfs却没有向stack里面添加新元素时，则把这个结点pop 
	}
}

int main(){
	cin>>n>>m;//n vertices, m edges
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
	
	cur = 2;//start from vertex 2
	s.push(cur);

	while(!s.empty()){
		cur = s.top();
		dfs(cur);
	}
	return 0;
}
/*--------Test-------
//dfs1
9 9
1 2
1 3
2 4
2 5
3 6
5 7
3 8
8 9
5 8
//dfs2
9 8
1 2
1 3
2 4
2 5
3 6
5 7
3 8
8 9
*/

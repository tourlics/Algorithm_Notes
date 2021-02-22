//create on 20200131
//洛谷[HAOI2006]受欢迎的牛
#include<iostream>
#include<algorithm> // min
#include<stack>
using namespace std;
int dfn[10010],low[10010],deep,ans,color,col[10010];
bool book[10010]; //i is in stack == true
stack<int> s;
bool e[10010][10010];
int n;
typedef struct{
	int weight;
	int outdegree;
}Node;
Node node[10010];
void tarjan(int v){
	dfn[v] = ++deep;
	low[v] = deep;
	book[v] = true;
	s.push(v);
	for(int i=1;i<=n;i++){
		if(e[v][i] == 0) continue;
		if(dfn[i] == 0) {
			tarjan(i);
			low[v] = min(low[i],low[v]); //回溯时更新low[ ]，取最小值
		}
		else if(dfn[i] != 0 && book[i] == true){ //i is not dfs-ed && is in stack
			low[v] = min(low[v],low[i]);
		} 
	}
	if(dfn[v] == low[v]){
		color++;
		int cur;
		do{
			cur = s.top();
			book[cur] = false;
			s.pop();
			col[cur] = color;
		}while(cur != v);	
	}	
}
int main(){
	int m;
	cin>>n>>m;

	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		e[a][b] = 1; //directed
	}
	for(int i=1;i<=n;i++)
		if(dfn[i]==0)
			tarjan(i);
	for(int i=1;i<=color;i++)
		for(int j=1;j<=n;j++){
			if(col[j]==i){ //缩点 
				node[i].weight++;
				for(int m=1;m<=n;m++){
					if(col[m]!=i && e[j][m]==1) 
						node[i].outdegree++;
				}
			}
		}
	int count = 0;
	for(int i=1;i<=color;i++){
		if(node[i].outdegree==0) {
			ans = node[i].weight;
			count++;
		}
	}
	if(count == 1) cout<<ans;
	else cout<<0;
	return 0;
} 
/*---Test------
//4
6 8
1 2
1 3
4 1
5 3
5 6
6 4
2 4
3 4
//1
6 8
1 2
1 3
4 1
3 5
5 6
4 6
2 4
3 4
*/

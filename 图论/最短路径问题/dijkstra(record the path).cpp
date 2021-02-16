//20200206
//Dijkstra adjacent list(vector) + record the path
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> //fill 
using namespace std;
const int inf = 0x3fffffff;
const int MAXN = 2510;
bool book[MAXN]; 
int n,start,term;
int data[MAXN]; //stores the shortest distance of every vertex
int pre[MAXN]; //记录前驱结点 
struct Edge{
	int v; //v为该边的另外一个顶点
	int weight; //该边的边权 
};
vector<Edge> adj[MAXN]; //adj[i]存放从顶点i出发所有能到达的点 ；相当于二维数组 
int countk;
int seekmin(){ //seek the min in data[];
	int minn = inf;
	int index;
	for(int i=1;i<=n;i++){
		if(book[i]==0 && data[i]<minn){ 
		//make sure not compare with the vertex booked
			minn = data[i];
			index = i;
		}
	}
	return index;
}
void Dijkstra(int cur,int dis){
	book[cur] = 1;
	countk++;
	for(int i=0;i<adj[cur].size();i++){
		Edge e = adj[cur][i];
		if(book[e.v]==0 && e.weight+dis<data[e.v]){//make sure not compare with the vertex booked
			data[e.v] = e.weight + dis;
			pre[e.v] = cur;
		} 	
	}
}
void dfs(int v){ //不能用while代替，因为顺序不对 
	if(v == start){
		printf("%d->",v);
		return ;
	}
	else {
		dfs(pre[v]);
		printf("%d->",v);
	}
}

int main(){
	int i,j,m,a,b,c;
	scanf("%d %d %d %d",&n,&m,&start,&term);
	fill(data,data + MAXN,inf);
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		Edge e1;
		e1.v = b;
		e1.weight = c;
		adj[a].push_back(e1); 
		Edge e2;
		e2.v = a;
		e2.weight = c;
		adj[b].push_back(e2); 
	}
	Dijkstra(start,0);
	while(countk<n){
		int next = seekmin();
		int distance = data[next];
		Dijkstra(next,distance);
	}
	dfs(pre[term]);
	printf("%d\n",term);
	printf("%d\n",data[term]);	
	return 0;
}
/*---Test---- 
7 11 5 4
2 4 2
1 4 3
7 2 2
3 4 3
5 7 5
7 3 3
6 1 1
6 3 4
2 4 3
5 6 3
7 2 1
*/

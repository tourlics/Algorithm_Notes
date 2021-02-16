//20200206
//PAT A1030 Travel Plan
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> //fill 
#include<stack>
using namespace std;
const int inf = 0x3fffffff;
const int MAXN = 510;
bool book[MAXN]; 
int n,start,term;
int data[MAXN]; //stores the shortest distance of every vertex
int num[MAXN]; //record the num of shortest path 
int cost[MAXN][MAXN];
struct Edge{
	int cur;
	int v; //v为该边的另外一个顶点
	int weight; //该边的边权 
//	int cost; //该边的花费 
};
vector<Edge> adj[MAXN]; //adj[i]存放从顶点i出发所有能到达的点 ；相当于二维数组 
vector<int> pre[MAXN]; 
int countk;
int seekmin(){ //seek the min in data[];
	int minn = inf;
	int index;
	for(int i=0;i<n;i++){
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
		if(book[e.v]==0 && e.weight+dis<data[e.v]){
			data[e.v] = e.weight + dis;
			num[e.v] = num[cur]; //如果小于，就继承 
			pre[e.v].clear();
			pre[e.v].push_back(cur);
		}
		else if(book[e.v]==0 && e.weight+dis==data[e.v]){// 如果等于，就加上 
			num[e.v] += num[cur];
			pre[e.v].push_back(cur);
		}
		
	}
}
stack<int> s,temppath,finalpath;
int mincost = inf;
int sum = 0;
void dfs(int v){
	if(v == start){
		sum = 0;
		while(!temppath.empty()) temppath.pop();
		int t = s.top();
		sum += cost[v][t];
		temppath.push(v);
		while(s.size() > 1){
			int temp = s.top();
			temppath.push(s.top());
			s.pop();
			sum += cost[temp][s.top()];	
		}
		temppath.push(s.top());
		s.pop();
		if(sum < mincost){
			while(!finalpath.empty()) finalpath.pop();
			mincost = sum;
			while(!temppath.empty()){
				finalpath.push(temppath.top());
				temppath.pop();
			}
		}
		return ;	
	}else{
		for(int i=0;i<pre[v].size();i++){
			s.push(v);
			dfs(pre[v][i]);
		}
	}
}
void show(){
	while(!finalpath.empty()){
		printf("%d ",finalpath.top());
		finalpath.pop();
	}
	printf("%d %d",data[term],mincost);
}
int main(){
	int i,j,m,a,b,c,d;
	scanf("%d %d %d %d",&n,&m,&start,&term);
	fill(data,data + MAXN,inf);
	for(i=0;i<m;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		Edge e1;
		e1.v = b;
		e1.weight = c;
		adj[a].push_back(e1); 
		Edge e2;
		e2.v = a;
		e2.weight = c;
		adj[b].push_back(e2);
		cost[a][b] = cost[b][a] = d; 
	}
	num[start] = 1;
	Dijkstra(start,0);
	while(countk<n){
		int next = seekmin();
		int distance = data[next];
		Dijkstra(next,distance);
	}
	dfs(term);
	show();
	return 0;
}


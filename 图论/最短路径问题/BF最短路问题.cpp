//20200210
//BF adjacent list(vector)
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> //fill 
using namespace std;
const int inf = 0x3fffffff;
const int MAXN = 2510;
int n,start,term;
int data[MAXN]; //stores the shortest distance of every vertex
struct Edge{
	int v; //v为该边的另外一个顶点
	int weight; //该边的边权 
};
vector<Edge> adj[MAXN]; //adj[i]存放从顶点i出发所有能到达的点 ；相当于二维数组 
bool BF(){ 
	for(int k=0;k<n-1;k++){ //execute n-1 times
		for(int i=1;i<=n;i++){//traverse all the edges
			for(int j=0;j<adj[i].size();j++){
				int v = adj[i][j].v;
				int weight = adj[i][j].weight;
				if(data[i]+weight < data[v]) data[v] = data[i] + weight;
			}
		}
	}
	bool state = 1; //判断是否存在从源点可达的负环 
	for(int i=1;i<=n;i++){//traverse all the edges
		for(int j=0;j<adj[i].size();j++){
			int v = adj[i][j].v;
			int weight = adj[i][j].weight;
			if(data[i]+weight < data[v]){
				state = 0;
				data[v] = data[i] + weight;
			}
		}
	}
	return state;
} 

int main(){
	int i,j,m,a,b,c;
	scanf("%d %d %d %d",&n,&m,&start,&term);
	fill(data,data + MAXN,inf);
	data[start] = 0; //源点 
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
	if(BF()) printf("%d\n",data[term]);	
	else printf("None\n");
	return 0;
}


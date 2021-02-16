//20200210
//BF(queue optimised) adjacent list(vector)
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
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
int countk;
queue<int> q;
bool inq[MAXN];
int num[MAXN]; //判断是否有可达负环 
bool SPFA(){ 
	while(!q.empty()){
		int i = q.front();
		q.pop();
		inq[i] = false;
		for(int j=0;j<adj[i].size();j++){
			int v = adj[i][j].v;
			int weight = adj[i][j].weight;
			if(data[i]+weight < data[v]){
				data[v] = data[i] + weight;
				if(!inq[v]){
					q.push(v);
					inq[v] = true;
					num[v]++;
					if(num[v] > n) return false;
				}
			}
		}	
	}
	return true;
} 

int main(){
	int i,j,m,a,b,c;
	scanf("%d %d %d %d",&n,&m,&start,&term);
	fill(data,data + MAXN,inf);
	data[start] = 0; //源点 
	q.push(start);
	inq[start] = true;
	num[start]++;
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
	if(SPFA()) printf("%d\n",data[term]);	
	else printf("None\n");
	return 0;
}


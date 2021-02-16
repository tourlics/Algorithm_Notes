//20200206
// PAT A1003 Emergency
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> //fill 
using namespace std;
const int inf = 0x3fffffff;
const int MAXN = 510;
bool book[MAXN]; 
int n,start,term;
int data[MAXN]; //stores the shortest distance of every vertex
int num[MAXN]; //record the num of shortest path 
int weig[MAXN];
int w[MAXN]; //record the num of shortest path 
struct Edge{
	int v; //v为该边的另外一个顶点
	int weight; //该边的边权 
};
vector<Edge> adj[MAXN]; //adj[i]存放从顶点i出发所有能到达的点 ；相当于二维数组 
int countk;
int seekmin(){ //seek the min in data[];
	int minn = inf;
	int index;
	for(int i=0;i<n;i++){ //notice that the min vertex is 0 in this problem
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
			num[e.v] = num[cur];
			w[e.v] = w[cur] + weig[e.v]; 
		}
		else if(book[e.v]==0 && e.weight+dis==data[e.v]){
			num[e.v] += num[cur];
			if(w[cur] + weig[e.v] > w[e.v])
				w[e.v] = w[cur] + weig[e.v]; 
		} 
	}
}

int main(){
	int i,j,m,a,b,c;
	scanf("%d %d %d %d",&n,&m,&start,&term);
	fill(data,data + MAXN,inf);
	for(int i=0;i<n;i++) //notice that the min vertex is 0 in this problem
		scanf("%d",&weig[i]);
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
	w[start] = weig[start];
	num[start] = 1;
	Dijkstra(start,0);
	while(countk<n){
		int next = seekmin();
		int distance = data[next];
		Dijkstra(next,distance);
	}
	printf("%d %d\n",num[term],w[term]);	
	return 0;
}


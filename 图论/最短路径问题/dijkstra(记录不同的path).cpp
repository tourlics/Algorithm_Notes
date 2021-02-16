//20200206
//Dijkstra adjacent list(vector)
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> //fill 
#include<stack>
using namespace std;
const int inf = 0x3fffffff;
const int MAXN = 2510;
bool book[MAXN]; 
int n,start,term;
int data[MAXN]; //stores the shortest distance of every vertex
int num[MAXN]; //record the num of shortest path 
struct Edge{
	int v; //vΪ�ñߵ�����һ������
	int weight; //�ñߵı�Ȩ 
};
vector<Edge> adj[MAXN]; //adj[i]��ŴӶ���i���������ܵ���ĵ� ���൱�ڶ�ά���� 
vector<int> pre[MAXN]; 
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
		if(book[e.v]==0 && e.weight+dis<data[e.v]){
			data[e.v] = e.weight + dis;
			num[e.v] = num[cur]; //���С�ڣ��ͼ̳� 
			pre[e.v].clear();
			pre[e.v].push_back(cur);
		}
		else if(book[e.v]==0 && e.weight+dis==data[e.v]){// ������ڣ��ͼ��� 
			num[e.v] += num[cur];
			pre[e.v].push_back(cur);
		}
		
	}
}
stack<int> s;
void dfs(int v){
	if(v == start){
		printf("%d->",v);
		while(s.size() > 1){
			printf("%d->",s.top());
			s.pop();
		}
		printf("%d\n",s.top());
		s.pop();
		return ;	
	}else{
		for(int i=0;i<pre[v].size();i++){
			s.push(v);
			dfs(pre[v][i]);
		}
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
	num[start] = 1;
	Dijkstra(start,0);
	while(countk<n){
		int next = seekmin();
		int distance = data[next];
		Dijkstra(next,distance);
	}
	printf("shortest distance = %d\nnum = %d\n",data[term],num[term]);
	dfs(term);	
	return 0;
}
/*---Test----
8 11 1 8
1 2 3
1 3 3
1 4 3
4 5 1
4 6 1
4 7 1
5 8 2
6 8 2
7 8 2
3 8 3
2 8 3
*/

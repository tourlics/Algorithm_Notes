//create on 20210216
//最小生成树Kruskal算法；邻接表存储图
//牛客网-还是畅通工程
#include<iostream>
#include<algorithm>
#define maxn 102
using namespace std;
int edge;
struct Adj{
	int a,b;
	int weight;
}adj[6000];
bool cmp(Adj e1,Adj e2){
    return e1.weight < e2.weight;
}
int father[maxn];
int findfather(int node){
	int vertex = node;
	while(node != father[node]) //node == father[node]到了根节点
		node = father[node];
	int root = node; //root为根节点
	while(vertex != father[vertex]){// path compression
		int temp = vertex;
		vertex = father[vertex]; //找根节点过程中所遍历到的结点（即父节点的父节点...）
		father[temp] = root;
	}
	return root;
}
void unionsets(int node1,int node2){
	int fa1 = findfather(node1);
	int fa2 = findfather(node2);
	father[fa2] = fa1;
}
bool cycle(int nodea,int nodeb){
	if(findfather(nodea) == findfather(nodeb)) return false;
	else {
		unionsets(nodea,nodeb);
		edge++;// end condition
		return true;
	}
}
int Kruskal(int i){
	int nodea = adj[i].a;
    int nodeb = adj[i].b;
    int weight=0;
	if(cycle(nodea,nodeb)){ //如果不构成环
		weight = adj[i].weight;
	}
    return weight; //不构成环则返回最小的边；构成环则返回0
}

int main(){
	int n;
    while(scanf("%d",&n)!=EOF && n!=0){
        edge = 0;
        for(int i=1;i<=n;i++){
            father[i] = i; //initialize
        }
        int a,b,c;
        int m = n*(n-1)/2;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            adj[i].a = a;
            adj[i].b = b;
            adj[i].weight = c;
        }
        sort(adj,adj+m,cmp);
        int cnt = 0;
        for(int i=0;edge<n-1;i++){
            cnt += Kruskal(i);
        }
        cout<<cnt<<endl;
    }
	
	return 0;
}

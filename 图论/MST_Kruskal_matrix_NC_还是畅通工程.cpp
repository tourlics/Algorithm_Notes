//create on 20200130
//update on 20210216
//最小生成树Kruskal算法；邻接矩阵存储图
//牛客网-还是畅通工程
#include<iostream>
#define maxn 102
#define inf 9999999 
using namespace std;
int edge;
int e[maxn][maxn],father[maxn];
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
int Kruskal(int n){
	int minn = inf;
	int nodea,nodeb;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(e[i][j] < minn) {
				minn = e[i][j];
				nodea = i;
				nodeb = j;
			}
		}
	} //找到权重最小的边
    int weight=0;
	if(cycle(nodea,nodeb)){ //如果不构成环
		weight = e[nodea][nodeb];
	}
	e[nodea][nodeb] = inf;
	e[nodeb][nodea] = inf;//ignore the edge checked
    return weight; //不构成环则返回最小的边；构成环则返回0
}

int main(){
	int n;
    while(scanf("%d",&n)!=EOF && n!=0){
        edge = 0;
        for(int i=1;i<=n;i++){
            father[i] = i; //initialize
            for(int j=1;j<=n;j++){
                e[i][j]=inf;
            }
        }
        int a,b,c;
        int m = n*(n-1)/2;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            e[a][b]=c;
            e[b][a]=c;//indirected
        }
        int cnt = 0;
        while(edge<n-1){
            cnt += Kruskal(n);
        }
        cout<<cnt<<endl;
    }
	
	return 0;
}

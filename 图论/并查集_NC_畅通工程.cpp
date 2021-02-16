//20210216
//牛客网-畅通工程
//并查集
#include<iostream>
#define maxn 1010
using namespace std;
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
	if(fa1!=fa2) father[fa2] = fa1;
}
int countsets(int n){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(father[i]==i) cnt++; //统计有多少个根节点，就有多少课树
    }
    return cnt;
}
int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF && n!=0){
        scanf("%d",&m);
        for(int i=1;i<=n;i++) father[i] = i;
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            unionsets(a,b);
        }
        cout<<countsets(n)-1<<endl;
    }
    return 0;
}
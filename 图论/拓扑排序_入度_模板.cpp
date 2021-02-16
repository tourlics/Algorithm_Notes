//create on 20210216
//拓扑排序；判断图中是否有环
//基于判断结点入度
//邻接表存储；模板
#include<iostream>
#include<vector>
#include<queue>
#define maxn 501
using namespace std;
vector<int> edge[maxn]; //存储每个结点的下一个结点（有向图），忽略权重
queue<int> q; //保存入度为0的结点
int indegree[maxn]; //存储每个结点的入度
int main(){
    int n,m; //n为结点个数；m为边的个数
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        indegree[b]++;
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i); //所有入度为0的结点进入队列
            cnt++; //统计每个如果队列的结点个数
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0;i<edge[node].size();i++){
            indegree[ edge[node][i] ]--;
            if(indegree[ edge[node][i] ]==0){
                q.push(edge[node][i]);
                cnt++;
            }
        }
    }
    if(cnt == n) cout<<"NO LOOP"<<endl;
    else cout<<"LOOP EXISTS"<<endl;
    return 0;
}
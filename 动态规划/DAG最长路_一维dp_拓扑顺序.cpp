//create on 20210221
//DAG最长路（有固定终点T）-模板
//动态规划
//使用邻接表存储图
//dp[i]表示以点i为终点的最长路径，
//然后从出度为0的点开始，按拓扑顺序依次求出
//dp[i] = max{dp[j]+length(i,j)} 
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int maxn = 1001;
struct Node{
    int nodeb;
    int weight;
};
vector<Node> v[maxn];
int dp[maxn]; //初始化为0，dp[i]表示以点i出发的最长路径
int indegree[maxn]; //存储每个结点的入度，注意不能存在Node结构体中
int path[maxn]; //记录最长路径，path[i]表示以点i出发的最长路径的前一个结点为path[i]
int toporder[maxn]; //将结点按拓扑顺序排序后的结果
void topsort(int n){ //n为结点总个数
    queue<int> q; //保存入度为0的结点
    for(int i=0;i<n;i++){ //将入度为0的结点全部如队列
        if(indegree[i]==0)
            q.push(i);
    }
    int k = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        toporder[k++] = cur;
        for(int i=0;i<v[cur].size();i++){
            indegree[ v[cur][i].nodeb ]--; //删边，入度-1
            if(indegree[ v[cur][i].nodeb ]==0)
                q.push(v[cur][i].nodeb);
        }
    }
}
int main(){
    int n,m,T;//结点个数，边数，终点T
    cin>>n>>m>>T;
    for(int i = 0;i<m;i++){ //读入图
        int a,b,c;//结点ab与边权
        cin>>a>>b>>c;
        Node temp;
        temp.nodeb = b;
        temp.weight = c;
        v[a].push_back(temp);
        indegree[b]++;
    }
    for(int i=0;i<m;i++) path[i] = -1; //path初始化为-1
    topsort(n);
    for(int i=0;i<n;i++){
        int cur = toporder[i];
        for(int j=0;j<v[cur].size();j++){
            int temp = dp[cur] + v[cur][j].weight;
            if(temp > dp[ v[cur][j].nodeb ]){
                dp[ v[cur][j].nodeb ] = temp;
                path[ v[cur][j].nodeb ] = cur;//先前结点是cur
            }
        }
    }
    cout<<dp[T]<<endl;//路径长度
    //求最长路径
    stack<int> s; //存储路径
    while(T!=-1){
        s.push(T);
        T = path[T];
    }
    cout<<s.top();
    s.pop();
    while(!s.empty()){
        cout<<"->"<<s.top();  
        s.pop();
    }
    return 0;
}
/*
//test1-图片DAG最长路
//0 is S;1=A;2=B;3=C;4=D;5=E;
//T=B=2
6 8 2
0 1 1
0 3 2
3 1 4
3 4 3
1 2 6
2 4 1
2 5 2
4 5 1
//test2-算法笔记P439图
//0 is A;8 is I
//T=H=7
9 12 7
0 2 2
0 3 2
2 5 3
5 7 2
5 8 3
6 7 2
6 8 2
1 4 2
4 6 1
1 3 3
3 5 3
3 6 2
*/
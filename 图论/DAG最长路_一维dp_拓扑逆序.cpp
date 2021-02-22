//create on 20210221
//DAG最长路（无固定终点）-模板
//动态规划
//使用邻接表存储图
//dp[i]表示以点i出发的最长路径，
//然后从出度为0的点开始，按逆拓扑顺序【用递归实现】依次求出
//dp[i] = max{dp[j]+length(i,j)} 
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1001;
struct Node{
    int nodeb;
    int weight;
};
vector<Node> v[maxn];
int dp[maxn]; //初始化为0，dp[i]表示以点i出发的最长路径
int path[maxn]; //记录最长路径，path[i]表示以点i出发的最长路径的下一个结点为path[i]
int dfs(int i){
    if(dp[i]>0) return dp[i]; //结点i已经被访问过，dp[i]已经计算出来了
    for(int j=0;j<v[i].size();j++){
        int temp = dfs(v[i][j].nodeb)+v[i][j].weight;
        if(temp > dp[i]){
            dp[i] = temp; //选择更大的
            path[i] =  v[i][j].nodeb; //记录路径,i的下一个结点为v[i][j].nodeb
        }
        
    }
    return dp[i];
}
int main(){
    int n,m;//结点个数，边数
    cin>>n>>m;
    for(int i = 0;i<m;i++){ //读入图
        int a,b,c;//结点ab与边权
        cin>>a>>b>>c;
        Node temp;
        temp.nodeb = b;
        temp.weight = c;
        v[a].push_back(temp);
    }
    for(int i=0;i<m;i++) path[i] = -1; //path初始化为-1
    for(int i=0;i<n;i++)
        dfs(i); //由于不知道源点，且可能有多个源点，需要对每个结点dfs；
    //不用担心时间复杂度，因为如果该结点之前被访问过，那么dfs就已经求出来了，不会继续递归下去
    int ans = 0; //整个DAG中的最长路径
    int start = 0; //最长路径的起点，输出路径时使用
    for(int i=0;i<n;i++){
        if(dp[i] > ans){
            ans = dp[i];
            start = i;
        }  
    }
    cout<<ans<<endl;
    //求最长路径
    //由于采取的邻接表存储图，所以最长路径的输出按照的是数据输入的顺序，不一定是字母顺序
    cout<<start;
    while(path[start]!=-1){
        start = path[start];
        cout<<"->"<<start;
    }
    return 0;
}
/*
//test1-图片DAG最长路
//0 is S;1=A;2=B;3=C;4=D;5=E
6 8
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
9 12
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
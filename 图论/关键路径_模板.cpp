//create on 20210222
//关键路径
//邻接表存储图
//汇点确定且唯一；如果汇点不确定但唯一，可以找ve[i]最大值得到汇点i
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxv = 101; //最大顶点数
const int maxe = 1010; //最大边数
const int inf = 0x3fffffff;
int ve[maxv]; //事件的最早发生时间
int vl[maxv]; //事件的最迟发生时间
int n,m;//结点个数，边数
struct Node{
    int nodeb;
    int weight;
};
vector<Node> v[maxv];
int dp[maxv]; //初始化为0，dp[i]表示以点i出发的最长路径
int indegree[maxv]; //存储每个结点的入度，注意不能存在Node结构体中
int toporder[maxv]; //将结点按拓扑顺序排序后的结果
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
vector<Node> path[maxv]; //存储关键路径
vector<int> unipath;
void dfs(int start){ //dfs输出路径；start源点；存在问题
    unipath.push_back(start);
    if(start == toporder[n-1] ){ //到汇点了
        int ans = 0;//输出路径的长度
        for(int i=0;i<unipath.size()-1;i++){
            cout<<unipath[i]<<"->";
            for(int j=0;j<v[ unipath[i] ].size();j++){
                if(v[ unipath[i] ][j].nodeb == unipath[i+1]){
                    ans += v[ unipath[i] ][j].weight;
                }
            }
        }
        cout<<unipath[unipath.size()-1]<<"  ";
        cout<<"length="<<ans<<endl;
        return ;
    }
    for(int i=0;i<path[start].size();i++){
        dfs(path[start][i].nodeb);
        unipath.pop_back();
    }
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){ //读入图
        int a,b,c;//结点ab与边权
        cin>>a>>b>>c;
        Node temp;
        temp.nodeb = b;
        temp.weight = c;
        v[a].push_back(temp);
        indegree[b]++;
    }
    topsort(n);
    //求ve，顺拓扑排序方向；可以优化：合并到topsort子程序中
    for(int i=0;i<n;i++){
        int cur = toporder[i];
        for(int j=0;j<v[cur].size();j++){
            int temp = ve[cur] + v[cur][j].weight;
            if(temp > ve[ v[cur][j].nodeb ]){
                ve[ v[cur][j].nodeb ] = temp;
            }
        }
    }
    //求vl，逆拓扑排序方向
    for(int i=0;i<n-1;i++) vl[i] = inf;//初始化为无穷大
    vl[ toporder[n-1] ] = ve[ toporder[n-1] ];//初始化，汇点的最迟开始时间等于最早开始时间
    for(int i=n-2;i>=0;i--){
        int cur = toporder[i];
        for(int j=0;j<v[cur].size();j++){
            int temp = vl[ v[cur][j].nodeb ] - v[cur][j].weight;
            if(temp < vl[cur]){
                vl[cur] = temp;
            }
        }
    }
    //for(int i=0;i<n;i++) cout<<ve[i]<<" "<<vl[i]<<endl;
    //由ve求ee,el；可以不保存，直接判断是否相等，如下：
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            int ee = ve[i]; //活动最早发生时间
            int el = vl[ v[i][j].nodeb ] - v[i][j].weight; //活动最迟发生时间
            if(ee == el){
                //cout<<i<<"->"<<v[i][j].nodeb<<endl;
                path[i].push_back(v[i][j]); //将关键活动加入path
            }
        }
    }
    dfs(0); //源点是0；输出关键路径及其长度
    return 0;
}
/*test
//关键路径（图）
4 5
0 1 4
1 3 6
0 2 3
1 2 2
2 3 4
//
4 5
0 1 4
1 3 6
0 2 6
1 2 2
2 3 4
*/
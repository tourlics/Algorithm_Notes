//create on 20210219
//王道-piggy-bank
//完全背包问题
//一维dp
//dp[j] = max(dp[j],dp[j-data[i].w]+data[i].v)
#include<iostream>
#include<string.h>
#define inf 0x3fffffff
using namespace std;
const int maxn = 10010;
struct Data{
    int w,v; //时间，价值
}data[maxn];
int dp[maxn]; //dp[i][j]表示总体积**恰好**为j时，前i个物品能达到的最大价值
int main(){
    int n;
    cin>>n;
    for(int q=0;q<n;q++){
        int t1,t2; //存储罐重，加了硬币的存储罐重
        cin>>t1>>t2;
        int t,m;
        t = t2-t1;//硬币的重量
        cin>>m; //硬币的种类数
        for(int i=1;i<=m;i++){
            cin>>data[i].v>>data[i].w; //读入顺序：硬币的价值，硬币的重量
        }
        dp[0] = 0;
        for(int i=1;i<=t;i++) dp[i] = inf; //边界：不放任何物品时的价值
        //注意：要求刚好装满背包，dp[0][0]=0;dp[0][i]=inf；
        //因为只有dp[0][0]是有意义的，dp[0][j]没有意义；由于题目要求价值最小，所以是inf
        for(int i=1;i<=m;i++){ //遍历每一个物品
            for(int j=data[i].w;j<=t;j++){ //必须顺序遍历，因为需要的已知值有d[i][]的
                //max函数的前部分：不放第i个物品
                //后部分：放第i个物品，价值变为了如下（注意时间也要增加，由于是逆序，所以应该-）
                dp[j] = min(dp[j],dp[j-data[i].w]+data[i].v); //题目要求价值最小
            }
        }
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=t;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        if(dp[t]<inf)
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[t]<<"."<<endl;
        else cout<<"This is impossible."<<endl;
        memset(dp,0,sizeof(dp));
    }
    
    return 0;
}
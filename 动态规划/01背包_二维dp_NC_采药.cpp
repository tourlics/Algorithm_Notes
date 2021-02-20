//create on 20210219
//牛客网-采药
//0-1背包问题
//二维dp
//dp[i][j]表示总体积（时间）不超过j的情况下，前i个物品所能到达的最大价值
//dp[i][j] = max(dp[i-1][j],dp[i-1][j-data[i].w]+data[i].v)
#include<iostream>
using namespace std;
const int maxn = 101;
struct Data{
    int w,v; //时间，价值
}data[maxn];
int dp[maxn][1001]; //dp[i][j]表示总体积（时间）不超过j的情况下，前i个物品所能到达的最大价值
int main(){
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        cin>>data[i].w>>data[i].v;
    }
    dp[0][0] = 0;
    for(int i=1;i<=t;i++) dp[0][i] = 0; //边界：不放任何物品时的价值
    //注意：如果要求刚好装满背包，则dp[0][0]=0;dp[0][i]=-inf；
    //因为此时dp[i][j]表示总体积**恰好**为j时，前i个物品能达到的最大价值
    //只有dp[0][0]是有意义的，dp[0][j]没有意义
    for(int i=1;i<=m;i++){ //遍历每一个物品
        for(int j=t;j>=data[i].w;j--){ //逆序遍历每一单位时间；也可以顺序遍历，因为需要的已知值都是d[i-1][]的
            //max函数的前部分：不放第i个物品
            //后部分：放第i个物品，价值变为了如下（注意时间也要增加，由于是逆序，所以应该-）
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-data[i].w]+data[i].v);
        }
        for(int j=data[i].w-1;j>=0;j--){ 
            //j-data[i].w<=0，也就是说背包放不下了，也就只能不放该物品了
            dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[m][t]<<endl;
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=t;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
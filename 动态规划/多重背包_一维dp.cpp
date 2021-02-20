//create on 20210219
//王道-珍惜
//多重背包问题
//一维dp
//转化成01背包问题
#include<iostream>
#include<string.h>
#define inf 0x3fffffff
using namespace std;
const int maxn = 10010;
struct Data{
    int w,v,num; //时间，价值，袋数
}data[maxn];
int dp[maxn]; 
int main(){
    int n;
    cin>>n;
    for(int q=0;q<n;q++){
        int t,m;
        cin>>t>>m; //钱，种类数
        for(int i=1;i<=m;i++){
            cin>>data[i].v>>data[i].w>>data[i].num; //读入顺序：硬币的价值，硬币的重量
        }
        dp[0] = 0;
        for(int i=1;i<=t;i++) dp[i] = 0; //边界：不放任何物品时的价值
        for(int i=1;i<=m;i++){ //遍历每一个物品
            for(int j=t;j>=data[i].v;j--){
                for(int k=1;k<=data[i].num;k++){ //区别与01背包问题的地方
                    if(j>=k*data[i].v)
                        dp[j] = max(dp[j],dp[j-k*data[i].v]+k*data[i].w); 
                }
            }
        }
        cout<<dp[t]<<endl;
        memset(dp,0,sizeof(dp));
    }
    
    return 0;
}
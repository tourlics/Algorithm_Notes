//create on 20210219
//0-1背包问题
//一维dp；滚动数组
//因为转移到状态dp[i][j]的两种方式都只与dp[i-1][]有关，所以去掉一维数组
//算法笔记P444
#include<iostream>
using namespace std;
const int maxn = 101;
struct Data{
    int w,v; //时间，价值
}data[maxn];
int dp[1001]; //dp[i][j]表示总体积（时间）不超过j的情况下，前i个物品所能到达的最大价值
int main(){
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        cin>>data[i].w>>data[i].v;
    }
    dp[0] = 0;
    for(int i=1;i<=t;i++) dp[i] = 0; //边界：不放任何物品时的价值
    //注意：如果要求刚好装满背包，则dp[0][0]=0;dp[0][i]=-inf；因为此时dp[i][j]表示总体积恰好为j时，前i个物品能达到的最大价值
    for(int i=1;i<=m;i++){ //遍历每一个物品
        for(int j=t;j>=data[i].w;j--){ //必须逆序遍历
            //因为怕本轮(i)前面得出的值对后面的值（本来是要通过上一轮(i-1)的到）有影响（通过本轮得到）
            //max函数的前部分：不放第i个物品
            //后部分：放第i个物品，价值变为了如下（注意时间也要增加，由于是逆序，所以应该-）
            dp[j] = max(dp[j],dp[j-data[i].w]+data[i].v);
        }
        //去掉讨论j<data[i].w部分，因为这一部分的值和上一轮的相等，没有必要重复赋值
    }
    cout<<dp[t]<<endl;
    return 0;
}
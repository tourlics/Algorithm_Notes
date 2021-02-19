//create on 20210219
//牛客网-拦截导弹
//最长不增子序列（同最长递增子序列）
//dp[i]表示必须以seq[i]结尾的LIS的长度
//dp[i] = dp[j]+1 ; j<i && seq[j]>=seq[i]
#include<iostream>
using namespace std;
int seq[30];
int dp[30]; //dp[i]表示必须以seq[i]结尾的LIS的长度
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>seq[i];
    dp[0] = 1;
    int tmax = 1; //记录最长子序列，避免重现遍历dp
    for(int i=1;i<n;i++){
        dp[i] = 1; //默认不存在seq[j]>=seq[i]，则必须以seq[i]结尾的最长子序列长度为1
        for(int j=0;j<i;j++){
            if(seq[j]>=seq[i] && dp[j]+1>dp[i]){ //j从0-i的遍历过程中会出现dp[j]+1<dp[i]，也就是说以seq[j]结尾加上当前字符构成的长度更小
                dp[i] = dp[j] + 1; //写法2： dp[i] = max(dp[j]+1,dp[i])
            } 
        }
        tmax = max(tmax,dp[i]);
    }
    cout<<tmax;
    return 0;
}
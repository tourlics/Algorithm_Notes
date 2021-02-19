//create on 20210219
//牛客网-合唱队形
//两次最长递增子序列
//dp[i] = dp[j]+1 ; j<i && seq[j]<seq[i]
#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int seq[110];
        int dp[110]; //dp[i]表示必须以seq[i]结尾的LIS的长度，从前往后
        int dp2[110]; //从后往前
        for(int i=0;i<n;i++) cin>>seq[i];
        for(int i=0;i<n;i++){ //从前往后
            dp[i] = 1; //默认不存在seq[j]>=seq[i]，则必须以seq[i]结尾的最长子序列长度为1
            for(int j=0;j<i;j++){
                if(seq[j]<seq[i] && dp[j]+1>dp[i]){
                    dp[i] = dp[j] + 1;
                } 
            }
        }
        for(int i=n-1;i>=0;i--){ //从后往前
            dp2[i] = 1; 
            for(int j=n-1;j>i;j--){
                if(seq[j]<seq[i] && dp2[j]+1>dp2[i]){
                    dp2[i] = dp2[j] + 1;
                } 
            }
        }
        int tmax = 1;
        for(int i=0;i<n;i++){ //找到最大
            if(dp[i]+dp2[i]>tmax) tmax = dp[i]+dp2[i];
        }
        cout<<n-(tmax-1)<<endl;
    }
    return 0;
}
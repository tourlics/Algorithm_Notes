//create on 20210219
//牛客网-最大上升子序列和
//一维dp
//dp[i]记录以seq[i]结尾（必须）的最大上升子序列和
//dp[i] = max{dp[i],dp[j]+seq[i]} j<i&&seq[j]<seq[i] 
#include<iostream>
using namespace std;
int dp[1001];
int seq[1001];
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++) cin>>seq[i];
        for(int i=0;i<n;i++){
            dp[i] = seq[i];
            for(int j=0;j<i;j++)
                if(seq[j]<seq[i])
                    dp[i] = max(dp[i],dp[j]+seq[i]); 
        }
        int tmax = 0;
        for(int i=0;i<n;i++)
            if(dp[i]>tmax) 
                tmax = dp[i];
        cout<<tmax<<endl;
        }
    return 0;
}
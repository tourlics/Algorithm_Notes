//create on 20210219
//牛客-最大序列和
//一维dp 最大子序列和
// dp[i] = max{dp[i-1]+seq[i] , seq[i]}
//dp[i]表示以seq[i]结尾（必须）的最大子序列和
#include<iostream>
using namespace std;
const int maxn = 1000010;
long long seq[maxn];
long long dp[maxn]; //dp[i]表示以seq[i]结尾（必须）的最大子序列和
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++) cin>>seq[i];
        dp[0] = seq[0];
        for(int i=1;i<n;i++)
            dp[i] = max(dp[i-1]+seq[i] , seq[i]); //如果dp[i-1]>0则加上它，否则就是它本身（作为一个新的子序列）
        long long ans = -maxn;
        for(int i=0;i<n;i++)
            if(dp[i] > ans)
                ans = dp[i];
        cout<<ans<<endl;
    }
    
    return 0;
}

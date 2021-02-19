//create on 20210219
//牛客网-最长回文子串
//算法笔记P437
//二维dp
//dp[i][j]表示s[i]到s[j]是否包含回文子串，是为1
//dp[i][j] = dp[i+1][j-1]; s[i] == s[j]
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1010;
char s[maxn];
bool dp[maxn][maxn]; //dp[i][j]表示s[i]到s[j]是否包含回文子串，是为1
int main(){
    while(cin>>s+1){
        int len = strlen(s+1);
        int ans = 1;
        for(int i=1;i<=len;i++){ //边界
            dp[i][i] = 1;
            if(s[i]==s[i+1]){
                dp[i][i+1] = 1;
                ans = 2;
            }
        }
        //为了避免先前的dp没有求出来的情况，我们对子串长度l进行枚举
        for(int l=3;l<=len;l++){
            for(int i=1;i+l-1<=len;i++){ //子串头
                int j = i+l-1;//子串尾
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = dp[i+1][j-1];
                    ans = l;
                }
            }
        }
        cout<<ans<<endl;
        memset(dp, 0 , sizeof(dp));//多组数据，清空
    }
    return 0;
}
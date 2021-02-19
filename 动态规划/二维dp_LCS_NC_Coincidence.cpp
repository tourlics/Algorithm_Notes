//create on 20210219
//牛客网-Coincidence
//最长公共子序列问题LCS
//二维dp
//dp[i][j]表示字符串a的i号位和字符串b的j号位之前的LCS长度
//dp[i][j] = dp[i-1][j-1] + 1 ;a[i]=b[j]
//dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;a[i]!=b[j]
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 101;
char a[maxn],b[maxn];
int dp[maxn][maxn];
int main(){
    cin>>a+1>>b+1; //从下标1开始读入；char数组支持这样写，string不支持这样写
    int lena = strlen(a+1);
    int lenb = strlen(b+1); 
    for(int i=0;i<lena;i++) dp[i][0] = 0;
    for(int j=0;j<lenb;j++) dp[0][j] = 0;//状态边界
    for(int i=1;i<=lena;i++){ //状态转移方程
        for(int j=1;j<=lenb;j++){
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[lena][lenb]<<endl;
    return 0;
}
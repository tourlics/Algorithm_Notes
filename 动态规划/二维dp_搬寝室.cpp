//create on 20210219
//王道-搬寝室
//二维dp
#include<iostream>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;

int dp[1001][2001]; //dp[i][j]表示在前j个物品中选择i对物品时，最小疲劳度
int data[2001];
int main(){
    int n,k;
    while(cin>>n>>k){
        for(int i=1;i<=n;i++){
            cin>>data[i];
        }
        sort(data+1,data+1+n);//从大到小排序；根据结论相差最小的两个物品配对
        for(int i=1;i<=n;i++) dp[0][i] = 0; //边界
        for(int i=1;i<=k;i++){
            for(int j=2*i;j<=n;j++){
                if(j>2*i) //前i对物品已经配对，不需要后面的物品
                    dp[i][j] = dp[i][j-1];
                else dp[i][j] = inf; //j==2*i
                int value = (data[j]-data[j-1])*(data[j]-data[j-1]);
                dp[i][j] = min(dp[i][j] , dp[i-1][j-2]+value); //状态转移
            }
        }
        cout<<dp[k][n]<<endl;
    }
    return 0;
}
//create on 20210201
//质因数分解模板
//牛客网-质因数的个数
#include<iostream>
#include<cmath>
#define MAXN 10010
using namespace std;
bool mark[MAXN]; //全局变量 初始值为 false；若为true，则表示非素数
int prime[MAXN]; //存储素数

int find_prime(int end){
    int cnt = 0; //记录素数的个数
    for(int i = 2;i<=end;i++){
        if(mark[i]) continue;
        prime[cnt++] = i; //else 新增一个素数
        for(int j = i*i;j<=end;j += i){ //注意如果从2开始数起，从i开始标记；如果不是的话，得从2开始标记
            mark[j] = true;
        }
    }
    return cnt;
}
struct factor{
    int num; //底数
    int times; //幂指数
}fac[10]; //由于最小的10个素数乘积大于int能表示的范围
 
int main(){
    int ans = 0;
    int x;
    int cnt = find_prime(MAXN-10);
    while(scanf("%d",&x)!=EOF){
        int k = 0;
        for(int i=0;i<cnt && x!=1;i++){
            if(x % prime[i]!=0) continue;
            int tcnt = 0;
            while(x % prime[i] == 0){
                x = x/prime[i];
                tcnt++;
            }
            fac[k].num = prime[i];
            fac[k++].times = tcnt;
        }
        if(x!=1){ //遍历完后如果没有分解完
            fac[k].num = x;
            fac[k].times = 1;
        }
        for(int j=0;j<=k;j++) ans += fac[j].times;
        cout<<ans<<endl;
    }
    return 0;
}

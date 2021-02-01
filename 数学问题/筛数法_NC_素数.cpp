//create on 20210201
//筛数法模板
//牛客网-素数
#include<iostream>
#include<cmath>
#define MAXN 10010
using namespace std;
bool mark[MAXN]; //全局变量 初始值为 false；若为true，则表示非素数
int prime[MAXN]; //存储素数（本题不用）

int find_prime(int end){
    int cnt = 0; //记录素数的个数（本题不用）
    for(int i = 2;i<=end;i++){
        if(mark[i]) continue;
        prime[cnt++] = i; //else 新增一个素数
        for(int j = i*i;j<=end;j += i){ //注意如果从2开始数起，从i开始标记；如果不是的话，得从2开始标记
            mark[j] = true;
        }
    }
    return cnt;
}

int main(){
    int prime_num = find_prime(MAXN);
    int x;
    while(scanf("%d",&x)!=EOF){
        bool state = 0;
        for(int i=2;i<x;i++){
            if(!mark[i]&&state&&i%10==1){//按题目要求，输出个位为1的素数
                state = 1;
                cout<<" "<<i; //按题目要求，第一个数前不能输出空格
            }
            else if(!mark[i]&&!state&&i%10==1){
                state = 1;
                cout<<i;
            } 
        }
        if(!state) cout<<-1;
        cout<<endl;
    }
    return 0;
}

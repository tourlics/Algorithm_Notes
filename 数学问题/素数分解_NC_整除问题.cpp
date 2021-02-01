//create on 20210201
//n!的分解
//牛客网-整除问题
#include<iostream>
#include<cmath>
#define MAXN 1001
using namespace std;
bool mark[MAXN]; //全局变量 初始值为 false；若为true，则表示非素数
int prime[MAXN]; //存储素数
int cnt; //记录素数的个数
void find_prime(int end){
    for(int i = 2;i<=end;i++){
        if(mark[i]) continue;
        prime[cnt++] = i; //else 新增一个素数
        for(int j = i*i;j<=end;j += i){ //注意如果从2开始数起，从i开始标记；如果不是的话，得从2开始标记
            mark[j] = true;
        }
    }
}

struct factor{
    int num; //底数
    int times; //幂指数
}faca[10]; //由于最小的10个素数乘积大于int能表示的范围
int splita(int a){//分解a，将结果存在faca中
    int k = 0;
    for(int i=0;i<cnt && a!=1;i++){
        if(a % prime[i]!=0) continue;
        int tcnt = 0;
        while(a % prime[i] == 0){
            a = a/prime[i];
            tcnt++;
        }
        faca[k].num = prime[i];
        faca[k++].times = tcnt;
    }
    if(a!=1){ //遍历完后如果没有分解完
        faca[k].num = a;
        faca[k++].times = 1;
    }
    return k-1;
}

factor facn[10]; //由题意，要想整除，n!和a的素因数底数都一样，所以个数相等
int splitn(int n){//分解n!，将结果存在facn中
    int k = 0;
    for(int p=0;p<cnt;p++){
        int cntp = 0;
        int t = n/(int)pow(prime[p],1);
        if(t==0) continue;
        for(int i=2;t!=0;i++){ //计算n/(p^i)，一旦t=0结束分解
            cntp += t;
            t = n/(int)pow(prime[p],i);
        }
        facn[k].num = prime[p];
        facn[k++].times = cntp;
    }
    return k-1;
}

int main(){
    int n,a;
    find_prime(MAXN);
    while(scanf("%d %d",&n,&a)!=EOF){
        int ka = splita(a);
        int kn = splitn(n);
        //找最小的k
        int minn = 999999;
        for(int i=0;i<=ka;i++){
            int k = 0;
            while(faca[i].num!=facn[k].num) k++;
            int t = facn[k].times/faca[i].times; //如果ka>kn出现不匹配时，则t=0
            if(t<minn) minn = t;
        }
        cout<<minn<<endl;
    }
    return 0;
}

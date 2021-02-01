//create on 20210201
//十进制转化为m进制
//牛客网-又一版A+B
#include<iostream>
using namespace std;
int arrx[50]; //存输入a的每一位
int splitx_m(long long x,int m){ 
    if(x==0){ //处理输入为0的情况
        arrx[0] = 0;
        return 1;
    }
    int i;
    for(i=0;x!=0;i++){ //注意数组实际存储位置和数的顺序刚好相反
        arrx[i] = x%m;
        x /= m;
    }
    return i; //返回a的位数
}

int main(){
    int m,a,b;
    while(scanf("%d",&m)!=EOF){ //注意处理输入的技巧
        if(m==0) break;
        scanf("%d %d",&a,&b);
        long long n = a+b; //两个int相加可能超过int(2^32约为4*10^9，即40亿)
        int num = splitx_m(n,m);
        for(int i=num-1;i>=0;i--) cout<<arrx[i];
        cout<<endl;
    }
    return 0;
}
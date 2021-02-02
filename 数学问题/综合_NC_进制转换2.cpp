//create on 20210202
//大整数n进制转化为m进制
//牛客网-进制转换2
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
char arrn[50]; //存输入n进制的a的每一位（即输入）
char arrm[50]; //存m进制的a的每一位（即输出）
struct bignum{
    int d[MAXN];
    int len;
    bignum(){
        memset(d,0,sizeof(d));
        len = 0;
    }
    bignum(char* t){
        len = strlen(t);
        for(int i=len-1;i>=0;i--){
            d[i] = t[len-i-1]-'0';
        }
    }
};
bignum multi(bignum a,int b){
    bignum c;
    int carry = 0;
    for(int i=0;i<a.len;i++){
        int tmp = a.d[i]*b + carry;
        carry = tmp/10;
        c.d[i] = tmp%10;
    }
    c.len = a.len;
    while(carry){ //对进位拆分数位
        c.d[c.len++] = carry%10;
        carry /= 10;
    }
    return c;
}
bignum n2D(int n,int num){ //n进制转十进制
    long long result = 0;
    for(int i=0;i<num;i++){
        if(arrn[i]<='9' && arrn[i]>='0') result += (arrn[i]-'0')*(long long)pow(n,num-i-1);
        else if(arrn[i]<='F' && arrn[i]>='A') result += (arrn[i]-'A'+10)*(long long)pow(n,num-i-1);
        else if(arrn[i]<='f' && arrn[i]>='a') result += (arrn[i]-'a'+10)*(long long)pow(n,num-i-1);
    }
    return result; //返回long long型的十进制
}
bignum D2m(long long d,int m){  //十进制转m进制
    if(d==0){ //处理输入为0的情况
        arrm[0] = '0';
        return 1;
    }
    int i;
    for(i=0;d!=0;i++){ //注意数组实际存储位置和数的顺序刚好相反
        if(d%m < 10) arrm[i] = '0'+ d%m;
        else if(d%m >= 10 && d%m < 16) arrm[i] = 'A'+ (d%m-10);
        d /= m;
    }
    return i; //返回d的位数
}

int main(){
    int n,m;
    while(scanf("%d %s %d",&n,arrn,&m)!=EOF){ 
        long long x = n2D(n,strlen(arrn)); 
        int num = D2m(x,m);
        for(int i=num-1;i>=0;i--) cout<<arrm[i];
        cout<<endl;
    }
    return 0;
}
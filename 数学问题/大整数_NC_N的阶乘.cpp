//create on 20210202
//大整数乘以int
//牛客网-N的阶乘
#include<iostream>
#include<cstring>
#define MAXN 10010
using namespace std;
struct bignum{
    int d[MAXN];
    int len;
    bignum(){
        memset(d,0,sizeof(d));
        len = 0;
    }
    bignum(int t){
        int i;
        for(i=0;t!=0;i++){
            d[i] = t%10;
            t = t/10;
        }
        len = i;
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
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        bignum a(n);
        for(int i=n-1;i>1;i--){
            a = multi(a,i); //具有相同结构的结构体变量可以直接赋值
        }
        for(int i=a.len-1;i>=0;i--){
            printf("%d",a.d[i]);
        }
        cout<<endl;
    }
    
    return 0;
}
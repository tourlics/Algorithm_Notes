#include<iostream>
using namespace std;
int gcd(int a,int b){ //递归写法
    if(b == 0) return a; //递归终点
    else return gcd(b,a%b);
}
// int gcd(int a,int b){ //非递归写法
//     while(b!=0){
//         int t = a%b;
//         a = b;
//         b = t;
//     }
//     return a;
// }
int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        cout<<gcd(a,b)<<endl;
        //cout<<a*b/gcd(a,b)<<endl;//最小公倍数
    }
    return 0;
}
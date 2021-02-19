//create on 20210219
//牛客网-N阶楼梯上楼问题
//一维动态规划/递推解法
//同类问题：裴波那契数列、吃糖果
#include<iostream>
using namespace std;
int n;
long long f[91];
int main(){
    cin>>n;
    f[1] = 1;
    f[2] = 2;
    for(int i=3;i<=90;i++) 
    	f[i] = f[i-1]+f[i-2]; //考虑最后一步（数量和前面几步产生的数量相等），只有两种情况，从n-1或n-2一步上来
    cout<<f[n];
    return 0;
}
//create on 20210219
//牛客网-N阶楼梯上楼问题
//递归解法
#include<iostream>
using namespace std;
int n;
int cnt;
void dfs(int step){
    if(step == n){
        cnt++;
        return ;
    }
    else if(step > n) return ;
    dfs(step+1);
    dfs(step+2);
}
int main(){
    cin>>n;
    dfs(0);
    cout<<cnt;
    return 0;
}
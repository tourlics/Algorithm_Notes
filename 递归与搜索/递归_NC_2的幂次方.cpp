//create on 20210219
//牛客网-2的幂次方
//递归
#include<iostream>
#include<vector>
using namespace std;
void dfs(int n){
    vector<int> bin; //逆序存放n的二进制表示
    while(n){
        bin.push_back(n%2);
        n /= 2;
    }
    bool mark = 1;
    //2(7)+2(3)+2(0) 对每一位再进行转化
    for(int i=bin.size()-1;i>=0;i--){
        if(bin[i] == 1){ //第i位为1
            if(!mark) cout<<"+"; //第一个前面不能有加号
            mark = false;
            //递归边界
            if(i == 0){ //最低位为1
                cout<<"2(0)";
            }
            else if(i == 1){ //次低位为1
                cout<<"2";
            }
            //递归关系式
            else{
                cout<<"2(";
                dfs(i);
                cout<<")";
            }
        }
    }
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        dfs(n);
        cout<<endl;
    }
    return 0;
}
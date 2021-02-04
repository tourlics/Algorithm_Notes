//create on 20210204
//牛客网-二叉树
//完全二叉树，求某一结点所在子树的结点个数
#include<iostream>
#include<cmath>
using namespace std;

int lefti(int v){
	return 2*v;
}
int righti(int v){
	return 2*v+1;
}

int main(){
    int m,n;
    while(cin>>m>>n){
        if(m==n && m==0) break;
        int cnt = 1; //根结点
        int node = m;
        for(int i=1;node<=n;i++){
            if(righti(node)<=n){ //某一层是满的
                cnt += (int)pow(2,i); 
                node = righti(node);
            }
            else break; //某一层不满
        }
        //如果某一层不满
        int t1 = node - 1;
        if(n>=lefti(t1)) cnt += n - lefti(t1);
        cout<<cnt;
    }
    
    return 0;
}
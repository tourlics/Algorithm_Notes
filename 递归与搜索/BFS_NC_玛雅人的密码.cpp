//create on 20210218
//BFS
//牛客网-玛雅人的密码
#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;
struct node{
    string s;
    int step;
};
int n;//字符串长度
queue<node> q;
map<string,int> inq; //用来判断之前是否判断过该状态（是否进入过队列）），从而剪枝
int bfs(){
    while(!q.empty()){
        node cur = q.front();
        q.pop();
        for(int i=0;i<n-1;i++){ //遍历每个状态转移
            string cs = cur.s;
            char t = cs[i];
            cs[i] = cs[i+1];
            cs[i+1] = t; //swap
            if(inq[cs]) continue; //先前已经判断过，剪枝
            if(cs.find("2012")!=-1) return cur.step + 1; //找到了
            node next;
            next.s = cs;
            next.step = cur.step + 1;
            q.push(next);
            inq[cs] = 1;
        }
    }
    return -1;
}
int main(){
    cin>>n;
    string t;
    cin>>t;
    if(t.find("2012")!=-1){
        cout<<0<<endl;
        return 0;
    }
    node start;
    start.s = t;
    start.step = 0;
    q.push(start);
    inq[start.s] = 1;
    cout<<bfs()<<endl;
    return 0;
}
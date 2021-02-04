//create on 20210204
//牛客网-哈夫曼树;搬水果
//实质就是求非叶子结点之和
#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>,greater<int> > q; //由于默认最大堆，所以需要更改

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        for(int i=0;i<n;i++){
            int t;
            scanf("%d",&t);
            q.push(t);
        }
    }
    int size = q.size();
    int ans = 0;
    for(int i=0;i<size-1;i++){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a+b;
        q.push(a+b);
    }
    cout<<ans<<endl;
    return 0;
}
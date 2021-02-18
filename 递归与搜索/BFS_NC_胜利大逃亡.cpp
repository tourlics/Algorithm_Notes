//create on 20210218
//BFS+剪枝
//牛客网-试题广场-胜利大逃亡
#include<iostream>
#include<queue>
using namespace std;
struct node{
    int x,y,z; //坐标
    int t; //时间；表示经过t能到达该坐标
};
queue<node> q;
bool cube[51][51][51]; //保存立方体坐标信息
bool mark[51][51][51]; //保存某个坐标是否已经出现在先前（t较小）的状态中

int nextx[] = {1,-1,0,0,0,0};
int nexty[] = {0,0,1,-1,0,0};
int nextz[] = {0,0,0,0,1,-1}; //依次为往x轴正负、y轴正负、z轴正负方向移动

int bfs(int a,int b,int c){
    while(!q.empty()){
        node cur = q.front();
        q.pop();
        for(int i=0;i<6;i++){ //6个方向
            int nx = cur.x + nextx[i];
            int ny = cur.y + nexty[i];
            int nz = cur.z + nextz[i]; //临时变量以便后续判断
            if(cube[nx][ny][nz]) continue; //墙，此路不通
            if(nx>=a||nx<0||ny>=b||ny<0||nz>=c||nz<0) continue; //出界
            if(mark[nx][ny][nz]) continue; //先前已经访问过了，剪枝
            if(nx==a-1 && ny==b-1 && nz==c-1) return cur.t + 1; //找到这个点，直接返回
            node next;
            next.x = nx;
            next.y = ny;
            next.z = nz;
            next.t = cur.t + 1;
            q.push(next);
            mark[nx][ny][nz] = 1; //标记该坐标
        }
    }
    return -1; //找不到坐标abc
}
int main(){
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){ //有k组测试数据
        int a,b,c,t;
        scanf("%d %d %d %d",&a,&b,&c,&t);
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                for(int s=0;s<c;s++){
                    scanf("%d",&cube[i][j][s]);
                    mark[i][j][s] = false; //由于有多组测试数据，所以要进行清空
                }
            }
        }
        while(!q.empty()) q.pop(); //由于有多组测试数据，所以要进行清空
        node start;
        start.x = start.y = start.z = start.t = 0;
        q.push(start);
        int time = bfs(a,b,c);
        if(time <= t) cout<<time<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
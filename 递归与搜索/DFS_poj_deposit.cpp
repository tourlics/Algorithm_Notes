//create on 20210218
//poj-oil deposit
//递归；dfs

#include<iostream>

using namespace std;
int m,n;
bool map[110][110]; //true 为@，false为*
bool mark[110][110]; //true表示已经访问过
int nextx[] = {1,-1,0,0,1,-1,1,-1};
int nexty[] = {0,0,1,-1,1,-1,-1,1}; //八个方向

void dfs(int x,int y){
    for(int i=0;i<8;i++){
        int nx = x + nextx[i];
        int ny = y + nexty[i];
        if(nx>m||nx<1||ny>n||ny<1) continue; //出界；地图从1开始，而不是0
        if(!map[nx][ny]) continue; //为*
        if(mark[nx][ny]) continue; //之前已经访问过
        mark[nx][ny] = 1;
        dfs(nx,ny);
    }
    return ;
}
int main(){
    while(scanf("%d %d",&m,&n)!=EOF){
        if(m==0) break;
        getchar(); //吃掉换行
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                char temp;
                scanf("%c",&temp);
                if(temp == '@') map[i][j] = 1;
                else if(temp == '*') map[i][j] = 0;
            }
            getchar(); //吃掉换行
        }
        int cnt = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){ //对每一个点dfs
                if(mark[i][j]) continue;
                if(!map[i][j]) continue;
                dfs(i,j);
                cnt++;
            }
        }
        cout<<cnt<<endl;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){ //由于有多组数据，所以要及时清空
                mark[i][j] = 0;
            }
        }
    }
    return 0;
}

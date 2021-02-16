//show the whole procedure as the notes demostrate.
#include<iostream>
#define inf 9999999
using namespace std;
int book[101],e[101][101],n,start,term,data[101];
//start means start from start
//term means the termination, use d[term] to get. In fact, we can get all the path from data[]
//data[] stores the shortest distance of every vertex
int countk; //record the number of vertices booked
int seekmin(){
	int minn=inf;
	int index;
	for(int i=1;i<=n;i++){
		if(book[i]==0 && data[i]<minn){ //make sure not compare with the vertex booked
			minn = data[i];
			index = i;
		}
	}
	return index;
}
void Dijkstra(int cur,int dis){
	book[cur] = 1;
	countk++;
	for(int i=1;i<=n;i++)
		if(book[i]==0 && dis+e[cur][i]<data[i]) //inf + dis< inf
			data[i] = dis + e[cur][i];
}
void show(){
	for(int i=1;i<=n;i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int i,j,m,a,b,c;
	scanf("%d %d %d %d",&n,&m,&start,&term);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=inf;
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		e[a][b]=c;
		e[b][a]=c;
	}
	//initialize
	for(int i=1;i<=n;i++){
		if(i==start) data[i] = 0;
		else data[i] = inf;
	}
	Dijkstra(start,0);
	show();
	int next = seekmin();
	while(countk!=n){
		Dijkstra(next,data[next]);
		show();
		next = seekmin();
		
	}
	printf("%d\n",data[term]);	
	return 0;
}
/*------Test-------
//×ó²à 
7 12 1 4
1 2 12
2 3 10
3 4 3
4 5 4
3 5 5
5 6 2
3 6 6
2 6 7
1 6 16
6 7 9
5 7 8
1 7 14
//ÓÒ²à 
6 9 1 6
1 2 4
1 3 2
2 3 3
2 4 5
3 4 8
3 5 10
4 5 2
5 6 3
4 6 6
*/ 

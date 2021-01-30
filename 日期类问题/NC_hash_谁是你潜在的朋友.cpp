#include<iostream>
#define MAXN 201
using namespace std;
int book[MAXN];
int reader[MAXN];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        reader[i] = temp;
        book[temp]++;
    }
    for(int i=0;i<n;i++){
        int temp = reader[i];
        if(book[temp]==1) cout<<"BeiJu"<<endl;
        else cout<<book[temp]-1<<endl;
    }
    return 0;
}
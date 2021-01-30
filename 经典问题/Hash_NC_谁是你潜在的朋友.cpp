//create on 20210130
//牛客网-谁是你潜在的朋友
#include<iostream>
#define MAXN 201
using namespace std;
int book[MAXN];//m<201，表示第i本书有几个人读
int reader[MAXN]; //记录输入时第i个读者喜欢读第几本书
int main(){
    int n,m;//n个读者，m本书
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
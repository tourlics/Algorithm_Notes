//create on 20210218
//牛客网-全排列
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
string s;
map<string,int> mp;
void swap(int n,int i){
    char t = s[n];
    s[n] = s[i];
    s[i] = t;
}
void perm(int n){
    if(n == s.length()){
        mp[s] = 1;
        return ;
    }
    int len = s.length();
    for(int i=n;i<len;i++){
        swap(n,i);
        perm(n+1);
        swap(n,i);
    }
}
int main(){
    cin>>s;
    perm(0);
    for(auto i=mp.begin();i!=mp.end();i++) cout<<i->first<<endl;
    return 0;
}
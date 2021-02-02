//create on 20210202
//大整数排序
//此题可以不转化为大整数，直接使用字符串排序
//牛客网-大整数排序
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 1010
using namespace std;
struct bignum{
    int d[MAXN];
    int len;
};
bool cmp(bignum a,bignum b){
    if(a.len < b.len) return true;
    else if(a.len > b.len) return false;
    else{
        bool state = 0;
        for(int i = a.len-1;i>=0;i--){
            if(a.d[i]==b.d[i]) continue;
            if(a.d[i]<b.d[i]){
                state = 1;
                break;
            }
            if(a.d[i]>b.d[i]){
                state = 0;
                break;
            }
            
        }
        if(state) return true;
        else  return false;
    }
}
void show(bignum a){
    for(int i=a.len-1;i>=0;i--){
            printf("%d",a.d[i]);
        }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    struct bignum data[101];
    for(int i=0;i<n;i++){
        char t[MAXN];
        scanf("%s",t);
        int length = strlen(t);
        data[i].len = length;
        for(int j=length-1;j>=0;j--){
            data[i].d[j] = t[length-j-1]-'0';
        }
    }
    sort(data,data+n,cmp);
    for(int i=0;i<n;i++) show(data[i]);
    return 0;
}
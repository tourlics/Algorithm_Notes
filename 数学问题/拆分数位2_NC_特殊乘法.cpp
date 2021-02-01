//crete on 20210201
//拆分数位方法二：将数当作字符串处理
#include<iostream>
using namespace std;
int main(){
    char a[11],b[11];
    while(scanf("%s %s",a,b)!=EOF){ //字符串数组名表示首地址
        int result=0;
        for(int i=0;a[i]!=0;i++){ //字符串数组末尾位'\0'
            for(int j=0;b[j]!=0;j++){
                result += (a[i]-'0')*(b[j]-'0');
            } 
        }
        cout<<result<<endl;
    }
}
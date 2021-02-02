//create on 20210202
//浮点数加法
//注意整数是右对齐，小数是左对齐
//牛客网-浮点数加法
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 1010
using namespace std;
struct floatnum{
    int dec[MAXN]; //小数部分
    int declen; //小数部分长度
    int inte[MAXN];//整数部分
    int intelen;//整数部分长度
    floatnum(){
        memset(dec,0,sizeof(dec));
        memset(inte,0,sizeof(inte));
        declen = 0;
        intelen = 0;
    }
    floatnum(char* de,char* in){
        declen = strlen(de);
        for(int i=declen-1;i>=0;i--){
            dec[i] = de[declen-i-1]-'0';
        }
        intelen = strlen(in);
        for(int i=intelen-1;i>=0;i--){
            inte[i] = in[intelen-i-1]-'0';
        }
    }
};
floatnum addfloat(floatnum a,floatnum b){
    floatnum c;
    int carry = 0;
    if(a.intelen >= b.intelen){ //小数部分处理较为麻烦
        for(int i=0;i<a.intelen-b.intelen;i++) c.inte[i] = a.inte[i];
        for(int i=a.intelen-b.intelen;i<a.intelen;i++){
            int tmp = a.inte[i] + b.inte[i+b.intelen-a.intelen] + carry;
            c.inte[i] = tmp % 10;
            carry = tmp / 10;
        }
        c.intelen = a.intelen;
    }
    if(a.intelen < b.intelen){
        for(int i=0;i<b.intelen-a.intelen;i++) c.inte[i] = b.inte[i];
        for(int i=b.intelen-a.intelen;i<b.intelen;i++){
            int tmp = b.inte[i] + a.inte[i+a.intelen-b.intelen] + carry;
            c.inte[i] = tmp % 10;
            carry = tmp / 10;
        }
        c.intelen = b.intelen;
    }
    
    int lenth2 = max(a.declen,b.declen);
    for(int i=0;i<lenth2;i++){
        int tmp = a.dec[i] + b.dec[i] + carry; //小数部分的进位直接加到整数部分
        c.dec[i] = tmp % 10;
        carry = tmp / 10;
    }
    if(carry) c.dec[lenth2++] = b.dec[lenth2] + 1;
    c.declen = lenth2;
    return c;
}
void show(floatnum c){
    for(int i=c.declen-1;i>=0;i--){
        printf("%d",c.dec[i]);
    }
    printf(".");
    for(int i=c.intelen-1;i>=0;i--){
        printf("%d",c.inte[i]);
    }
    printf("\n");
}
int main(){
    char ade[1000],ain[1000],bde[1000],bin[1000];
    for(int i=0;;i++){
        char t;
        scanf("%c",&t);
        if(t=='.') break;
        ade[i] = t;
    }
    for(int i=0;;i++){
        char t;
        scanf("%c",&t);
        if(t=='\n') break;
        ain[i] = t;
    }
    for(int i=0;;i++){
        char t;
        scanf("%c",&t);
        if(t=='.') break;
        bde[i] = t;
    }
    for(int i=0;;i++){
        char t;
        scanf("%c",&t);
        if(t=='\n') break;
        bin[i] = t;
    }
    floatnum a(ade,ain);
    floatnum b(bde,bin);
    floatnum c = addfloat(a, b);
    show(c);
    return 0;
}
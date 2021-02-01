//create on 20210201
//拆分数位
//牛客网：特殊乘法
#include<iostream>
using namespace std;
int arra[10]; //存输入a的每一位
int arrb[10];
int splita(int a){ 
    int i;
    for(i=0;a!=0;i++){ //注意数组实际存储位置和数的顺序刚好相反
        arra[i] = a%10;
        a /= 10;
    }
    return i; //返回a的位数
}
int splitb(int b){ 
    int i;
    for(i=0;b!=0;i++){
        arrb[i] = b%10;
        b /= 10;
    }
    return i; //返回b的位数
}

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        int numa = splita(a);
        int numb = splitb(b);
        int result = 0;
        //数组实际存储位置和数的顺序刚好相反，为了完全模拟题意，故从后到前；
        //其实就本题然而，从前到后也一样
        for(int i=numa-1;i>=0;i--){ 
            for(int j=numb-1;j>=0;j--){
                result += arra[i]*arrb[j];
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
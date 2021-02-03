//create on 20210203
//牛客网-简单计算器（有空格）
//第一种思路如代码所示
//第二种思路：先将所有空格用tmp.replace(" ","")去掉，然后按没有空格的计算，代码见另一个
#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
string tmp;
stack<double> digital;
stack<char> sign;
int dors(char t){
    if(t<='9'&&t>='0') return 1; //数字
    if(t==' ') return 2; //空格
    else return 3; //运算符
}
int prio(char t){
    if(t=='&') return 0; // 自定义字符，方便后续写程序
    if(t=='+' || t=='-') return 1;
    if(t=='*' || t=='/') return 2;
    else return -1;
}
double oper(double a,double b,char t){
    if(t == '+') return a+b;
    else if(t == '-') return a-b;
    else if(t == '*') return a*b;
    else if(t == '/') return a/b;
    else return -1;
}
int main(){
    while(getline(cin,tmp)){
        if(tmp=="0") break;
        sign.push('&');//自定义字符，方便处理符号栈为空的情况
        tmp = tmp + "\n";
        int len = tmp.length();
        int result = 0; //处理多位数字
        for(int i=0;i<len;i++){
            if(i!=0&&dors(tmp[i-1])==1&&(tmp[i]==' '||tmp[i]=='\n')){
                digital.push(result); 
                result = 0;
            }
            else if(dors(tmp[i])==1){//如果是数字
                result = 10*result + tmp[i]-'0';
            }
            else if(dors(tmp[i])==3){ //如果是运算符
                if(prio(tmp[i])>prio(sign.top())){ 
                    sign.push(tmp[i]);
                }
                else{
                    while(prio(tmp[i])<=prio(sign.top())){ //当前运算符优先级比栈顶运算符小或等于
                        char t = sign.top(); //取栈顶元素
                        sign.pop(); //弹栈顶
                        double b = digital.top();
                        digital.pop();
                        double a = digital.top();
                        digital.pop();
                        double ans = oper(a,b,t);
                        digital.push(ans);
                    }
                    sign.push(tmp[i]);
                } 
            }
        }
        while(sign.top()!='&'){
            char t = sign.top(); //取栈顶元素
            sign.pop(); //弹栈顶
            double b = digital.top();
            digital.pop();
            double a = digital.top();
            digital.pop();
            double ans = oper(a,b,t);
            digital.push(ans);
        }
        printf("%.2f\n",digital.top());
        //由于要重复读入，所以要清空
        while(!digital.empty()) digital.pop();
        while(!sign.empty()) sign.pop();
    }
    
    return 0;
}
//3-7-1+3+3*6-3/1*9-9
//9-1*9-10*4-4-4+7-3+6
//create on 20210203
//牛客网-计算表达式（无空格）
//结合算法笔记理解代码思路
//注意注释块中的代码是另一种写法：=的作用只是将最后一个数压栈；处理完字符串以后，还要不断地弹栈
#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
string tmp;
stack<double> digital;
stack<char> sign;
bool dors(char t){
    if(t<='9'&&t>='0') return true; //数字
    else return false; //运算符
}
int prio(char t){
    if(t=='$') return 0; // 自定义字符，方便后续写程序
    if(t=='=') return 1; //末尾字符
    if(t=='+' || t=='-') return 2;
    if(t=='*' || t=='/') return 3;
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
        sign.push('$');//自定义字符，方便处理符号栈为空的情况
        tmp = tmp + "=";//标志字符串末尾，将最后一个数字压栈
        int i=0;
        double result = 0;
        while(i<tmp.size()){
            while(dors(tmp[i])){
                result = result*10 + tmp[i] - '0';
                i++;
            }
            digital.push(result);
            result = 0;
//             if(tmp[i]=='=') break;
            //如果是运算符
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
            i++;
        }
       
//         while(sign.top()!='&'){
//             char t = sign.top(); //取栈顶元素
//             sign.pop(); //弹栈顶
//             double b = digital.top();
//             digital.pop();
//             double a = digital.top();
//             digital.pop();
//             double ans = oper(a,b,t);
//             digital.push(ans);
//         }
        cout<<digital.top()<<endl;
        //由于要重复读入，所以要清空
        while(!digital.empty()) digital.pop();
        while(!sign.empty()) sign.pop();
        tmp.clear();
    }
    
    return 0;
}
//3-7-1+3+3*6-3/1*9-9
//9-1*9-10*4-4-4+7-3+6
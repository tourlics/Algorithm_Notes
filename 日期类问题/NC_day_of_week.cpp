//create on 20210130
//同NC日期差值.cpp；判断今天（星期日）和输入日期的差值，然后除以7得到星期几
#include<iostream>
using namespace std;
typedef struct Date{
    int year;
    int mon;
    int day;
};
bool operator!=(Date &t1,Date &t2){ //cpp操作符重载，比较两个结构体是否相等
   return (t1.year!=t2.year)||(t1.mon!=t2.mon)||(t1.day!=t2.day);
}
char month[13][20] = {" ","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char week_day[8][10] = {" ","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int chartoint(char mon[]){ //将输入的字符串转化为整数型
    int i=1;
    for(i=1;i<=12;i++){
        if(strcmp(mon,month[i])==0) //如果两个字符串相等
            break; 
    }
    return i;
}
int leap_month[] = {-1,31,29,31,30,31,30,31,31,30,31,30,31}; //闰年月份对应的天数
int usual_month[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};

bool isleap(int year){ 
    //判断闰年：当年数能被4整除且不能被100整除，或者能被400整除时为闰年
    if(year%4==0&&year%100!=0 || year%400==0) return true;
    else return false;
}

Date nextday(Date d){ //计算下一天
    if(isleap(d.year)){ //闰年情况
        if(d.day+1 <= leap_month[d.mon]) d.day++; //如果不是这个月的最后一天
        else{ //如果是这个月的最后一天
            d.day = 1;
            if(d.mon!=12) d.mon++; //如果不是这一年的最后一个月
            else{ //如果是这一年的最后一个月
                d.mon = 1;
                d.year++;
            }
        }
    }
    else{ //非闰年情况，代码同上
        if(d.day+1 <= usual_month[d.mon]) d.day++;
        else{
            d.day = 1;
            if(d.mon!=12) d.mon++;
            else{
                d.mon = 1;
                d.year++;
            }
        }
    }
    return d;
}

int main(){
    Date dstart,dend;
    char stemp[20];
    scanf("%4d%s%2d",&dstart.year,stemp,&dstart.day); //注意字符串数组名即代表首地址，因此不加&
    dstart.mon = chartoint(stemp);
    memset(stemp,0,sizeof(stemp)); //清空数组stemp，防止后面使用的stemp长度大于上面的stemp
    scanf("%4d%s%2d",&dend.year,stemp,&dend.day); //注意处理输入的技巧
    dend.mon = chartoint(stemp);
    int cnt = 1; //按照题目意思，相邻日期差两天
    Date dtemp = dstart;
    while(dtemp!=dend){ //已操作符重载
        dtemp = nextday(dtemp);
        cnt ++;
    }
    cout<<cnt;
    return 0;
}
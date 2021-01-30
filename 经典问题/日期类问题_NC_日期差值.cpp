//create on 20210130
//思路：从dstart开始，一天一天数到dend，注意判断是否为闰年
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
bool operator>(Date &t1,Date &t2){ //cpp操作符重载，比较两个结构体是否相等
   if(t1.year>t2.year) return true;
   else if(t1.year==t2.year && t1.mon>t2.mon) return true;
   else if(t1.year==t2.year && t1.mon==t2.mon && t1.day>t2.day) return true;
   else return false;
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
    scanf("%4d%2d%2d",&dstart.year,&dstart.mon,&dstart.day); 
    scanf("%4d%2d%2d",&dend.year,&dend.mon,&dend.day); //注意处理输入的技巧
    if(dstart>dend){ //保证dstart在dend前面
        Date dt = dend;
        dend = dstart;
        dstart = dt;
    }
    int cnt = 1; //按照题目意思，相邻日期差两天
    Date dtemp = dstart;
    while(dtemp!=dend){ //已操作符重载
        dtemp = nextday(dtemp);
        cnt ++;
    }
    cout<<cnt;
    return 0;
}
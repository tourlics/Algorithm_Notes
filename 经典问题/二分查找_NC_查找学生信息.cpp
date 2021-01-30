//create on 20210130
//思路：由于N较大，因此先排序，再二分查找
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 1001
using namespace std;
struct student{
    char sno[10];
    char sname[20];
    char ssex[5];
    int sage;
}stu[MAXN];
bool cmp(student a,student b){
    return strcmp(a.sno,b.sno)<0; //从小到大排序
}
int binary_search(int n,char sname[]){
    int lp = 0;
    int rp = n-1;
    int mp;
    while(lp<=rp){
        mp = (lp+rp)/2;
        int sgn = strcmp(sname, stu[mp].sno);
        if(sgn>0) lp = mp+1;
        else if(sgn<0) rp = mp-1;
        else return mp;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s %s %s %d",&stu[i].sno,&stu[i].sname,&stu[i].ssex,&stu[i].sage);
    }
    sort(stu,stu+n,cmp);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        char temp[20];
        cin>>temp;
        int no = binary_search(n, temp);
        if(no==-1) cout<<"No Answer!"<<endl;
        else{
            printf("%s %s %s %d\n",stu[no].sno,stu[no].sname,stu[no].ssex,stu[no].sage);
        }
    }
    return 0;
}
//create on 20210201
//�������ֽ�ģ��
//ţ����-�������ĸ���
#include<iostream>
#include<cmath>
#define MAXN 10010
using namespace std;
bool mark[MAXN]; //ȫ�ֱ��� ��ʼֵΪ false����Ϊtrue�����ʾ������
int prime[MAXN]; //�洢����

int find_prime(int end){
    int cnt = 0; //��¼�����ĸ���
    for(int i = 2;i<=end;i++){
        if(mark[i]) continue;
        prime[cnt++] = i; //else ����һ������
        for(int j = i*i;j<=end;j += i){ //ע�������2��ʼ���𣬴�i��ʼ��ǣ�������ǵĻ����ô�2��ʼ���
            mark[j] = true;
        }
    }
    return cnt;
}
struct factor{
    int num; //����
    int times; //��ָ��
}fac[10]; //������С��10�������˻�����int�ܱ�ʾ�ķ�Χ
 
int main(){
    int ans = 0;
    int x;
    int cnt = find_prime(MAXN-10);
    while(scanf("%d",&x)!=EOF){
        int k = 0;
        for(int i=0;i<cnt && x!=1;i++){
            if(x % prime[i]!=0) continue;
            int tcnt = 0;
            while(x % prime[i] == 0){
                x = x/prime[i];
                tcnt++;
            }
            fac[k].num = prime[i];
            fac[k++].times = tcnt;
        }
        if(x!=1){ //����������û�зֽ���
            fac[k].num = x;
            fac[k].times = 1;
        }
        for(int j=0;j<=k;j++) ans += fac[j].times;
        cout<<ans<<endl;
    }
    return 0;
}

//20200204
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool pd_prime(int a){
	bool state = 1;
    int b = a;
    int num = 0;
    while (a!=0){
        num = num*10 + a%10;
        a /= 10;
    } 
    if (num != b) return 0;
    int n = sqrt(b); //АнЅв 
    for(int i=2;i<n;i++){
    	if(b%i==0){
    		state = 0;
    		break;
		} 
	}
    return state;
}
int main(){
	int start,end;
	int count=0;
	scanf("%d %d",&start,&end);
	if(start%2 == 0) start += 1;
	for(int i=start;i<=end;i=i+2){
		if(pd_prime(i)){
			printf("%d\n",i); 
		//	count++;
		}
	}
	//cout<<count;
	return 0;
}



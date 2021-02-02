//20200212
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000;
struct bignum{
	int d[MAXN];
	int len;
	bignum(){ 
		memset(d,0,sizeof(d));
		len = 0;
	}
	bignum(char *t){
		memset(d,0,sizeof(d));
		len = strlen(t);
		for(int i=0;i<len;i++) 
			d[i] = t[i] - '0';
	}
};
int comparebig(bignum a,bignum b){
	if(a.len > b.len) return 1;
	else if(a.len < b.len) return -1;
	else if(a.len == b.len){
		for(int i=0;i<a.len;i++){
			if(a.d[i] == b.d[i]) continue;
			else if(a.d[i] > b.d[i]) return 1;
			else if(a.d[i] < b.d[i]) return -1;
		}
		return 0;
	}
}
bignum subbig(bignum a,bignum b){ //a>b
	reverse(a.d,a.d+a.len);
	reverse(b.d,b.d+b.len);
	bignum c;
	int lenth = a.len;
	int carry = 0;
	for(int i=0;i<lenth;i++){
		if(a.d[i]+carry < b.d[i]) {
			c.d[i] = carry + a.d[i] +10 - b.d[i];
			carry = -1;
		}
		else{
			c.d[i] = carry + a.d[i] - b.d[i];
			carry = 0;
		}
	}
	c.len = lenth;
	while(c.d[c.len-1] == 0 && c.len != 1){
		c.len--;
	}
	reverse(c.d,c.d+c.len);
	return c;
}
bignum reminder;
bignum divided_optimised(bignum a,bignum b){
	bignum c;
	int conserve = b.len;
	b.len = a.len;
	int k = 0;
	bignum t;
	int count = 0;
	if(comparebig(a,b) != -1){
		t = subbig(a,b);
		count++;
		while(comparebig(t,b) != -1){
			t = subbig(t,b);
			count++;
		}
	}else{
		b.len--;
		t = subbig(a,b);
		count++;
		while(comparebig(t,b) != -1){
			t = subbig(t,b);
			count++;
		}
	}
	c.d[k++] = count;
	b.len--;
	
	while(b.len >= conserve){
		int count = 0;
		if(comparebig(t,b) != -1){
			t = subbig(t,b);
			count++;
			while(comparebig(t,b) != -1){
				t = subbig(t,b);
				count++;
			}
		}
		c.d[k++] = count;
		b.len--;
	}
	c.len = k;
	reminder = t;
	return c;
}
void show(bignum c){
	int lenth = c.len;
	for(int i=0;i<lenth;i++) printf("%d",c.d[i]);
	printf("\n");
}

int main(){
	char tempa[MAXN];
	char tempb[MAXN];
	scanf("%s",tempa);
	scanf("%s",tempb);
	bignum a(tempa),b(tempb);
	if(comparebig(a,b) == -1){
		printf("a / b\n");
		printf("quotient = 0\n");
		printf("reminder = ");
		show(a);
		return 0;
	}
	bignum c = divided_optimised(a,b);
	printf("a / b\n");
	printf("quotient = ");
	show(c);
	printf("reminder = ");
	show(reminder);
	return 0;
}

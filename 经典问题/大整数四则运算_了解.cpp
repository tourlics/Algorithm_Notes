//create on 20200212;update on 20210202
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1000;
struct bignum{
	int d[MAXN];
	int len;
	bignum(){ 
		memset(d,0,sizeof(d));
		len = 0;
	}
	bignum(char *t){ //将字符串转化成结构体中的数组，并计算大整数数位
		len = strlen(t);
		for(int i=len-1;i>=0;i--)  //将高位放在后面，方便后面进位的处理
			d[len-i-1] = t[i] - '0';
	}
};
int comparebig(bignum a,bignum b){
	if(a.len > b.len) return 1;
	else if(a.len < b.len) return -1;
	else if(a.len == b.len){
		for(int i=a.len-1;i>=0;i--){
			if(a.d[i] == b.d[i]) continue;
			else if(a.d[i] > b.d[i]) return 1;
			else if(a.d[i] < b.d[i]) return -1;
		}
		return 0;
	}
}
bignum addbig(bignum a,bignum b){
	bignum c;
	int lenth = max(a.len,b.len);
	int carry = 0;
	for(int i=0;i<lenth;i++){
		c.d[i] = (a.d[i] + b.d[i] + carry) % 10;
		carry = (a.d[i] + b.d[i] + carry) / 10;
	}
	if(carry) c.d[lenth++] = b.d[lenth] + 1; //如果有进位
	c.len = lenth;
	return c;
}
bignum subbig(bignum a,bignum b){ //a>b
	bignum c;
	int lenth = a.len;
	int carry = 0;
	for(int i=0;i<lenth;i++){
		if(a.d[i]+carry < b.d[i]) { //如果不够减，需要借位
			c.d[i] = carry + a.d[i] +10 - b.d[i];
			carry = -1;
		}
		else{ //够减，不需要借位：对应位相减，并减去来自低位的进位
			c.d[i] = carry + a.d[i] - b.d[i];
			carry = 0;
		}
	}
	c.len = lenth;
	while(c.d[c.len-1] == 0 && c.len != 1){ //计算位数，去除掉高位为0的占位
		c.len--;
	}
	return c;
}
bignum multi(bignum a,bignum b){
	bignum c;
	bignum t[a.len+1];
	for(int i=0;i<a.len;i++){
		int carry = 0;
		for(int j=0;j<b.len;j++){
			t[i].d[i+j] = (a.d[i] * b.d[j] + carry) % 10;
			carry = (a.d[i] * b.d[j] + carry) / 10;
		}
		if(carry){
			t[i].d[i+b.len] = carry;
			t[i].len = i+ b.len + 1;
		}else t[i].len = i+ b.len;
	}
	c = addbig(t[0],t[1]);
	for(int i=2;i<a.len;i++){
		c = addbig(c,t[i]);
	}
	return c;
}

int divide(bignum a,bignum b){ // "66535664674756 3" will cause error
	int count = 0; // may overflow
	bignum c = subbig(a,b);
	while(comparebig(c,b) == 1){ //may time limit error
		c = subbig(c,b);
		count++;
	}
	return count;
}

void show(bignum c){
	int lenth = c.len;
	for(int i=lenth-1;i>=0;i--) printf("%d",c.d[i]);
	printf("\n");
}

int main(){
	char tempa[MAXN];
	char tempb[MAXN];
	scanf("%s",tempa);
	scanf("%s",tempb);
	bignum a(tempa),b(tempb);
	
	int t = comparebig(a,b);
	printf("%d\n",t);
	
	
	bignum c = addbig(a,b);
	printf("a + b = ");show(c);
	
	
	if(comparebig(a,b) == -1){
		bignum d = subbig(b,a);
		printf("a - b = -");show(d);
	}
	else{
		bignum d = subbig(a,b);
		printf("a - b = ");show(d);
	}
	
	
	bignum e = multi(a,b);
	printf("a x b = ");show(e);
	
	
	/*if(comparebig(a,b) == -1){
		printf("0\n");
	}
	else{
		int f = divide(a,b);
		printf("a / b = %d\n",f);
	}*/
	
	
	
	return 0;
}

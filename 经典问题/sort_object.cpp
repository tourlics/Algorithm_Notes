#include<iostream>
#include<algorithm>
using namespace std;
class Node{
	private: 
		int a;
		double b;
	public:
		int geta(){
			return a;
		}
		double getb(){
			return b;
		}
		void seta(int a){
			this->a = a;
		}
		void setb(double b){
			this->b = b;
		}
};
bool cmp(Node n1,Node n2){
	return n1.getb() > n2.getb();
}
int main(){
	Node n[10];
	for(int i=0;i<10;i++) {
		n[i].seta(i);
		n[i].setb(i*3.14);
	}
	sort(n,n+10,cmp);
	for(int i=0;i<10;i++) {
		cout<<n[i].geta()<<" "<<n[i].getb()<<endl;	
	}
	return 0;
}

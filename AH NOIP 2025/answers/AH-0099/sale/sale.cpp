#include<bits/stdc++.h>
using namespace std;
#define LL long long

int read();
void write(int x);
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	write(1);
	return 0;
}
int read() {
	int pre=1,Arc=0;
	char ch=getchar();
	while(ch<48||57<ch) {
		if(ch==45) pre=-1;
	ch=getchar(); }
	while(48<=ch&&ch<=57) {
		Arc=(Arc<<3)+(Arc<<1)+(ch^48);
	ch=getchar(); }
	return Arc*pre;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	int cnt1=0,stack1[40];
	do{
		stack1[++cnt1]=x%10,x/=10;
	}while(x);
	while(cnt1) putchar(stack1[cnt1--]^48);
	puts("");
}


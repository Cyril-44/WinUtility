#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long

const int N=1e5+10,MAX=1e18+1;
int n,m,ans=0;
int ax[N],bx[N],mn=MAX,mn2=0,mn3=MAX;
struct Node{
	int ax,bx;
	bool st=true;
}num[N];
bool cmp(Node a,Node b) {
	return a.ax<b.ax;
}

int read();
void write(int x);
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) {
		num[i].ax=read(),num[i].bx=read();
	}
	sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++) {
		//printf("%lld %lld\n",num[i].ax,num[i].bx);
		if(num[i].ax+num[i].bx<mn) {
			mn=num[i].ax+num[i].bx;
			mn2=i; mn3=min(num[i].ax,num[i].bx);
		}
	}
	/*for(int i=1;i<=n;i++)
		if(num[i].ax+num[i].bx==mn&&mn2!=i) {
			printf("SAME:%lld %lld\n",num[i].ax,num[i].bx);
		}*/
	//printf("mn3:%lld\n",mn3);
	//printf("%lld %lld\n",num[mn2].ax,num[mn2].bx);
	for(int i=1;i+1<=n;i+=2) {
		if(num[i].ax+num[i+1].ax<mn&&m>=num[i].ax+num[i+1].ax) {
			m-=(num[i].ax+num[i+1].ax); ans+=2;
			//if(i==mn2||i+1==mn2) puts("Success");
			num[i].st=!num[i].st;
			num[i+1].st=!num[i+1].st;
			//printf("%lld\n",num[i].ax);
		}
	}
	int gone=m/mn;
	//m-=gone*mn;
	m%=mn;
	ans+=(gone*2);
	//write(ans);
	//printf("m:%lld\n",m);
	for(int i=1;i<=n;i++) {
		int dx=0;
		if(num[i].st) dx=num[i].ax;
		else dx=num[i].bx;
		//printf("%lld\n",dx);
		if(dx<=m) {
			m-=dx; ans++;
		}
	}
	/*if(fs&&num[mn2].bx<=m) {
		m-=num[mn2].bx; ans++;
		//puts("Success");
	} 
	else 
	if(num[mn2].ax<=m) ans++;*/
	write(ans);
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


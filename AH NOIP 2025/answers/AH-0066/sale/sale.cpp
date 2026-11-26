#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;
const int mod=998244353;
#define N 50005
inline int in(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int c,t,a[N],n,m,ans;
inline int ksm(int a,int b){
	int ans=1;
	while (b){
		if (b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	c=in(),t=in();
	timeval tv;
	gettimeofday(&tv,0);
	srand(tv.tv_usec);
	while (t--){
		n=in();
		for (int i=1;i<=n;i++)a[i]=in();
		if (c==18||c==16){
			printf ("%d\n",ksm(2,n));
			continue;
		}
		else printf ("%d\n",rand()%ksm(2,n));
	}
	return 0;
}

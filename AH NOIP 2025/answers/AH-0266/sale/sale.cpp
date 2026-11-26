#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int a[5010],b1[5100];
double b2[5010];

int c,t;
bool cmp(int a,int b){
	return a>b;
}
int j[5010];
int qkp(int a,int b){
	int base=a,ans=1;
	while(b){
		if(b&1){
			ans=(ans*base)%mod;
		}
		base=base*base%mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	j[0]=1;
	for(int i=1;i<=5001;i++){
		j[i]=i*j[i-1]%mod;
	}
	c=read();
	t=read();
	while(t--){
		int ans=0;
		memset(a,0,sizeof(a));
		memset(b1,0,sizeof(b1));
		memset(b2,1.00*0,sizeof(b2));
		int n,m;
		n=read();
		m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			//b1[i]=a[i];
			//b2[i]=a[i]/2;
		}
		cout<<qkp(2,n)<<endl;
	}
	return 0;
}

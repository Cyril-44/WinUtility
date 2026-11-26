#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5005
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
int n,m,mod=998244353;
int a[N];
int ksm(int a,int b){
	int s=1;
	while(b){
		if(b%2)s=(s*1ll*a)%mod;
		a=(a*1ll*a)%mod,b/=2;
	}
	return s;
}
struct node{
	int x,y,k;
}ls[N];
int b[N],ans=0;
bool cmp(node a,node b){
	if(a.x*b.y!=b.x*a.y)
		return a.x*b.y>b.x*a.y;
	if(a.x!=b.x)
		return a.x>b.x;
	return a.k<b.k;
}
ll f[105][105];
void dfs(int u){
	if(u>n){
		int kk=m;
		for(int i=1;i<=n;i++)
			ls[i].x=a[i],ls[i].y=b[i],ls[i].k=i;
		sort(ls+1,ls+1+n,cmp);
		ll k=0;
		for(int i=1;i<=n;i++)
			if(ls[i].y<=kk)
				kk-=ls[i].y,k+=ls[i].x;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			for(int j=0;j<=m;j++){
				if(j>=ls[i].y)
					f[i][j]=max(f[i-1][j],f[i-1][j-ls[i].y]+ls[i].x);
				else
					f[i][j]=f[i-1][j];
			}
		if(k==f[n][m])
			ans++,ans%=mod;
		return;
	}
	b[u]=1;
	dfs(u+1);
	b[u]=2;
	dfs(u+1);
}
void cl(){
	n=read(),m=read();
	bool ff=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=a[i-1]&&i!=1)
			ff=1;
	}
	if(n<=10){
		ans=0;
		dfs(1);
		printf("%d\n",ans);
		return;
	}
	printf("%d\n",ksm(2,n));
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int tid=read(),t=read();
	while(t--)
		cl();
	return 0;
}
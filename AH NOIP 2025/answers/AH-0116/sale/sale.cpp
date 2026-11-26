#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c,t;
long long n,m;
long long f[100][1010];
long long ans;
struct DATA{
  long long o,v=0;
  double g;
}a[10010];
bool cmp(DATA a,DATA b)
{
  return a.g>b.g;
}
int main()
{
  freopen("sale.in","r",stdin);
  freopen("sale.out","w",stdout);
  cin>>c>>t;
  while(t--)
  {
	 ans=0;
	cin>>n>>m;
	DATA  b[10010];
	for(int i=1;i<=1010;i++) 
	{
	b[i].o=b[i].v=0,b[i].g=0.0;
	a[i].o=a[i].v=0,a[i].g=0.0;
}
	for(int i=1;i<=n;i++)
	cin>>a[i].o;
	for(int i=0;i<1<<n;i++)
	{
	memset(f,0,sizeof f);
	for(int j=0;j<n;j++)
	{
	if(i>>j&1) a[j+1].g=a[j+1].o*1.0/2.0,a[j+1].v=2;
	else a[j+1].g=a[j+1].o*1.0,a[j+1].v=1;
	b[j+1].g=a[j+1].g;
	b[j+1].v=a[j+1].v;
	b[j+1].o=a[j+1].o;
}
   for(int u=1;u<=n;u++)
	{
	for(int v=1;v<=m;v++)
	{
		if(v>=a[u].v)f[u][v]=max(f[u-1][v],f[u-1][v-a[u].v]+a[u].o);
		else f[u][v]=f[u-1][v];
}
}
	sort(b+1,b+1+n,cmp);
	long long k=0,l=0;
	for(int j=1;j<=n;j++)
	  if(k+b[j].v<=m) k+=b[j].v,l+=b[j].o;
	if(l==f[n][m]) ans=ans%mod+1;
}
	cout<<ans<<endl;
  }
  return 0;
}

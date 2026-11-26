#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N],b[N],minl=2e9+10;
ll sum[N];
ll read()
{
	ll s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}

int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ll n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read();
		minl = min(minl,a[i]+b[i]);
	}
	sort(a+1,a+n+1);
	ll ans=m/minl*2;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		ans=max(ans,(m-sum[i])/minl*2+i);
	}
	cout<<ans;
	return 0;
}
//!noip@Nov29,2025:dream

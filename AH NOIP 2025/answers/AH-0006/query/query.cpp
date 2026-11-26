 #include<bits/stdc++.h>
using namespace std;
#define popcount(x) __builtin_popcount(x)
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=50005;
constexpr ll inf=1e18;
unsigned long long A;
ll ans[N],a[N],s[N];
int n,q;
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int l,r,u;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i],s[i]=a[i]+s[i-1];
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		for(int i=1;i<=n;++i)
		{
			ll mx=-inf;
			ans[i]=-inf;
			for(int j=r;j>=l;--j)
				if(i-j>=0)
				{
					mx=max(s[i]-s[i-j],mx);
					ans[i-j+1]=max(ans[i-j+1],mx);
				}
			for(int j=l-1;j>=0;--j)
				if(i-j>0)
					ans[i-j]=max(ans[i-j],mx);
		}
		A=0;
		for(int i=1;i<=n;++i)
			A^=(ull)ans[i]*i;//,cerr<<ans[i]<<'\n';
		cout<<A<<'\n';
	}
	return 0;
}

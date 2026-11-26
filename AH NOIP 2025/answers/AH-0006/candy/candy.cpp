 #include<bits/stdc++.h>
using namespace std;
#define popcount(x) __builtin_popcount(x)
typedef long long ll;
constexpr int N=500005;
constexpr ll mod=998244353;
ll x[N],y[N],m,p,ans;
int n;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	p=1LL<<50;
	for(int i=1;i<=n;++i)
		cin>>x[i]>>y[i],p=min(p,x[i]+y[i]);
	sort(x+1,x+1+n);
	ans=m/p*2;
	for(int i=1;i<=n&&m>=x[i];++i)
		m-=x[i],ans=max(ans,i+m/p*2);
	cout<<ans;
	return 0;
}

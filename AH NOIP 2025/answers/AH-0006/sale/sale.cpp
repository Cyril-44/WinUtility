 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=5005;
constexpr ll mod=998244353;
ll s[N],fac[N],inv[N],pw[N],a[N],b[N],ans;
int is[N],n,m,c;
ll C(const int n,const int m)
{
	if(n<0&&n==m)
		return 1;
	if(m<0||n<m)
		return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll f(const int n,const int m)
{
	if(m<n)
		return 0;
	if(m>2*n)
		return 0;
	return C(n,m-n);
}
bool check(int m)
{
	vector<ll>x{},y{},z{};
	int u=0,v=0;
	for(int i=1;i<=n;++i)
		if(is[i])
			x.push_back(a[i]);
		else
			y.push_back(a[i]);
	int yy=m;
	ll s1=0,s2=0;
	while(yy&&(u<x.size()||v<y.size()))
	{
		if(v>=y.size())
			s1+=x[u],++u,--yy;
		else if(u>=x.size())
		{
			if(yy<=1)
				break;
			else
				s1+=y[v],++v,yy-=2;
		}
		else if(x[u]*2>y[v]||yy==1)
			s1+=x[u],++u,--yy;
		else
			s1+=y[v],++v,yy-=2;
	}
	u=0,v=0;
	if(m&1)
	{
		if(!x.empty())
			s2+=x[0],u=1;
		--m;
	}
	m/=2;
	x.push_back(0);
	for(;u+1<x.size();u+=2)
		y.push_back(x[u]+x[u+1]);
	sort(y.begin(),y.end(),greater<>());
	for(int i=0;i<y.size()&&i<m;++i)
		s2+=y[i];
	//cerr<<s1<<' '<<s2<<'\n';
	return s1<s2;
}
void solve()
{
	cin>>n>>m,ans=pw[n];
	for(int i=1;i<=n;++i)
		cin>>a[i];
	a[0]=1LL<<52;
	sort(a+1,a+1+n,greater<>());
	if(n<=10)
	{
		for(int i=0;i<(1<<n);++i)
		{
			for(int j=1;j<=n;++j)
				is[j]=(i>>j-1)&1;
			if(check(m))
				--ans;
		}
	}
	else if(m==2*n-1||c==18)
	{
		
	}
	else
	{
		
	for(int i=1;i<=n;++i)
		b[i]=a[n+1-i];//,cerr<<a[i]<<' ';
	//cerr<<'\n';
	s[n+1]=1;
	for(int i=n;i>=1;--i)
		s[i]=pw[n-i]+s[i+1];
	int it=0;
	for(int i=1;i<=n;++i)
	{
		while(it<n&&a[it+1]>=2*a[i])
			++it;
		for(int j=it+1;j<i;++j)
			if(a[j]>a[i])
			{
				int k=lower_bound(b+1,b+1+n,a[j]-a[i])-b-1;
				int s=m-(j-1-it)-1-1;
				//cout<<i<<' '<<it<<' '<<j<<' '<<k<<' '<<s<<'\n';
				for(int u=0;u<=i-j-1&&u<=s;++u)
					ans=(ans-(pw[k]-1-k)*f(it,s-u)%mod*C(i-j-1,u))%mod;//,cout<<"*"<<ans<<'\n';
				//s=m-(j-1-it)-1-1-1;
				//for(int u=0;u<=i-j-1&&u<=s;++u)
				//	ans=(ans-k*f(j-1,s-u)%mod*C(i-j-1,u))%mod;
			}
		for(int j=1;j<i;++j)
			if(a[j]>a[i]&&a[j]<2*a[i])
			{
				int s=m-1-1;
				//cout<<"(((((("<<i<<','<<j<<":\n";
				for(int u=0;u<=i-j-1&&u<=s;++u)
					ans=(ans-f(j-1,s-u)%mod*C(i-j-1,u))%mod;//,cout<<"*"<<ans<<'\n';
			}
	}
	}
	
	cout<<(ans+mod)%mod<<'\n';
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	inv[0]=inv[1]=fac[0]=pw[0]=1;
	for(int i=2;i<=5000;++i)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=5000;++i)
		inv[i]=inv[i-1]*inv[i]%mod,fac[i]=fac[i-1]*i%mod,pw[i]=pw[i-1]*2%mod;
	int T;
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
}

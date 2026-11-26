#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long x[100005],y[100005];
long long ans;
int ii;
double minn=1e9*1.0;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	ii=n+1;x[ii]=1e18+1;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		double num=(x[i]+y[i])*1.0/2;
		if (num<minn || (num==minn && x[i]<x[ii]))
		{
			minn=num;
			ii=i;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (x[i]<minn || (x[i]==minn && x[i]<=x[ii]))
		{
			ans++;
			m-=x[i];
			//cout<<i<<'\n';
			//cout<<x[i]<<' '<<y[i]<<'\n';
		}
	}
	//cout<<'\n';
	//cout<<ans<<' '<<m<<'\n';
	//cout<<x[ii]<<' '<<y[ii]<<'\n';
	//cout<<ii<<'\n';
	//cout<<'\n';
	long long ss=m/(x[ii]+y[ii]);
	ans+=ss*2ll;
	m-=ss*(x[ii]+y[ii]);
	vector <long long> X;
	//if (m>x[ii] && x[ii]<=minn) ans++,m-=x[ii];
	for (int i=1;i<=n;i++)
	{
		if (!(x[i]<minn || (x[i]==minn && x[i]<x[ii])))
		{
			X.push_back(x[i]);
		}
	}
	sort(X.begin(),X.end());
	for (int x : X)
	{
		//cout<<x<<' '<<m<<'\n';
		if (x<=m) ans++,m-=x;
		else break;
	}
	cout<<ans;
	return 0;
}
/*
2 10
4 1
3 3
*/

#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N=1e5+5,MOD=0x3f3f3f3f;
int i,n,a[N],qz[N],Q,lj,rj,ans;
int qpow(int a,int n)
{
	int ans=1;
	while(n>1)
	{
		if(n%2==1)ans*=a,n--;
		if(n%2==0)ans*=ans,n/=2;
	}
	return ans;
}
signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n+1;i++)qz[i]=qz[i-1]+a[i-1];
	//for(i=1;i<=n+1;i++)cout<<qz[i]<<' ';
	cout<<endl;
	cin>>Q;
	while(Q--)
	{
		cin>>lj>>rj;
		if(lj==rj)
		{
			int ans=1;
			for(i=1;i<=n-lj+1;i++)ans^=((long long)(qz[i+lj]-qz[i])*i);
			cout<<ans<<endl;
		}
	}
	return 0;
}

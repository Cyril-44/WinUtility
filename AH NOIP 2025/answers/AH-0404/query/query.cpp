#include<bits/stdc++.h>
using namespace std;
long long n,a[50005],q,l,r,sum[50005],mx,k[50005],ans;
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		for (int i=1;i<=n;i++)
		{
			mx=-1e18;
			for (int j=l;j<=r;j++)
			{
				if (i+j-1>n)
				{
					break;
				}
				mx=max(mx,sum[i+j-1]-sum[i-1]);
			}
			k[i]=mx;
			ans=ans^(i*k[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[50006],q,l[1030],r[1030],le,sum[50006];
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=q;i++)
	{
		int ans=-1;
		for(int k=l[i];k<=r[i];k++)
		{
			for(int j=1;j<=n-k+1;j++)
			{
				ans=max(sum[j+k-1]-sum[j-1],ans);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


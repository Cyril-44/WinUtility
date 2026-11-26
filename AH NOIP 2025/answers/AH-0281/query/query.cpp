#include<bits/stdc++.h>
using namespace std;
int a[50005];
int l,r;
int qq(int m)
{
	int maxx=-100005;
	for(int t=l-1;t<=r-1;t++)
	{
		for(int i=m-t;i<=m;i++)
		{
			int sum=0;
			for(int j=i;j<=i+t;j++)
			{
				sum+=a[j];
			}
			maxx=max(maxx,sum);
		}
	}
	return maxx;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		auto ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=ans^(qq(i)*i);
			//cout<<qq(i)<<' '<<i<<endl;
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	} 
	return 0;
}

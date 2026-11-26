#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int m,n;
		cin>>n>>m;
		int a[100001],f=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			if(a[j]!=a[j-1])
			{
				f=1;
			}
		}
		int y=2;
		for(int j=2;j<=n;j++)
		{
			y*=2;
		}
		if(f==0)
		{
			cout<<y<<endl;
			continue;
		}
		else
		{
			cout<<y/2+2<<endl;
			continue;
		}
	}
	return 0;
}

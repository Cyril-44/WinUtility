#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[100005]={0};
		int num[100005]={0};
		memset(num,0,sizeof(num));
		for (int i=2;i<=n;i++)
		{
			cin>>a[i];
			num[a[i]]++;
		}
		if(m==1) 
		{
			cout<<n+1<<endl;
		}
		else
		{
			int ans=0,ma=0;
			for (int i=2;i<=n;i++)
			{
				ma=max(ma,num[i]);
				if(num[i]>0) ans++;
			}
		cout<<ma+ans+n+1<<endl;
		}
	}
	return 0;
	}

#include<bits/stdc++.h>
using namespace std;
long long int t,n,m,p[8009],d[8009],h,a[8009];
bool pan[8009],pan0[8009];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		n=m=0;
		cin>>n>>m;
		memset(p,0,sizeof(p));
		for(int i=1;i<=n-1;i++)
		{
			cin>>p[i];
			if(p[i]==p[i-1])  pan[i]=pan[i-1]=1;
		}
		d[1]=0;
		for(int i=2;i<=n;i++)
		{
			d[i]=d[p[i]]+1;
			h=max(h,d[i]);
		}
		cout<<2*n-1<<"\n";
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=8005;
vector <int> p[N];
int num[N];
int point_num[N];
int rot=1;
int ans=0;
int num_t[N];
void tr(int k)
{
	bool b=0;
	for(int i=0;i<=num[k]-1;i++)
	{
		if(num[p[k][i]]==0) num_t[k]=0;
		else b=1;
	}
	if(b==0)
	{
		for(int i=0;i<=num[k]-1;i++)
		{
			if(num[p[k][i]]==0) num_t[p[k][i]]=i;
		}
		num_t[k]=num[k];
		ans++;
		//ans+=num_t[k]+1;
		return ;
	}
	else
	{
		int maxn=0;
		for(int i=0;i<=num[k]-1;i++)
		{
			if(num[p[k][i]]==0) ans++;
			else
			{
				tr(p[k][i]);
			}
			maxn=max(num_t[p[k][i]],maxn);
		}
		num_t[k]=maxn+1;
		//ans+=num_t[k]+1;
	}
}
void tr1(int k)
{
	if(num[k]!=0)
	{
		ans+=(num_t[k]+1);
		for(int i=0;i<=num[k]-1;i++)
		{
			tr1(p[k][i]);
		}
	}
	else
		return ;
	
	//cout<<ans<<endl;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m;
		cin>>n>>m;
		for(int j=2;j<=n;j++)
		{
			int a;
			cin>>a;
			p[a].push_back(j);
			num[a]++;
			point_num[j]++;
		}
		if(m==1)
		{
			cout<<n+1<<endl;
			continue;
		}
		/*if(m==2)
		{
			cout<<n+1<<endl;
			continue;
		}*/
		for(int j=1;j<=n;j++)
		{
			if(point_num==0)
			{
				rot=i;
			}
		}
		tr(rot);
		tr1(rot);
		cout<<ans<<endl;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<num[k];k++)
			{
				p[j][k]=0;
			}
			num[j]=0;
			num_t[j]=0;
			point_num[j]=0;
			ans=0;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T;
int n,m;
int a[8010]={0};
int jd[8010]={0};
int jz[8010]={0};
vector<int> v[8010];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(v,0,sizeof(v));
		cin>>n>>m;
		for(int i=2;i<=n;i++)
		{
			cin>>a[i];
			v[a[i]].push_back(i);
		}
		for(int i=n;i>=1;i--)
		{
			int ansjd=1;
			for(int j=0;j<(int)v[i].size();j++)
			{
				ansjd+=jd[v[i][j]];
			}
			jd[i]=ansjd;
			for(int j=0;j<(int)v[i].size();j++)
			{
				ansjd=max(ansjd,jd[i]+jz[v[i][j]]);
			}
			jz[i]=ansjd;
		}
		for(int i=1;i<=n;i++)
		{
			cout<<jd[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<jz[i]<<" ";
		}
		cout<<endl;
		cout<<jz[1]<<endl;
	}
	return 0;
}

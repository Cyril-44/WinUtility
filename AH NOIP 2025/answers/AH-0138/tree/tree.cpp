#include<bits/stdc++.h>
using namespace std;
int T,n,m,father[8010],trees[8010],stage[8010],t,hmax,son[8010];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		int sum=0;
		father[1]=0;
		stage[1]=1;
		for(int i=2;i<=n;i++)
		{
			cin>>father[i];
			stage[i]=stage[father[i]]+1;
			son[father[i]]=1;
			hmax=max(hmax,stage[i]);
		}
		t=0;
		int t1=n+1;
		for(int i=n;i>=1;i--)
		{
			if(son[i]==0)
			{
				if(father[i]!=father[t1])
				{
					t=0;
					t1=i;
					sum++;
				}
				trees[i]=t;
				t++;
			}
			trees[father[i]]=max(trees[father[i]],trees[i]+1);
		}
		for(int i=n;i>=1;i--)
		{
			if(son[i]==1)
			{
				sum+=trees[i]+1;
			}
		}
		cout<<sum<<endl;
		hmax=0;
		for(int i=1;i<=n;i++)
		{
			stage[i]=0;
			trees[i]=0;
			son[i]=0;
			father[i]=0;
		}
	}
}

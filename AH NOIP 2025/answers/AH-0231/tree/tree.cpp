#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int u,w=0,d=0;
	vector<int> v;
}t[1000010];
void search(int u)
{
	int tn=t[u].v.size();
	for(int i=0;i<tn;i++)
		search(t[u].v[i]);
	if(t[u].v.size())
	{
		bool f=1;
		for(int i=0;i<tn;i++)
			if(t[t[u].v[i]].v.size()!=0)
				f=0;
		if(f)
			t[u].w=t[u].v.size();
		else
		{
			int maxt=0;
			for(int i=0;i<tn;i++)
				maxt=max(t[t[u].v[i]].w,maxt);
			t[u].w=maxt+1;
		}
	}
	return ;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			t[i].w=0;
			t[i].d=0;
			t[i].v.clear();
		}
		for(int i=2;i<=n;i++)
		{
			int x;
			cin>>x;
			t[x].v.push_back(i);
			t[i].u=x;
			t[i].d=t[x].d+1;
		}
		search(1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(t[i].v.size()!=0)
			{
				bool f=1;
				int tn=t[i].v.size();
				for(int j=0;j<tn;j++)
				{
					if(t[t[i].v[j]].v.size()==0)
					{
						f=0;
						break;
					}
				}
				if(f)
					ans+=t[i].w+1;
				else
					ans+=t[i].w+2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

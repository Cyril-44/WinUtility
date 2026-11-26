#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int fa[8080],bj[8080];
vector<int> lve[8080];
int t,n,m,root;

ll ret(int i,int depth)
{
	if(lve[i].size() == 0)
	{
		return 1;
	}
	int mx = -1;
	for(int j = 0;j < lve[i].size();j++)
	{
		mx = max(ret(lve[i][j],depth+1),mx);
	}
	return (max+m-depth);
}

ll ask(int i)
{
	ll ans = 0;
	if(lve[i].size() == 0) return 1;
	ans += ret(i,0);
	ans += 深度+leavesmax
	find...
	if have other children
	ans += ask(childi)
	return ans;
	
}


int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
	
	cin>>t;
	
	for(int i = 1;i <= t;i++)
	{
		cin>>n>>m;int f;
		memset(lve,0,sizeof(lve));
		for(int j = 1;j <= n;j++)
		{
			cin>>f;
			fa[j] = f;
			lve[f].push_back(j);
		}
		for(int j = 1;j <= n;j++)
		{
			if(fa[j] == 0)
			{
				root = j;
				break;
			}
		}
		cout<<ask(root);
	}
	
    return 0;
}

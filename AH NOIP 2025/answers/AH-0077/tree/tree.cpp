#include<bits/stdc++.h>
using namespace std;
int depth[8008],f[8008][8008],num[8008],ans=0;
vector<int> a[8008];
struct node
{
	int x,num;
}b[8008];
void dfs(int x,int fa)
{
	int tot=0;
	if(x!=1)
	depth[x]=depth[fa]+1;
	if(a[x].size()==1)
	{
		f[x][1]=0;
		f[x][0]=1;
		num[x]=1;
		ans+=depth[x]-2;
		return;
	}
	else
	{
        for(int i=0;i<a[x].size();i++)
        {
		    if(a[x][i]==fa)
		    continue;
		    dfs(a[x][i],x);
		    b[++tot].x=a[x][i];
		    b[tot].num=num[a[x][i]];
		}
		return;
	}
}
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
		for(int i=1;i<=n-1;i++)
		{
			int x;
			cin>>x;
			a[i+1].push_back(x);
			a[x].push_back(i+1);
		}
		dfs(1,0);
		cout<<ans+2*n<<endl;
    }
}

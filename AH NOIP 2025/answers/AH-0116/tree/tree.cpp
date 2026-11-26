#include <bits/stdc++.h>
using namespace std;
int t;
int n,h;
int p[100];
bool bo[10][100];
int maxn;
void dfs(int u)
{
  if(u<1)
  {
	  int ans=0;
	for(int i=n;i>=1;i--)
	 for(int j=0;j<6;j++)
	 if(bo[i][j]==1) bo[p[i]][j]=1;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=6;j++)
	if(bo[i][j]==0) 
	{
		ans+=j;
		break;
	}
	maxn=max(maxn,ans);
	return ;
  }
  for(int i=0;i<6;i++)
  {
   bo[u][i]=1;
   dfs(u-1);
   bo[u][i]=0;
   bo[p[u]][i]=0;
  }
  return ;
}
int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  cin>>t;
  while(t--)
  {
	memset(bo,0,sizeof bo);
	cin>>n>>h;
	p[1]=1;
	for(int i=2;i<=n;i++) cin>>p[i];
	maxn=INT_MIN;
    dfs(n+1);
    cout<<maxn<<endl;
  }
  return 0;
}

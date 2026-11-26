#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m;
struct DATA{
  int x,y;
  int tot;
}c[N];
int u=0;
long long ans=0;
bool cmp(DATA a,DATA b)
{
  return a.x<b.x;
}
int main()
{ 
  freopen("candy.in","r",stdin);
  freopen("candy.out","w",stdout);
  cin>>n>>m;
  c[u].tot=INT_MAX;
  for(int i=1;i<=n;i++)
  {
  cin>>c[i].x>>c[i].y;
  c[i].tot=c[i].x+c[i].y;
  if(c[u].tot>c[i].tot or (c[u].tot==c[i].tot and c[i].x<c[u].x))
   u=i;
}
  long long k=m,cnt=0;
  int x=c[u].x;
  int y=c[u].y;
  while(k>=0)
  {
  if(cnt%2==0) k-=x;
  else k-=y;
  cnt++;
}
  cnt--;
  ans=cnt;
  if(cnt%2==0) k+=x;
  else k+=y;
  sort(c+1,c+1+n,cmp);
  long long tp=cnt;
  cnt++;
  while(cnt--)
  {
	if(cnt!=tp)
	{
	if(cnt%2==0) k+=x;
    else k+=y;
}
    int i=1;
    while(k>=0 and i<=n)
    {
	if(c[i].x==x and c[i].y==y) 
	{i++;continue;}
    k-=c[i].x;
    i++;
	}
	i--;
  int flag=0;
	for(int j=1;j<=i;j++)
	{
		if(c[j].x==x and c[j].y==y) {flag=1;continue;}
	k+=c[j].x;
} 
    if(c[i].x==x and c[i].y==y) flag=0;
	ans=max(ans,cnt+i-1-flag);
  }
  cout<<ans;
  return 0;
}

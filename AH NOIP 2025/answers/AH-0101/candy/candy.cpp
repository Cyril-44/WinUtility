#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,m;
struct node{
	int x,y,id;//is the minf
}a[maxn];
bool cmp(node p,node q){return p.x<q.x;}
int sum=0,minf;
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].x>>a[i].y;
		if(i==1) sum=a[i].x+a[i].y,minf=1;
		else 
		{
			if(a[i].x+a[i].y<sum) sum=a[i].x+a[i].y,minf=i;
			else if(a[i].x+a[i].y==sum){if(a[i].x<a[minf].x) minf=i;} 
		}
	}
	a[minf].id=minf;
	int ans=0,flag=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) if(a[i].id==minf) {minf=i;break;}
	int i;
	for(i=1;i<=n;i++)
	{
		if(i==n) if(a[i].x>=a[minf].y) break;
		if(a[i].x+a[i+1].x>sum) break;
		if(i==minf) flag=1;
		m-=a[i].x,ans++;
	}
	if(flag){
		if(m<a[minf].y){cout<<ans;return 0;}
		m-=a[minf].y,ans++;
	}
	ans+=m/sum*2,m%=sum;
	int now=min(a[minf].x,a[i].x);
	if(m>=now) ans++;
	cout<<ans;
	return 0;
}

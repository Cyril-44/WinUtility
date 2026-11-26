#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
inline ll in(){
	ll x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
ll n,m,ans,mn=1e18,pos,w,xx,yy,dp[10005];
bool flag;
struct node{ll x,y,id;}a[N];
bool cmp(node a,node b){return a.x<b.x;}
priority_queue<int,vector<int>,greater<int > >q;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n=in(),m=in();
	if (m<=10000){
		memset(dp,-1,sizeof dp);dp[0]=0;
		for (int i=1;i<=n;i++){
			ll x=in(),y=in();
			for (int j=0;j<=m;j++){
				if (dp[j]==-1)continue;
				if (j+x+y<=m)dp[j+x+y]=max(dp[j]+2,dp[j+x+y]);
			}
			for (int j=m;j>=0;j--){
				if (dp[j]==-1)continue;
				if (j+x<=m)dp[j+x]=max(dp[j]+1,dp[j+x]);
			}
		}
		for (int i=0;i<=m;i++)ans=max(ans,dp[i]);
	}
	else {
		for (int i=1;i<=n;i++){
			ll x=in(),y=in();
			a[i].x=x;a[i].y=y;a[i].id=i;
			if (x+y<mn){
				pos=i;mn=x+y;xx=x;yy=y;
			}
		}
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=n;i++){
			if (a[i].x*2<mn){
				if (a[i].id==pos)q.push(a[i].x);
				else ans++,m-=a[i].x;
			}
			else {w=i;break;}
		}
		ans+=m/mn*2;m%=mn;
		for (int i=w;i<=n;i++)q.push(a[i].x);
		while (!q.empty()){
			int x=q.top();q.pop();
			if (m>=x)m-=x,ans++;
			else break;
		}
	}
	printf ("%lld",ans);
	return 0;
}

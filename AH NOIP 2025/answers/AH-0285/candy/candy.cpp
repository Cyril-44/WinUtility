#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y;
}a[100009];
bool cmp(node l,node r){
	return l.x<r.x;
}
long long n,m,i,dp[100009],ct,cut,ans,sum;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i].x>>a[i].y,ct=a[i].x+a[i].y;
	sort(a+1,a+n+1,cmp);
	dp[0]=0;
	for(i=1;i<=n;i++)dp[i]=dp[i-1]+a[i].x;
	for(i=1;i<=n;i++)ans+=(dp[i]/ct*i*2);
	cout<<ans;
	return 0;
}

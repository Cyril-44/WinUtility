#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
struct node{
	int b,k,id,id1;
}s[105];
bool cmp(node a,node b){
	if(a.b!=b.b)return a.b>b.b;
	if(a.k!=b.k)return a.k>b.k;
	return a.id<b.id;
}
bool cmp1(node a,node b){
	return a.id1<b.id1;
}
long long dp[105];
int n,mo;
int c,T;
long long ans=0;
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++)s[i].id1=i;
		sort(s+1,s+n+1,cmp);
		memset(dp,0,sizeof(dp));
		int m=mo;
		long long sum=0,s1=0;
		for(int i=1;i<=n;i++){
			if(m>=s[i].k)m-=s[i].k,sum+=s[i].b*s[i].k;
		}
		m=mo;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=s[i].k;j--){
				dp[j]=max(dp[j],dp[j-s[i].k]+s[i].b*s[i].k);
				s1=max(s1,dp[j]);
			}
		}
		sort(s+1,s+n+1,cmp1);
		if(s1==sum)ans++;
		return;
	}
	s[x].b=a[x],s[x].k=1;
	dfs(x+1);
	s[x].b=a[x]>>1,s[x].k=2;
	dfs(x+1);
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>mo;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]<<=1;
			s[i].id=i;
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}

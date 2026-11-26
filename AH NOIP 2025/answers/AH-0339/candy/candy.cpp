#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node{
	int a,b;
}c[1000005];
int cnt[1000005];
long long m;
long long ans=0;
int minn=2e9;
long long sum=0;
bool cmp(node p,node q){
	return p.a<q.a;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&c[i].a,&c[i].b);
		minn=min(minn,c[i].a+c[i].b);
	}
	sort(c+1,c+n+1,cmp);
	ans=m/minn*2;
	for(int i=1;i<=n;i++){
		if(c[i].a<=m){
			m-=c[i].a;
			ans=max(ans,i+m/minn*2);
		}
	}
	printf("%lld",ans);
	return 0;
}

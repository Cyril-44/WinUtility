#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rp(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n,mx2=2e9;long long m,ans;
priority_queue<int,vector<int>,greater<int> >q;
priority_queue<int>qq;
int main() {
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	fr(i,1,n) {
		int x,y;scanf("%d%d",&x,&y);
		mx2=min(mx2,x+y);q.push(x);
	}
	while(!q.empty()&&q.top()*2<mx2&&q.top()<=m) ++ans,qq.push(q.top()),m-=q.top(),q.pop();
	long long h=(m/mx2);ans+=h*2;
	m-=mx2*1ll*h;
	if(!qq.empty()) {
		int x=qq.top();
		if(m+x>=mx2) ++ans,q.push(x),m+=x,m-=mx2;
	}
	while(!q.empty()&&q.top()<=m) m-=q.top(),q.pop(),++ans;
	printf("%lld\n",ans);
	return 0;
}
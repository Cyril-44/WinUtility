#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=8000+100;
ll n,m;
ll fa[maxn];
ll head[maxn],to[2*maxn],nxt[2*maxn],cnt_edge;
void add(ll u,ll v) {
	to[++cnt_edge]=v;
	nxt[cnt_edge]=head[u];
	head[u]=cnt_edge;
}
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while (T--) {
		cin>>n>>m;
		cnt_edge=0;
		memset(head,0,sizeof(head));
		for (int i=2; i<=n; i++) {
			ll x; cin>>x;
			fa[i]=x, add(i,x), add(x,i);
		}
		if (m==2) {
			ll ans=0, Max=0;
			for (int i=head[1]; i; i=nxt[i]) {
				ll v=to[i];
				ll sum=-1;
				for (int j=head[v]; j; j=nxt[j])
					sum++;
				Max=max(Max, sum+1);
				ans+=sum+1;
				if (sum) ans++;
			}
			ans+=Max+1;
			cout<<ans<<"\n";
		}
	}
	return 0;
}

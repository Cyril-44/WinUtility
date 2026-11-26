#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+100;
ll n,m;
struct node {
	ll p,id;
}w[2*maxn];
bool cmp(node a,node b) {
	return a.p<b.p;
}
int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll cnt_w=0;
	m*=2;
	for (int i=1; i<=n; i++) {
		ll x,y; cin>>x>>y;
		x*=2, y*=2;
		w[++cnt_w].id=1, w[cnt_w].p=x;
		w[++cnt_w].id=2, w[cnt_w].p=(x+y)/2;
	}
	sort(w+1,w+cnt_w+1,cmp);
	ll End1=-1, ans=0;
	for (int i=1; i<=cnt_w; i++) {
		if (w[i].id==1) {
			if (w[i].p>m) break;
			End1=w[i].p;
			m-=w[i].p;
			ans++;
		}
		if (w[i].id==2)  
			while (1) {
				if (w[i].p*2>m) {
					if (End1==-1) break;
					if (w[i].p*2<=m+End1) 
						End1=-1, m=m+End1-w[i].p*2, ans++;
					else break;
				}
				else 
					m-=w[i].p*2, ans+=2;
			}
	}
	cout<<ans;
	return 0;
}

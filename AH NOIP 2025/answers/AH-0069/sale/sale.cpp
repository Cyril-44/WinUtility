#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5000+100;
const ll mod=998244353;
ll n,m,ans;
ll a[maxn],w[maxn];
ll ksm(ll a,ll k) {
	ll res=1;
	while (k) {
		if (k%2==1) res=(res*a)%mod;
		a=(a*a)%mod;
		k/=2; 
	}
	return res;
}


struct node {
	ll w,a;
}tmp[maxn];
bool cmp1(node x,node y) {
	if (x.a*y.w==y.a*x.w) return x.a>y.a;
	return x.a*y.w>y.a*x.w;
}
bool cmp2(node x,node y) {
	return x.a>y.a;
}
priority_queue <ll, vector<ll>, greater<ll> > q1,Clear1;
priority_queue <ll> q2,Clear2;
void work() {
	for (int i=1; i<=n; i++) 
		tmp[i].a=a[i], tmp[i].w=w[i];
	sort(tmp+1,tmp+n+1,cmp1);
	ll sum1=0, cost=m;
	for (int i=1; i<=n; i++) 
		if (cost>=tmp[i].w) {
			cost-=tmp[i].w;
			sum1+=tmp[i].a;
		}
	cost=m;
	sort(tmp+1,tmp+n+1,cmp2);
	ll sum2=0;
	q1=Clear1;
	q2=Clear2;
	for (int i=1; i<=n; i++) {
		if (tmp[i].w<=cost) {
			cost-=tmp[i].w;
			sum2+=tmp[i].a;
			if (tmp[i].w==2) 
				q1.push(tmp[i].a);
		}
		else if (tmp[i].w==1)
			q2.push(tmp[i].a);
	}
	while (!q1.empty()&&q2.size()>=2) {
		ll x,y;
		x=q1.top(); q1.pop();
		y=q2.top(); q2.pop();
		y+=q2.top(); q2.pop();
		if (x<y) sum2+=y-x;
		else break;
 	}
 	if (sum1>=sum2) 
		ans++;
}
void dfs(ll k) {
	if (k>n) {
		work();
		return ;
	}
	w[k]=1;
	dfs(k+1);
	w[k]=2;
	dfs(k+1);
}

bool cmp3(ll a,ll b){
	return a>b;
}
ll Find(ll x) {
	ll l=2, r=n, mid;
	x--;
	while (l<=r) {
		mid=(l+r)/2;
		if (a[mid]<=x) r=mid-1;
		else l=mid+1;
	}
	return r+1;
}
int main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll cnt_T, T;
	cin>>cnt_T>>T;
	while (T--) {
		cin>>n>>m;
		for (int i=1; i<=n; i++) 
			cin>>a[i];
		ans=0;
		if (1<=cnt_T && cnt_T<=5) {
			dfs(1);
			cout<<ans<<"\n";
			continue;
		}
		if (cnt_T==18) {
			cout<<ksm(2,n)<<'\n';
			continue;
		}
		if ((7<=cnt_T&&cnt_T<=9)||cnt_T==14||cnt_T==15) {
			sort(a+1,a+n+1,cmp3);
			ll sum=ksm(2,n);
			for (int i=2; i<=n; i++) {
				if (a[i]*2<=a[1]) break;
				ll k=Find(a[1]-a[i]);
				sum-=ksm(2,n-k+1);
				sum=((sum%mod)+mod)%mod;
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}

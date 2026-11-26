#include<bits/stdc++.h>
#define int long long
using namespace std;
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
const int N=1e5+10;
int n,m,ans,tott,cnt;
#define PII pair<int,int>
PII a[N];
#define fi first
#define se second
bool cmp(PII aa,PII bb){
	return aa.fi+aa.se<bb.fi+bb.se;
}
priority_queue<int,vector<int>,greater<int> > hp;
signed main(){
	ios::sync_with_stdio(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	forr(i,1,n)cin>>a[i].fi>>a[i].se;
	sort(a+1,a+1+n,cmp);
	forr(i,1,n){
		hp.push(a[i].fi);
	}
	int cts=a[1].fi+a[1].se;
	tott=2*(m/cts);
	cnt=tott/2;
	m-=m/cts*cts;
	ans=tott;
	while(!hp.empty()){
		while(!hp.empty()&&m>=hp.top()){
			tott++;ans=max(ans,tott);
			m-=hp.top();
			hp.pop();
		}
		if(hp.empty())break;
		int del=hp.top()-m;
		int ss=(del-1)/cts+1;
		if(ss>cnt)break;
		cnt-=ss;
		tott-=2*ss;
		m+=ss*cts;
	}
	cout<<ans;
	return 0;
}

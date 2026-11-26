#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
struct node{
	int x,y;
}a[100005];
bool cmp(node x,node y){
	if(x.x!=y.x) return x.x<y.x;
	else return x.y<y.y;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	int s=0x3f3f3f3f3f3f3f3f,p,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		s=min(s,a[i].x+a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	int pp=0;
	for(int i=1;i<=n;i++){
		//cerr<<a[i].x<<' '<<a[i].y<<'\n';
		if(2*a[i].x>s||m<a[i].x) break;
		m-=a[i].x;ans++;pp=i;
	}
	cerr<<s<<'\n';
	cerr<<m<<'\n';
	ans+=2*(m/s);
	m%=s;
	cerr<<m<<' '<<ans<<'\n';
	for(int i=1;i<=n;i++){
		int v=((i<=pp)?a[i].y:a[i].x);
		if(v<=m) m-=v,ans++;
	}
	cout<<ans;
	return 0;
}

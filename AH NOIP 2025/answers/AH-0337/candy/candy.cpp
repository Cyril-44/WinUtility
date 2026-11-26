#include <bits/stdc++.h>
using namespace std;

struct node{
	long long x,y,rt;
}a[200005];
bool cmp(node x,node y){
	return x.x<y.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	for(int i=1;i<=n;i++) a[i].rt=a[i].x+a[i].y;
	long long p=1e18;
	for(int i=1;i<=n;i++) p=min(p,a[i].rt);
	long long ans=m/p*2,sum=0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum+=a[i].x;
		ans=max(ans,(m-sum)/p*2+i);
	}
	cout<<ans<<endl;
	return 0;
}

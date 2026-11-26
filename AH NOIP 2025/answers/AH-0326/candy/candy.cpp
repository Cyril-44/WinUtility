#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+5;
struct node{
	LL x,y;
}a[N];
LL n,m;
LL cnt,ans;
bool cmp(node p,node q){
	return p.x+p.y<q.x+q.y;
}
bool cmp2(node p,node q){
	return p.x<q.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	stable_sort(a+1,a+n+1,cmp);
	LL op=a[1].x+a[1].y;
	ans=(m/op)*2ll;
	stable_sort(a+1,a+n+1,cmp2);
	for(LL i=1;i<=n;i++){
		if(m>=a[i].x){
			cnt++;
			m-=a[i].x;
			ans=max(ans,cnt+(m/op)*2ll);
		}else{
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

//long long  freopen 多测
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
int n,m,cst;
struct node{
	int x,y;
}a[N];
bool cmp1(node a,node b){return a.x+a.y<b.x+b.y;}
bool cmp2(node a,node b){return a.x<b.x;}
signed main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	sort(a+1,a+1+n,cmp1);cst=a[1].x+a[1].y;
	int ans=m/cst*2;
	sort(a+1,a+1+n,cmp2);
	for(int i=1,tot=0;i<=n;i++){
		tot+=a[i].x;
		if(tot>m){break;}
		ans=max(ans,i+(m-tot)/cst*2);
	}
	cout<<ans;
	return 0;
}

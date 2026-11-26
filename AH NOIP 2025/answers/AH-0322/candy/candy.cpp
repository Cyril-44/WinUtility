#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{int x,y;}a[1000005];
int n,m,ans=3e18,ans1,s;
bool cmp(node a,node b){return a.x<b.x;}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y,ans=min(ans,a[i].x+a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<=n;i++){
		s+=a[i].x;
		if(m>=s){
			int u=m-s;
			ans1=max(ans1,i+u/ans*2);
		}
	}
	cout<<ans1;
    return 0;
}
//8:42

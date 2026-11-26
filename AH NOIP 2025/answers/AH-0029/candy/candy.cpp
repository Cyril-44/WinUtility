#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=100010;
ll n,m,mn,ans,sum[maxn];
struct node{
	ll x,y;
}a[maxn];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	mn=1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		mn=min(mn,a[i].x+a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i].x;
	}
	for(int i=0;i<=n;i++){
		if(sum[i]>m){
			break;
		}
		ans=max(ans,i+((m-sum[i])/mn)*2);
	}
	cout<<ans<<endl;
	return 0;
}	

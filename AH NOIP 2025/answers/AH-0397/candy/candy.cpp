#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,m,cnt;
struct node{
    ll x,y;
}a[N];
bool cmp(node a,node b){
    return a.x<b.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	ll minn=2e9;
	for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        minn=min(minn,a[i].x+a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	ll sum=0,cnt=0,maxn=m/minn*2;
	for(int i=1;i<=n;i++){
        if(sum>=m)break;
        sum+=a[i].x;
        cnt++;
        maxn=max(maxn,(m-sum)/minn*2+cnt);
	}
	cout<<maxn;
	return 0;
}

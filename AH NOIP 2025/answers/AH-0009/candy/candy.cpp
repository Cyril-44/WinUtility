#include <bits/stdc++.h>
#define ll long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+5;
int n;ll m;
ll ans,res,tmp;

struct candy{
    ll x,y;
    bool operator<(candy g)const{return x<g.x;}
}a[N];

int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    up(i,1,n) cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1);
    ll minn=1e18;
    up(i,1,n) minn=min(minn,a[i].x+a[i].y);
    res=(m/minn)*2,ans=res;
    tmp=m-res/2*minn;
    ll cnt=res;
    up(i,1,n){
        while (cnt>=2&&tmp<a[i].x){
            cnt-=2,res-=2;
            tmp+=minn;
        }
        if (tmp>=a[i].x) res++,tmp-=a[i].x;
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}

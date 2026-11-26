#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

struct Candys{
    ll odd,even;
    bool operator<(const Candys other)const{
        return odd<other.odd;
    }
}candy[maxn];

ll n,m;
ll minprice;
ll presum[maxn];

void init(){
    cin>>n>>m;
    minprice=1e10;
    for(int i=1;i<=n;i++){
        cin>>candy[i].odd>>candy[i].even;
        minprice=min(candy[i].odd+candy[i].even,minprice);
    }
    sort(candy+1,candy+1+n);
    for(int i=1;i<=n;i++){
        presum[i]=presum[i-1]+candy[i].odd;
    }
}

ll find(ll v){
    int l=1;
    int r=n;
    int mid;
    while(l<r){
        mid=(l+r)/2;
        if(v>presum[mid]) l=mid+1;
        else r=mid;
    }
    if(presum[l]==v) return l;
    else return l-1;
}

ll ff(ll a){
    return min(a,n);
}

ll check(ll a,ll v){
    return (find(a*minprice+v)-a*2);
}

ll ansfind(ll v){
    ll l=1;
    ll r=n/2;
    ll mid1=l,mid2=r;
    while(l<r){
        int res1=check(mid1,v);
        int res2=check(mid2,v);
        if(res1>res2) r=mid2-1;
        if(res1==res2) l=mid1,r=mid2;
        if(res1<res2) l=mid1+1;
        mid1=(2*l+r)/3;
        mid2=(l+2*r)/3;
    }
    return max(check(l,v),max(check(1,v),check(n/2,v)));
}

ll f(ll a){
    ll t=0;
    return max(a,t);
}

int main(){
    init();
    ll ans=0;
    ans+=2*(m/minprice);
    m%=minprice;
    ans+=max(find(m),ansfind(m));
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,pos;
struct node
{
    ll x,y;
}a[100005];
ll m,minn=1e18;
multiset<pair<ll,ll> > s;
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld %lld",&a[i].x,&a[i].y);
        if(a[i].x+a[i].y<=minn)
        {
            minn=a[i].x+a[i].y;
            pos=i;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(i!=pos) s.insert(make_pair(a[i].x,a[i].y));
    }
    ll ans=m/(a[pos].x+a[pos].y)*2,sum=ans,T=sum;
    m%=(a[pos].x+a[pos].y);
    //printf("%lld %lld\n",sum,m);
    for(ll i=1;i<=T+1;++i)
    {
        ll it1=(*s.begin()).first,it2=(*s.begin()).second;
        //if(it1>m) break;
        while(it1<=m)
        {
            m-=it1;
            ++sum;
            s.erase(s.begin());
            //printf("%lld %lld\n",it1,it2);
            s.insert(make_pair(it2,it1));
            it1=(*s.begin()).first,it2=(*s.begin()).second;
        }
        //printf("%d %lld %lld\n",i,m,sum);
        if((i&1ll)&&(sum<ans)&&(i>1e6)) break;
        ans=max(ans,sum);
        if(i&1) m+=a[pos].y;
        else m+=a[pos].x;
        --sum;
    }
    printf("%lld\n",ans);
    return 0;
}

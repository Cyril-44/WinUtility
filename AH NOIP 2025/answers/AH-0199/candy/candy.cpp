#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll money,ans;
struct cost
{
    ll x;
    ll y;
    ll a;
};
ll cmp(struct cost A,struct cost B)
{
    return A.a<B.a;
}
ll _cmp(struct cost A,struct cost B)
{
    return A.x<B.x;
}
inline void pay(ll a,ll m)
{
    int i;
    for(i=0;money+a<=m;i++)
        money=money+a;
    ans=i*2;
}
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ll n,m,i;
    cin>>n>>m;
    struct cost candy[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>candy[i].x>>candy[i].y;
        candy[i].a=candy[i].x+candy[i].y;
    }
    sort(candy+1,candy+n+1,cmp);
    pay(candy[1].a,m);
    if(money!=m)
    {
        sort(candy+1,candy+n+1,_cmp);
        for(i=1;money+candy[i].x<=m;i++)
        {
            money=money+candy[i].x;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

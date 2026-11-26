#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
ll n,m,b[N],cnt,ta=1,tb=1,ans;
struct in
{
    ll x,y,d;
}a[N];
bool cnm(in u,in v)
{
    return u.d<v.d;
}
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        a[i].d=(a[i].x+a[i].y);
    }
    sort(a+1,a+n+1,cnm);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i].x;
    }
    sort(b+1,b+n+1);
    ll fl=0;
    //for(int i=1;i<=n;i++)cout<<a[i].d<<" "<<b[i]<<"\n";
    while(1)
    {
        //cout<<m<<" ";
        if(fl)
        {
            if(tb<=n&&m>=b[tb])
            {
                m-=b[tb];
                tb++;
                ans++;
            }
            else
            {
                if(b[tb-1]+m>=a[1].d)ans++;
                cout<<ans;
                return 0;
            }
        }
        else if(b[tb]*2<a[1].d)
        {
            ans++;
            m-=b[tb];
            tb++;
        }
        else
        {
            ans+=m/a[1].d*2;
            m=m%a[1].d;
            fl=1;
        }
    }
    cout<<ans;
    return 0;
}

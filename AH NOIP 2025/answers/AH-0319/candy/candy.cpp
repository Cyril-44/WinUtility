#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
const int N=1e5+10;
int n,a[N],b[N];
ll pre[N];
ll m,tmp,ans,smin=inf;
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        smin=min(smin,1ll*a[i]+b[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    for(int i=0;i<=n;i++)
        ans=max(ans,(m-pre[i])/smin*2+i);
    cout<<ans<<"\n";
    return 0;
}

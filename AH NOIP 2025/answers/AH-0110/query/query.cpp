#include<bits/stdc++.h>
#define int long long
#define ll unsigned long long
using namespace std;
const int N=5e4+114;
int f[N][20],sum[N],a[N],w[N],n,m;
void build(int len){
    for(int i=1;i<len;i++) f[i][0]=-1e18;
    for(int i=len;i<=n;i++) f[i][0]=sum[i]-sum[i-len];
    for(int k=1;(1<<k)<=n;k++)
        for(int i=1;i<=n;i++)
            f[i][k]=max(f[i][k-1],f[i+(1<<k-1)][k-1]);
}
int query(int l,int r)
{
    int k=log2(r-l+1);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
void init(){
    for(int i=1;i<=n;i++) w[i]=-1e18;
}
signed main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    cin>>m;
    while(m--)
    {
        init();
        int l,r;cin>>l>>r;
        for(int len=l;len<=r;len++)
        {
            build(len);
            for(int i=1;i+len-1<=n;i++) w[i]=max(w[i],query(i,i+len-1));
        }
        for(int i=1;i<=n;i++) cout<<w[i]<<' ';
        cout<<'\n';
        ll ans;
        for(int i=1;i<=n;i++) ans^=(ll)(i*w[i]);
        cout<<ans<<'\n';
    }
    return 0;
}

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define inf 1e18
using namespace std;
const int N=3010;
int n,m,a[N];
ll pre[N];
ll res[N][N];
int hd,tl,q[N];

int main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],pre[i]=pre[i-1]+a[i];
    for(int k=1;k<=n;k++)
    {
        hd=1,tl=0;
        for(int i=1;i<=n;i++)
        {
            while(hd<=tl&&q[hd]<i-k+1)hd++;
            if(i+k-1<=n)
            {
                ll cur=pre[i+k-1]-pre[i-1];
                while(hd<=tl&&(pre[q[tl]+k-1]-pre[q[tl]-1])<cur)tl--;
                q[++tl]=i;
            }
           res[k][i]=pre[q[hd]+k-1]-pre[q[hd]-1];
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        ull ans=0;
        for(int j=1;j<=n;j++)
        {
            ll smax=-inf;
            for(int k=l;k<=r;k++)smax=max(smax,res[k][j]);
            ans^=(1ull*smax*j);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

// 暴力 二维
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int maxn = 1e3+5;
const int maxm = 1e4+5;
ll n,m;
ll a[maxn][3];
ll f[maxn][maxm];
int main ()
{
    freopen ("candy.in","r",stdin);
    freopen ("candy.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i][1]; //奇数
        cin>>a[i][2];
    }
    if (n<=maxn)
    {
for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (j<a[i][1]) f[i][j]=f[i-1][j];
            else{
                for (int k=1;k<=1e5+5;k++)
                {
                    ll sum=0;
                    sum = (k/2)*(a[i][1]+a[i][2])+(k%2)*a[i][1];
                    if (j>=sum) 
                    {
                        if (k==1)
                        f[i][j]=max(f[i-1][j],f[i-1][j-sum]+k);
                        f[i][j]=max(f[i][j],f[i-1][j-sum]+k);
                    }
                    else 
                        break;
                }
            }
        }
    }
    cout<<f[n][m];
    }
    else
    {
        ll ans=1000000009;
        for (int i=1;i<=n;i++)
        {
            ans=min(ans,a[i][1]);
        }
        cout<<m/ans;
    }
    
    return 0;
}
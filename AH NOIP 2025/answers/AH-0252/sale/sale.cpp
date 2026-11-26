#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[5000];
int ccf(int x)
{
    int ans=1;
    for(int i=1;i<=x;i++)
    {
        ans*=2;
        ans%=998244353;
    }
    return ans;
}
int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    }
    cout<<ccf(m-n);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,a[50005]={0},q;
int main(void)
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        long long l,r,ans=a[i];
        cin>>l>>r;
        for(int j=2;j<=n;j++)
        {
            ans=ans^(i*a[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}

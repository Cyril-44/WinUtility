#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int ans=0,c;
        for(int i=1;i<=n-1;i++) cin>>c;
        for(int i=1;i<=n-1;i++)
            ans+=i;
        cout<<ans<<'\n';
    }
    return 0;
}

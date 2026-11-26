#include<bits/stdc++.h>
#define int long long
using namespace std;
int t[200005];
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    int n,m,minn=1e18,b,ans=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i]>>b;
        minn=min(minn,t[i]+b);
    }
    sort(t+1,t+1+n);
    for(int i=0;i<=n;i++)
    {
        if(m<t[i]) break;
        if(t[i+1]*2>minn){
            ans++;
            m-=t[i];
            int x=m/minn;
            ans+=x*2;
            m=m-x*minn;
            if(m>t[i+1]) ans++;
            else if(m+t[i]>minn) ans++;
            break;
        }
        ans++;
        m-=t[i];
    }
    cout<<ans<<endl;
    return 0;
}

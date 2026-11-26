#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+114;
int n,m,ans,sum,x[N],t=1e18,p,res=-1;
signed main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int y;
        cin>>x[i]>>y;
        t=min(t,x[i]+y);
    }
    sort(x+1,x+1+n);
    int p=n;
    while(x[p]>=t) --p;
    for(int i=1;i<=p;i++) sum+=x[i];
    m-=sum;
    ans=p+(m/t)*2;
    m-=(m/t)*t;
    int i=p;
    while(i>=2&&x[i]+x[i-1]>t) res=max(res,ans+m/t*2+(m-m/t*t+x[i]>=t)),m+=x[i]+x[i-1]-t,i-=2;
    if(i>=1) res=max(res,ans+m/t*2+(m-m/t*t+x[i]>=t));
    cout<<res;
    return 0;
}

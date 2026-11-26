#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,zu,a[100005],ans,i,t,x1,y2,k,t1,t2;
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m>>x>>y;
    zu=x+y;a[1]=x;x1=x;y2=y;
    for(i=2;i<=n;i++)
    {
        cin>>x>>y;
        if((zu==x+y&&y<y2)||zu>x+y)
        {
            zu=x+y;
            x1=x;y2=y;
        }
        a[i]=x;
    }
    sort(a+1,a+1+n);
    t=m/zu;
    m-=t*zu;
    ans+=t*2;
    for(i=1;i<=n;i++)
    {
        if(m<a[i]) break;
        m-=a[i]; ans++;
    }
    for(;i<=n;i+=2)
    {
        if(a[i]+a[i+1]>=zu||t==0) break;
        t--; m=m+zu-a[i]-a[i+1];
    }
    t=min(a[i],x1);
    if(x1<=a[i-1])
    {
        k=1;t=min(a[i],y2);
    }
    if(m<t)
    {
        cout<<ans;
        return 0;
    }
    if(m>=zu)
    {
        if(k==0)
        {
            m-=x1;ans++;
        }
        while(m)
        {
            if(m<y2) break;
            m-=y2;ans++;
            if(m<x1) break;
            m-=x1;ans++;
        }
        cout<<ans;
        return 0;
    }
    cout<<ans+1;
    return 0;
}
//Bye

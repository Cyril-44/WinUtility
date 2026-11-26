#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int p[10005],h[10005],maxc=-1,t[10005],d[10005];
int pp[10005],s[10005],o=0,ans;
int ff(int x)
{
    int y=0;
    while(x)
    {
        x=p[x];
        y++;
    }
    return y;
}
void fff(int x)
{
    while(x)
    {
        t[p[x]]=max(t[x]+1,t[p[x]]);
        x=p[x];
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree,out","w",stdout);
    cin>>T;
    while(T--)
    {
        o=0;
        memset(s,0,sizeof(s));
        cin>>n>>m;
        for(int i=2;i<=n;i++)
        {
            cin>>p[i];
            pp[i]=p[i];
            d[p[i]]++;
        }
        pp[1]=p[1]=0;
        for(int i=1;i<=n;i++)
        {
            h[i]=ff(i);
            maxc=max(maxc,h[i]);
        }
        sort(pp+1,pp+n+1);
        for(int i=1;i<=n;i++)
        {
            if(d[i]==0)
            {
                t[p[i]]=upper_bound(pp+1,pp+n+1,p[i])-lower_bound(pp+1,pp+n+1,p[i]);
                s[p[i]]=1;
            }
        }
        //cout<<o<<' ';
        for(int i=1;i<=n;i++)
        {
            if(s[i]==1)
            {
                fff(i);
                o++;
            }
        }
        ans=o;
        for(int i=1;i<=n;i++)
        {
            if(t[i]!=0)ans+=t[i]+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,i,j,o,n,m,fa[8001],zi[8001][8001],zinum[8001],a[8001],ii[8001];
long long ans;
long long zhao(int p)
{
    if(zinum[p]==0)
    {
        int father=fa[p],q=0;
        for(int k=1;k<=zinum[father];k++)
        {
            if(zinum[zi[father][k]]==0) q++;
        }
        if(q==zinum[father])
        {
            for(int k=1;k<=zinum[father];k++)
            {
                if(zi[father][k]==p) return a[p]=k-1;
            }
        }
        else
        {
            return a[p]=0;
        }
    }
    else
    {
        for(ii[p]=1;ii[p]<=zinum[p];ii[p]++)
        {
            zhao(zi[p][ii[p]]);
            a[p]=max(a[p],a[zi[p][ii[p]]]);
        }
        a[p]++;
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    for(o=1;o<=t;o++)
    {
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            zinum[i]=0;
            a[i]=0;
        }
        for(i=2;i<=n;i++)
        {
            cin>>fa[i];
            zinum[fa[i]]++;
            zi[fa[i]][zinum[fa[i]]]=i;
        }
        zhao(1);
        ans=0;
        for(i=1;i<=n;i++)
        {
            if(zinum[i]==0)
            {
                if(a[i]==0) ans++;
            }
            else
            {
                ans+=a[i];
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

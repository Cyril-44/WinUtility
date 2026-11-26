#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[8005];
int cn[8005],sz[8005];
bool iss[8005];
int a[8005];
int maxx;
vector<int> g[8005];
void dfs(int x)
{
    if(x>n)
    {
        int sum=0;
        for(int i=n;i>=1;i--)
        {
            a[i]=0;
            if(iss[i])
                continue;
            int l=g[i].size();
            for(int jj=0;jj<l;jj++)
            {
                int j=g[i][jj];
                if(!iss[j])
                    a[i]=max(a[i],a[j]+1);
            }
            for(int jj=0;jj<l;jj++)
            {
                int j=g[i][jj];
                if(iss[j])
                    a[i]+=sz[j];
            }
            sum+=a[i]+1;
        }
   //     for(int i=1;i<=n;i++)
  //          cout<<iss[i];
  //      cout<<"   ";
   //     for(int i=1;i<=n;i++)
   //         cout<<a[i]<<" ";
   //     cout<<"   "<<sum<<"\n";
        maxx=max(maxx,sum);
        return;
    }
    if(!iss[fa[x]])
    {
        iss[x]=0;
        dfs(x+1);
    }
    iss[x]=1;
    dfs(x+1);
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=2;i<=n;i++)
            cin>>fa[i];
        if(m<=2)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
                cn[i]=0;
            for(int i=2;i<=n;i++)
                cn[fa[i]]++;
            int maxx=0;
            for(int i=2;i<=n;i++)
            {
                if(fa[i]==1)
                {
                    if(cn[i]==0)
                        ans++;
                    else
                        ans+=cn[i]+2;
                    maxx=max(maxx,cn[i]);
                }
            }
            ans+=maxx+2;
            cout<<ans<<"\n";
            continue;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                sz[i]=0;
            }
            for(int i=n;i>=1;i--)
            {
                g[i].clear();
                sz[i]++;
                sz[fa[i]]+=sz[i];
            }
            for(int i=2;i<=n;i++)
            {
                g[fa[i]].push_back(i);
            }
            maxx=0;
            iss[1]=0;
            dfs(2);
            cout<<maxx<<"\n";
        }
    }
    return 0;
}

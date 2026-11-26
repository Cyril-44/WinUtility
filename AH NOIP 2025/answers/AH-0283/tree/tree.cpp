#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<=b;++i)
#define forl(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int ans;

void solve()
{
    ans=0;
    int n,m;cin>>n>>m;
    int fa[n+1],fh[n+1],dp[n+1],leaff[n+1],maxh=-1;
    bool leaf[n+1];
    memset(fh,0,sizeof(fh));
    memset(dp,0,sizeof(dp));
    memset(leaf,1,sizeof(leaf));
    memset(leaff,0,sizeof(leaff));
    fh[1]=1;
    forr(i,2,n)
    {
        cin>>fa[i];
        leaf[fa[i]]=0;
        fh[i]=fh[fa[i]]+1;
        maxh=max(maxh,fh[i]);
    }
    vector<int> ch[maxh+1];
    forr(i,1,n)
    {
        ch[fh[i]].push_back(i);
    }
    forl(i,maxh,2)
    {
        forr(j,0,ch[i].size()-1)
        {
            if(leaf[ch[i][j]]){
            dp[ch[i][j]]=leaff[fa[ch[i][j]]];
            leaff[fa[ch[i][j]]]++;
        }
        }
        forr(j,0,ch[i].size()-1)
        {
            dp[fa[ch[i][j]]]=max(dp[fa[ch[i][j]]],dp[ch[i][j]]+1);
        }
    }
    forr(i,1,n)
    {
        if(leaf[i]){
            if(dp[i]==0)ans++;
        }
        else{
            ans+=(dp[i]+1);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

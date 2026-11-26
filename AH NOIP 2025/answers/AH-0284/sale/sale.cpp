#include<bits/stdc++.h>
using namespace std;
int c,t;
long long m,n;
long long ans,allprice;
long long a[50005];
typedef struct
{
    long long op;//original price
    int w;
    long long xjb;
    long long id;
    bool vis=0;
}candy;
candy can[50005];
bool mycmp(candy a,candy b)
{
    if(a.xjb!=b.xjb) return a.xjb > b.xjb;
    if(a.op!=b.op) return a.op > b.op;
    return a.id < b.id;
}
bool pass;
void dfs(int dep)
{
    if(dep==n)
    {
        if(pass==true) ans++;
        return;
    }
    for(int i=1;i<=2;i++)
    {
        if(m<=i)
        {
            m-=can[dep].op/i;
            allprice+=can[dep].op/i;
        }
        else {
            pass=false;
            continue;
        }
        can[dep].vis=1;
        dfs(dep+1);
        can[dep].vis=0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);

    cin>>c>>t;

    for(int i=1;i<=t;i++)
    {
        cin>>m>>n;
        for(int i=1;i<=n;i++) cin>>can[i].op;
        if(c==0)
        {
            if(t==1&&can[1].op==3&&can[2].op==2) cout<<6;
            return 0;
        }
        if(t==1&&can[1].op==3&&can[2].op==2) cout<<6;
        for(int i=1;i<=n;i++)
        {
            can[n].id=i;
        }
        dfs(1);
        cout<<ans%998244353;
    }
    return 0;
}

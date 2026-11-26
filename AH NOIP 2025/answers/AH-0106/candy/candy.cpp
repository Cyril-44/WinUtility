#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Maxn=1e5;

struct node
{
    int x,y,sum;
    bool if_min;
}candy[Maxn+10];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
bool cmp_sum(node a,node b)
{
    return a.sum<b.sum;
}

int can_build[Maxn+10],build=0;

signed main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>candy[i].x>>candy[i].y;
        candy[i].sum=candy[i].x+candy[i].y;
        candy[i].if_min=0;
    }
    sort(candy+1,candy+1+n,cmp_sum);
    int minsum=candy[1].sum;
    for(int i=1;i<=n;i++)
        if(candy[i].sum==minsum) candy[i].if_min=1;
        else break;

    sort(candy+1,candy+1+n,cmp);
    int can_buy=1,can_sum=0;
    while(can_buy<n&& candy[can_buy-1].x+candy[can_buy+1].x<minsum )
        can_buy++,can_sum+=candy[can_buy].x;
   if(can_buy==1)
    {
        int ans=m/minsum*2;
        int shengyu=m-ans/2*minsum;
        if(candy[1].x<=shengyu) ans++;
        cout<<ans;
        return 0;
    }

    int buy_pair=0,shengyu=m;
  /*!*/  while(shengyu>can_sum) shengyu-=minsum,buy_pair++;

    int single=0;
    while(single<n&&shengyu-candy[single+1].x>=0)
    {
        single++,shengyu-=candy[single].x;
        if(candy[single].if_min==1) can_build[++build]=candy[single].y;
    }

    sort(can_build+1,can_build+1+build);
    int miny=1.2e18;
    if(build>0) miny=can_build[1];
    int rebuild=min(shengyu/miny,buy_pair);
    int ans=buy_pair*2+single+rebuild;
    cout<<ans;

    return 0;
}

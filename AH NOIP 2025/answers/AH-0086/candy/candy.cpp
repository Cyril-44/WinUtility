#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int x,y;
};
node w[100011];
int n,m;
inline int mwbax(int x,int y,int w,int z)
{
    return max(x,max(y,max(w,z)));
}
ll a[2][10011][3];
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&w[i].x,&w[i].y);
    if(m<=10000)
    {
        for(int j=1;j<=m;j++)
                a[0][j][0]=a[0][j][1]=a[0][j][2]=-1145141919;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(w[i].x>m) continue;
            int x=i&1,y=(i+1)&1;
            for(int j=1;j<=m;j++)
            {
                a[x][j][0]=max(a[y][j][0],max(a[y][j][1],a[y][j][2]));
                if(j>=w[i].x) a[x][j][2]=mwbax(a[y][j-w[i].x][0]+1, a[y][j-w[i].x][1]+1 , a[y][j-w[i].x][2]+1 , a[x][j-w[i].x][1]+1);
                if(j>=w[i].y+w[i].x)
                    a[x][j][1]=a[x][j-w[i].y][2]+1;
//                if(w[i].x==3)
  //                  printf("%d %d %d\n",j,a[x][j][0],a[x][j][1]);
            }
            a[y][0][0]=-1145141919;
        }
        for(int j=1;j<=m;j++)
            ans=max(a[n&1][j][0],max(a[n&1][j][1],a[n&1][j][2]));
        printf("%d",ans);
        return 0;
    }
    ll cnt=0,minn=0x7f7f7f7f;
    for(int i=1;i<=n;i++)
        minn=min(minn,w[i].x*1ll);
    printf("%lld",m/minn);
    return 0;
}

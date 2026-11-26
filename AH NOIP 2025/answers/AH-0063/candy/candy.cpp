#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll x,y,z;
    int id;
}a[100005];
bool cmp(node x,node y)
{
    if(x.z!=y.z)
        return x.z<y.z;
    return x.x<y.x;
}
bool cmp2(node x,node y)
{
    return x.x<y.x;
}
ll n,m,cnt,mx;
int f[115][115];
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].z=a[i].x+a[i].y;
        a[i].id=i;
    }
    if(n<=100&&m<=100)
    {
        ll sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                sum=0;
                for(int k=1;;k++)
                {
                    if(k&1)
                        sum+=a[i].x;
                    else
                        sum+=a[i].y;
                    if(sum<=j)
                        f[i][j]=max(f[i][j],f[i-1][j-sum]+k);
                    else
                        break;
                }
                f[i][j]=max(f[i][j],f[i-1][j]);
            }
        cout<<f[n][m];
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    ll s=0,xx=a[1].x,yy=a[1].y,idd=a[1].id,flag=0;
    sort(a+1,a+1+n,cmp2);
    for(int i=0;i<=n;i++)//挑前i糖果的x
    {
        if(a[i].id==idd)
        {
            flag=1;
            continue;
        }
        ll cnt=i-flag;
        s+=a[i].x;
        if(s>m)
            break;
        ll m1=m-s;
        cnt=cnt+m1/(xx+yy)*2;
        m1%=xx+yy;
        if(m1>=xx)
            cnt++;
        //cout<<"i:"<<i<<" cnt:"<<cnt<<"\n";
        mx=max(mx,cnt);
    }
    cout<<mx;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
typedef struct
{
    long long x;
    long long y;
    long long sum;
}price;
price p[100005];
price canx[100005],cany[100005];
bool mycmp(price a,price b)
{
    return a.sum < b.sum;
}
bool cmpx(price a,price b)
{
    return a.x < b.x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("candy5.in","r",stdin);
    freopen("candy.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin >> p[i].x >> p[i].y;
    for(int i=1;i<=n;i++) p[i].sum = p[i].x + p[i].y;
    sort(p+1,p+1+n,mycmp);
    for(int i=2;i<=n;i++) canx[i-1] = p[i];
    sort(canx+1,canx+n,cmpx);
    if(m<p[1].x)
    {
        cout<<0;
        return 0;
    }
    else if(m<p[1].sum)
    {
        cout<<1;
        return 0;
    }
    ans=2*(m/p[1].sum);
    long long mleft = m%p[1].sum;
    if(p[1].y > canx[1].x + canx[2].x && n>=3)
    {
        ans--;
        mleft+=p[1].y;
        price asmember;
        asmember.x=p[1].y;
        canx[n]=asmember;
        sort(canx+1,canx+n+1,cmpx);
        long long pos=1;
        while(mleft >= canx[pos].x && canx[pos].x!=0)
        {
            mleft-=canx[pos].x;
            ans++;
            pos++;
        }
    }
    else if(p[1].sum >canx[1].x + canx[2].x + canx[3].x && n>=4)
    {
        ans-=2;
        mleft+=p[1].sum;
        price asmember;
        asmember.x=p[1].x;
        canx[n]=asmember;
        sort(canx+1,canx+n+1,cmpx);
        long long pos=1;
        while(mleft >= canx[pos].x && canx[pos].x!=0)
        {
            mleft-=canx[pos].x;
            ans++;
            pos++;
        }
    }
    else
    {
        long long pos=1;
        while(mleft >= canx[pos].x && canx[pos].x!=0)
        {
            mleft-=canx[pos].x;
            ans++;
            pos++;
        }
    }
    cout<<ans;
    return 0;
}


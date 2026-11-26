#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,m,a[5005]={0},f[5005]={0},cnt[5005]={0},max_v=-1;
struct can{
    double x;
    long long xa,y;
};
bool cmp(can a,can b){
    return a.x>b.x || a.x==b.x && a.y>b.y;
}
void total(){
    long long sum=0,q=m;
    can arr[5005]={0};
    for(int i=1;i<=n;i++)arr[i].x=a[i]/f[i],arr[i].y=a[i],arr[i].xa=f[i];
    sort(arr+1,arr+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(q>=arr[i].xa)sum+=arr[i].y,q-=arr[i].xa;
    }
    max_v=max(max_v,sum);
    cout<<sum<<"\n";
    cnt[sum]++;
    cnt[sum]%=998244353;
    return ;
}
void dfs(long long step)
{
    if(step==n+1)
    {
        total();
        return ;
    }
    f[step]=1;
    dfs(step+1);
    f[step]=2;
    dfs(step+1);
    f[step]=0;
    return ;
}
int main(void){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        max_v=-1;
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        dfs(1);
        cout<<cnt[max_v]<<"\n";
    }
    return 0;
}

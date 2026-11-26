#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
const int modd=998244353;
struct node{
int t,a;
};node p[100005];node q[100005];
int f[100005];
int a[100005];
int sou2(){
    for(int i=1;i<=m;i++) f[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=p[i].t;j--)
        {
            f[j]=max(f[j],f[j-p[i].t]+p[i].a);
        }
    }
    return f[m];
}
bool cmd(node x,node y)
{
    return (x.a*2/x.t>y.a*2/y.t)||((x.a*2/x.t==y.a*2/y.t)&&(x.a>y.a));
}
int sou1()
{
    int cnt=0,mm=m;;
    for(int i=1;i<=n;i++)
        q[i]=p[i];
    sort(q+1,q+1+n,cmd);
    for(int i=1;i<=n;i++)
    {
        if(mm>=q[i].t){
            mm-=q[i].t;
            cnt+=q[i].a;
        }
        if(mm==0)break;
    }
    return cnt;
}
void pan()
{
    int x=sou1(),y=sou2();
    if(x==y)
        ans=(ans+1)%998244353;
}
void dfs(int k)
{
    if(k==n+1){
        pan();
        return;
    }
    p[k].t=1;
    dfs(k+1);
    p[k].t=2;
    dfs(k+1);
}
int pai(int x,int y){
    int cnt=1;
    for(int i=x;i>y;i--)
        cnt*=i;
    return cnt;
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int C,T;
    cin>>C>>T;
    if(C<=5)
    {
        while(T--)
        {
            ans=0;
            cin>>n>>m;
            for(int i=1;i<=n;i++)
                cin>>p[i].a;
            dfs(1);
            cout<<ans<<endl;
        }
    }
    if(C==10||C==11||C==12||C==19||C==20)
    {
        while(T--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;i++)   cin>>p[i].a;
            if(m%2==1)
            {
                ans=1;
                for(int i=1;i<n;i++)
                    ans=(ans*2)%modd;
            for(int i=2;i<n;i+=2)
                {
                    ans=(ans+pai((m-i)/2+i,i))%modd;
                }
                ans=(ans+2)%modd;
                cout<<ans;
            }
        }

    }
    if(C==7||C==8||C==9||C==14||C==15)
    {
        while(T--)
        {
            cin>>n>>m;
            ans=1;
            for(int i=1;i<=n;i++) cin>>a[i];
            sort(a+1,a+1+n);
            for(int i=1;i<=n;i++)
                ans=(ans*2)%modd;
            for(int i=n-1;i>=1;i--)
            {
                if(a[i]*2<=a[n]) break;
                ans--;
                for(int j=i-1;j>=1;j--)
                {
                    if(a[i]+a[j]<a[n]){
                        ans=ans-pow(2,j)+1;
                        break;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    if(C==16){
        while(T--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;i++){
                cin>>p[i].a;
                p[i].t=2;
            }
            ans=1;
            for(int i=1;i<=n;i++)
                ans=(ans*2)%modd;
            if(sou1()!=sou2()) ans--;
            cout<<ans<<endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar_unlocked
int read(){
    int x=0;bool f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c))x=x*10+c-'0',c=gc();
    return f?-x:x;
}
const int M=998244353;
int C;int n,m,ans;
struct node{int a,w;};
vector<node>a;
const int dd=45;
int dp[dd][dd<<1];
namespace sub3{
    int xjb(node&t){return t.a*(t.w==1?2:1);}
    void dfs(int now){
        if(now>n){
            vector<node>b;
            for(auto it:a)b.push_back(it);
            sort(b.begin(),b.end(),[](node&p,node&q){return xjb(p)==xjb(q)?(p.a>q.a):xjb(p)>xjb(q);});
            int nm=m,cnt=0;
            for(auto it:b)
                if(it.w<=nm)nm-=it.w,cnt+=it.a;
            int mx=0;
            for(int i=0;i<=m;i++)mx=max(mx,dp[n][i]);
            ans+=(cnt==mx);
            return;
        }
        for(int j=1;j<=m;j++)
            dp[now][j]=max(dp[now-1][j],dp[now-1][j-1]+a[now-1].a);
        dfs(now+1);
        a[now-1].w=2;
        for(int j=2;j<=m;j++)
            dp[now][j]=max(dp[now-1][j],dp[now-1][j-2]+a[now-1].a);
        dfs(now+1);
    }
    void work(){
        int T=read();
        while(T--){
            n=read(),m=read();a.clear();ans=0;
            for(int i=1;i<=n;i++)a.push_back({read(),1});
            memset(dp,0,sizeof(dp));
            dfs(1);
            printf("%lld\n",ans%M);
        }
    }
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    C=read();
    sub3::work();
    return 0;
}

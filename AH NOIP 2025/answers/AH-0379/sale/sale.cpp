#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long a[10000];
long long vis[100000];
long long ans=0;
struct node{
   long long yj,qj,bi;
   float xj;
}b[200000];
bool cmp(node aa,node bb){
      if(aa.xj!=bb.xj)return aa.xj>bb.xj;
       if(aa.yj!=bb.yj)return aa.yj>bb.yj;
       return aa.bi<bb.bi;
}
void dfs(long long dq,long long z,long long tar){
    if(dq==z+1){
        for(long long i=1;i<=z;i++){
            b[i].yj=a[i];
            b[i].qj=vis[i];
            b[i].xj=b[i].yj/b[i].qj;
            b[i].bi=i;
        }
        sort(b+1,b+1+z,cmp);
        long long minn=1e18;
        long long cnt=0;
        long long last1=1e18,last2=1e18,last3=0,last4=1e18;
        for(long long i=1;i<=z;i++){
            if(cnt+b[i].qj<=tar){
                cnt+=b[i].qj;
                if(b[i].qj==1){
                    last1=last2;
                    last2=b[i].yj;
                }else{
                  last4=b[i].yj;
                }
            }else{
                if(b[i].qj==2){
                 last3=max(last3,b[i].yj);
                }
            }
        }
        if(cnt==tar-1){
            last1=0;
        }
        long long jjj=min(last1+last2,last4);
        //cout<<jjj<<" "<<last3<<endl;
        if(last3<=jjj||last3==0){
            ans++;
         //   for(long long i=1;i<=z;i++)cout<<vis[i]<<" ";
        //cout<<endl;
        }

        return ;
    }
    vis[dq]=1;
     dfs(dq+1,z,tar);
     vis[dq]=2;
     dfs(dq+1,z,tar);
    // cout<<1<<endl;
    return ;
}
int main(){
        freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
            ans=0;
     long long n,m;
     cin>>n>>m;
     for(long long i=1;i<=n;i++)cin>>a[i];
     if(m==n*2-2){
        sort(a+1,a+1+n);
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=2;
            ans%=998244353;
        }
        float p=a[2];
        if(a[1]>p/2&&a[1]!=a[2])ans--;
        cout<<ans<<endl;
     }else if(n<=40){
       dfs(1,n,m);
       ans%=998244353;
       cout<<ans<<endl;
     }else{
         ans=1;
        for(int i=1;i<=n;i++){
            ans*=2;
            ans%=998244353;
        }
        cout<<ans<<endl;
     }

    }
    return 0;
}
//!noip@Nov29,2025:dream

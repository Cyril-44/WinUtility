#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#define ll long long
#define N 8005
using namespace std;
int t;
int n,m;
ll p[N],deg[N],g[N];
ll ans,maxn;
ll a[N];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        ans=maxn=0;
        for(int i=1;i<=n;i++) deg[i]=g[i]=0;
        for(int i=2;i<=n;i++){
            scanf("%lld",&p[i]);
            deg[p[i]]++;
        }
        if(m<=2){
            for(int i=2;i<=n;i++){
                if(p[i]==1){
                    maxn=max(maxn,deg[i]+1);
                    ans+=(1+deg[i]+(deg[i]>0));
                }
            }
            ans+=(maxn+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define N 45
const long long mod=998244353;
long long n,a[N],st;
long long m,t,cnt,f[100005];
struct node{
    int id;
    double w;
}c[N],b[N];
void cal(int x){
    cnt=0;
    memset(b,0,sizeof(b));
    while(x){
        b[++cnt].w=x%2;
        x>>=1;
    }
    return ;
}
bool cmp(node x,node y){
    if(x.w!=y.w)
        return x.w>y.w;
    if(a[x.id]!=a[y.id])
        return a[x.id]>a[y.id];
    return x.id<y.id;
}
bool cmp2(node x,node y){
    return x.w<y.w;
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%lld %lld",&st,&t);
    while(t--){
         scanf("%lld %lld",&n,&m);
        long long ans=0,sum1=0,s1=0,s2=0,sum2=0;
        bool diffe=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            if(a[i]!=a[i-1])
                diffe=1;
        }
        if(!diffe){
            long long cj=1;
            for(int i=1;i<=n;i++)
                diffe=diffe*2%mod;
            printf("%lld\n",diffe%mod);
            continue;
        }else{
            for(int i=0;i<=(1<<n)-1;i++){
                sum1=0;s1=0;s2=0;sum2=0;
                cal(i);
                for(int j=n;j>=1;j--){
                    b[j].w++;
                    c[j].w=a[j]*1.0/b[j].w;
                    c[j].id=j;
                    b[j].id=j;
                }
                sort(c+1,c+n+1,cmp);
                for(int j=1;j<=n;j++){
                    if(s1+b[c[j].id].w<=m){
                        sum1+=a[c[j].id];
                        s1+=b[c[j].id].w;
                    }
                }

                sort(b+1,b+n+1,cmp2);
                memset(f,0,sizeof(f));
                bool flag=0;
                for(int i=1;i<=n;i++){
                    for(int j=m;j>=(int)b[i].w;j--){
                        f[j]=max(f[j],f[j-(int)b[i].w]+a[b[i].id]);
                        if(f[j]>sum1){
                            flag=1;
                        }
                    }
                    if(flag)
                        continue;
                }
                if(flag) continue;
                if(sum1==f[m])
                    ans=(1+ans)%mod;
            }
            printf("%lld\n",ans%mod);
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

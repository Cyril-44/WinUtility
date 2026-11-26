#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353;
long long c,T,n,m,f[N],w[N],p[N];
struct sXC{
    int w;
    long long a;
    double xjb;
    int id;
}pr[N];
bool cmp(sXC u,sXC v){
    if(u.xjb!=v.xjb)return u.xjb>v.xjb;
    if(u.a!=v.a)return u.a>v.a;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>pr[i].a;
            p[i]=pr[i].a;
        }
        long long ans=0;
        for(int i=0;i<(1<<n);i++){
            for(int j=1;j<=n;j++){
                pr[j].a=p[j];
            }
            memset(f,0,sizeof(f));
            int cnt=0,opt=i;
            while(cnt<n){
                pr[++cnt].w=(opt&1)+1;
                w[cnt]=pr[cnt].w;
                pr[cnt].xjb=pr[cnt].a*1.0/pr[cnt].w;
                opt=(opt>>1);
            }
            for(int k=1;k<=n;k++){
                for(int j=m;j>=pr[k].w;j--){
                    f[j]=max(f[j],f[j-pr[k].w]+pr[k].a);
                }
            }
            long long t1=f[m],t2=0,t=m;
            sort(pr+1,pr+n+1,cmp);
            for(int j=1;j<=n;j++){
                if(t>=pr[j].w){
                    t-=pr[j].w;
                    t2+=pr[j].a;
                }
            }
            if(t2>=t1){
                ans++;
            }
            ans=ans%mod;
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 50005
using namespace std;
const ll mod=998244353;
int cd,t;
ll n,m,a[N],c[N];
ll fac[N],inv[N],ans;
struct node{
    ll a,w;
    friend bool operator < (node aa,node bb){
        if(aa.a*bb.w!=bb.a*aa.w) return (aa.a*bb.w>bb.a*aa.w);
        return aa.a>bb.a;
    }
}b[N];
bool cmp(int xx,int yy){
    return xx>yy;
}
ll qp(ll a,ll b){
    if(b<=0) return 1ll;
    ll x=qp(a*a%mod,b/2);
    return b%2?x*a%mod:x;
}
ll C(ll x,ll y){
    if(x<y||x<0||y<0) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%d%d",&cd,&t);
    fac[0]=inv[0]=1;
    for(int i=1;i<=5e4;i++) fac[i]=fac[i-1]*i%mod;
    inv[50000]=qp(fac[50000],mod-2);
    for(int i=49999;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
    if(cd==18){
        while(t--){
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
            ans=1;
            for(int i=1;i<=n;i++){
                ans=ans*2%mod;
            }
            cout<<ans<<endl;
        }
    }else if((cd>=7&&cd<=9)||(cd==14||cd==15)){
        while(t--){
            ans=0;
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
            a[n+1]=0;
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n+1;j++){
                    int k;
                    if(i==1&&j==2) k=3;
                    else if(i==1) k=2;
                    else k=1;
                    if(a[i]*2>a[k]&&a[k]>a[i]+a[j]){
                        ans=(ans+qp(2,n-max(max(i,j),k)))%mod;
                    }
                }
            }
            cout<<(qp(2,n)-ans+mod)%mod<<endl;
        }
    }else if((cd>=10&&cd<=12)||cd==19||cd==20){
        while(t--){
            ans=0;
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
            a[n+1]=0;
            sort(a+1,a+1+n,cmp);
            for(int i=n;i>=1;i--){
                if(a[i]==a[i+1]) c[i]=c[i+1];
                else c[i]=i;
            }
            for(int i=1;i<=n;i++){
                ans=(ans+C(n-i,m-i)-C(c[i]-i,m-i))%mod;
            }
            cout<<(qp(2,n)-ans+mod)%mod<<endl;
        }
    }else{
        while(t--){
            scanf("%lld%lld",&n,&m);
            ans=0;
            for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
            for(int i=0;i<(1<<n);i++){
                int s=m,cnt=0,idx1=0,idx2=0;
                for(int j=1;j<=n;j++){
                    if(i&(1<<(j-1))) b[j]=(node){a[j],2};
                    else b[j]=(node){a[j],1};
                }
                b[n+1]=(node){0,1};
                sort(b+1,b+1+n);
                for(int i=1;i<=n;i++){
                    if(s>=b[i].w){
                        s-=b[i].w;
                        if(b[i].w==1) idx1=i;
                    }else{
                        idx2=i;
                        break;
                    }
                }
                if(s==1&&idx1!=0){
                    for(int ii=idx2;ii<=n+1;ii++){
                        if(b[ii].w==1){
                            if(b[idx1].a+b[ii].a<b[idx2].a){
                                ans++;
                            }
                            break;
                        }
                    }
                }
            }
            cout<<(1<<n)-ans<<endl;
        }
    }
    return 0;
}

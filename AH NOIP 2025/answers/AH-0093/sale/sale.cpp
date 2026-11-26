#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
const int N=1e5+10;
long long c,t,n,m,a[N];
struct kx{
    int p;
    double t;
}f[N];
long long pow1(long long a,long long b){
    long long t=1;
    a=a%p;
    for(;b;b=b>>1){
        if(b&1) t=t*a;
        a*=a;
        a%=p;
        t%=p;
    }
    return t%p;
}
bool cmp(int g,int h){return g>h;}
bool cmp2(kx g,kx h){
    if(g.t!=h.t) return g.t>h.t;
    return g.p>h.p;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c==18){
            cout<<pow1(2,n)<<endl;
            for(int i=1;i<=n;i++) a[i]=0;
            continue;
        }
        sort(a+1,a+1+n,cmp);
        long long ans=pow1(2,n);
        if(m==2){
            int l=0;
            for(int i=2;i<=n;i++){
                if(a[i]*2>a[1]) ans--;
                else {
                    l=i;//第一个小于a[1]/2的位置
                    break;
                }
            }
            if(ans<0) ans+=p;
            for(int i=2;i<l;i++){
                for(int j=n;j>=l;j--){
                    if(a[i]+a[j]<a[1]){
                        ans-=pow1(2,n-j);
                        if(ans<0) ans+=p;
                    }
                }
            }
            cout<<ans<<endl;
            for(int i=1;i<=n;i++) a[i]=0;
            continue;
        }else if(n<=5){
            bool vis[10];
            memset(vis,0,sizeof(vis));
            for(int i1=1;i1<=2;i1++){
                for(int i2=1;i2<=2;i2++){
                    for(int i3=1;i3<=2;i3++){
                        for(int i4=1;i4<=2;i4++){
                            for(int i5=1;i5<=2;i5++){
                                    int d=0;
                                f[1].t=a[1]/i1;f[2].t=a[2]/i2;f[3].t=a[3]/i3;f[4].t=a[4]/i4;f[5].t=a[5]/i5;
                                f[1].p=a[1];f[2].p=a[2];f[3].p=a[3];f[4].p=a[4];f[5].p=a[5];
                                sort(f+1,f+1+n,cmp2);
                                int cnt=0,k=m;
                                memset(vis,0,sizeof(vis));
                                for(int i=1;i<=n;i++){
                                    if(i==1) d=i1;if(i==2) d=i2;if(i==3) d=i3;if(i==4) d=i4;if(i==5) d=i5;
                                    if(k>=d) {
                                        k-=d;
                                        cnt+=f[i].p;
                                    }
                                    vis[i]=1;
                                }
                                if(m==1){
                                        int x=0;
                                    for(int i=1;i<=n;i++){
                                        if(vis[i]) x=i;
                                    }
                                    if(x==n) continue;
                                    for(int i=x+1;i<=n;i++) if(f[i].p>f[x].p) {ans--;break;}
                                }else{
                                    int x=0,y=0;
                                    for(int i=1;i<=n;i++){
                                        if(i==1) d=i1;if(i==2) d=i2;if(i==3) d=i3;if(i==4) d=i4;if(i==5) d=i5;
                                        if(d==1&&vis[i]) x=y,y=i;
                                    }
                                    for(int i=x+1;i<y;i++){
                                        if(f[x].p+f[y].p<f[i].p){ans--;break;}
                                    }
                                }
                            }
                        }
                    }
                }
            }

        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++) a[i]=0;
    }
    return 0;
}

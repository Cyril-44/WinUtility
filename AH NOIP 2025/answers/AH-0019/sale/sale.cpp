#include <bits/stdc++.h>
using namespace std;
int read(){
    int xx=0,ff=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') ff=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        xx=xx*10+(ch-'0');
        ch=getchar();
    }
    return xx*ff;
}
void write(int xx){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10) write(xx/10);
    putchar(xx%10+'0');
}
const int N=5000,mod=998244353;
int jia(int A,int B){return (A+B<mod?A+B:A+B-mod);}
void add(int &A,int B){A=jia(A,B);}
int jin(int A,int B){return A-B<0?A-B+mod:A-B;}
void mns(int &A,int B){A=jin(A,B);}
int ca,T,f[N+5][2*N+5],C[N+5][N+5];
int n,m,a[N+5],h[N+5],p[N+5],pre[N+5];
void cle(){
    for(int i=0;i<=n;++i) h[i]=p[i]=pre[i]=0;
}
struct www{
    int val,ty,id,oe;
}b[2*N+5];
bool cmp(www A,www B){
    if(A.val==B.val){
        if(A.ty==B.ty){
            if(A.oe==B.oe) return A.id<B.id;
            else return A.oe>B.oe;
        }
        return A.ty>B.ty;
    }
    else return A.val>B.val;
}
int main() {
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    f[0][0]=1;
    for(int i=1;i<=N;++i){
        for(int j=2*i;j>=2;--j) f[i][j]=jia(f[i-1][j-1],f[i-1][j-2]);
        f[i][1]=f[i-1][0];
    }
    for(int i=0;i<=N;++i){
        C[i][0]=1;
        for(int j=1;j<=i;++j) C[i][j]=jia(C[i-1][j],C[i-1][j-1]);
    }
    ca=read(); T=read();
    while(T--){
        n=read(); m=read();
        vector<int> ls(n);
        for(int i=1;i<=n;++i){
            a[i]=read();
            b[i]=(www){a[i],1,i,a[i]&1};
            b[i+n]=(www){(a[i]>>1),2,i,a[i]&1};
            ls[i-1]=a[i];
        }
        sort(ls.begin(),ls.end());
        ls.erase(unique(ls.begin(),ls.end()),ls.end());
        int len=ls.size();
        if(len==1){
            int h=1;
            for(int i=1;i<=n;++i) h=2ll*h%mod;
            write(h); putchar('\n');
            continue;
        }
        if(n<=5){
            long long ans=0;
            for(long long s=0;s<(1<<n);++s){
                vector<tuple<double,long long,long long,long long> > v;
                for(long long i=1;i<=n;++i){
                    if((s>>(i-1))&1) v.emplace_back(-a[i]/2.0,-a[i],i,2);
                    else v.emplace_back(-a[i],-a[i],i,1);
                }
                sort(v.begin(),v.end());
                long long sum=0;
                long long k=m;
                for(long long i=1;i<=n;++i){
                    long long w=get<3>(v[i-1]);
                    long long aa=-get<1>(v[i-1]);
                    if(k<w) continue;
                    k-=w;
                    sum+=aa;
                }
                long long res=0;
                do{
                    for(long long t=0;t<(1<<n);++t){
                        long long p=0,k=m;
                        for(long long i=1;i<=n;++i){
                            if((t>>(i-1))&1){
                                long long w=get<3>(v[i-1]);
                                long long aa=-get<1>(v[i-1]);
                                if(k<w) continue;
                                k-=w;
                                p+=aa;
                            }
                        }
                        res=max(res,p);
                    }
                }while(next_permutation(v.begin(),v.end()));
                ans+=(sum==res);
            }
            write(ans);
            putchar('\n');
            cle();
            continue;
        }
        sort(b+1,b+2*n+1,cmp);
        for(int i=1;i<=2*n;++i){
            pre[i]=pre[i-1];
            if(b[i].ty==2) p[b[i].id]=i;
            else ++pre[i];
        }
        int e=1,ans=0,tc=0,ms=0;
        for(int w=2*n;w>=1;--w){
            if(b[w].ty==1){
                int x=lower_bound(ls.begin(),ls.end(),b[w].val)-ls.begin()+1;
                h[x]=e;
                add(ms,e);
                add(e,e);
                --tc;
            }
            else{
                bool fl=1;
                int aw=a[b[w].id],k=m-2,s=jia(ms,1),r=len,c=tc;
                for(int x=w-1;x>=1 && k>=0;--x){
                    if(b[x].id==b[w].id){
                        fl=0;
                        continue;
                    }
                    if(b[x].ty==1){
                        if(p[b[x].id]>w) --c;
                        if(aw>b[x].val){
                            while(r>=1 && ls[r-1]>=aw-b[x].val){
                                mns(s,h[r]);
                                --r;
                            }
                            int d=pre[x-1]-fl-c;
                            // int o=0;
                            for(int i=0;i<=min(c,k);++i){
                                add(ans,1ll*f[d][k-i]*C[c][i]%mod*s%mod);
                                // add(o,1ll*f[d][k-i]*C[c][i]%mod*s%mod);
                            }
                        }
                        if(p[b[x].id]<w) k-=2;
                    }
                }
                ++tc;
            }
        }
        write(jin(e,ans)); putchar('\n');
        cle();
    }
    return 0;
}
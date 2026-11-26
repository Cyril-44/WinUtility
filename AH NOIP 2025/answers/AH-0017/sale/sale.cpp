#include<bits/stdc++.h>
#define ll long long
#define itn int
#define gc getchar
#define pc putchar
#define scf scanf
#define prf printf
#define fu(v,s,e) for(int v=(s);v<=(e);v++)
#define fd(v,s,e) for(int v=(s);v>=(e);v--)
using namespace std;
int _t,_c;
int in(){
    int x=0,f=1;
    char c=gc();
    while((c<'0'||c>'9')&&c!='-') c=gc();
    if(c=='-') c=gc(),f=-1;
    while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
    return x*f;
}
template<typename _Tp>
void out(_Tp x){
    if(x>9) out(x/10);
    pc(x%10+'0');
}
template<typename _Tp>
void out(_Tp x,char c){out(x),pc(c);}
#define mod 998244353
int n,m,a[50005];
namespace n_10{
    ll f[25];
    int c[15],ans;
    struct node{
        int b,i;
    }b[15];
    inline bool operator<(const node &p,const node &q){
        if(p.b^q.b) return p.b>q.b;
        if(a[p.i]^a[q.i]) return a[p.i]>a[q.i];
        return p.i<q.i;
    }
    int wk(){
        memset(f,0,sizeof(f));
        fu(i,1,n) fd(j,m,c[i]) f[j]=max(f[j],f[j-c[i]]+a[i]);
        fu(i,1,n) b[i]=node{a[i]*(3-c[i]),i};
        sort(b+1,b+1+n);
        int mm=m;
        ll res=0;
        fu(i,1,n) if(mm>=c[b[i].i]) mm-=c[b[i].i],res+=a[b[i].i];
        // fu(i,1,n) cerr<<c[i]<<' ';
        // cerr<<'\n'<<f[m]<<' '<<res<<'\n';
        return res==f[m];
    }
    int mian(){
        ans=0;
        fu(k,0,((1<<n)-1)){
            fu(i,1,n) c[i]=((k>>(i-1))&1)+1;
            ans+=wk();
        }
        return ans;
    }
}
int pw(int a,int b){
    if(!b) return 1;
    ll x=pw(a,b>>1);
    if(b&1) return x*x%mod*a%mod;
    return x*x%mod;
}
namespace m_2{
    int mian(){
        sort(a+1,a+1+n);
        int ed=0;
        fd(i,n,1) if(a[i]*2<=a[n]){
            ed=i+1;
            break;
        }
        ll ans=0;
        fu(i,ed,n-1){
            int st=lower_bound(a+1,a+1+n,a[n]-a[i])-a-1;
            ans+=pw(2,st);
        }
        return (pw(2,n)-ans%mod+mod)%mod;
    }
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    _c=in(),_t=in();`
    while(_t--){
        n=in(),m=in();
        fu(i,1,n) a[i]=in();
        // if(n<=10) out(n_10::mian(),'\n');
        if(m==2) out(m_2::mian(),'\n');
    }
    // cerr<<clock()/1000.0<<'\n';
    return 0;
}
/*
消除激光炮
                                                            __--\__                    
                                                        __-/       \--\__              
                                                       /__               \             
                                                       |  \--\__    __--/ |            
-   -   -   -   -   -   -   -   -   -   -   -   -   -  |-   -   \-\/      |            
========\\===========\\===========\\===========\\===========\\    |       |            
########||###########||###########||###########||###########||    |       |            
========//===========//===========//===========//===========//    |       |            
-   -   -   -   -   -   -   -   -   -   -   -   -   -  |-_  -     |     __/            
                                                          \--\__  |__--/               
                                                             |  \-/ \_                 
                                                         __-/         \---__           
                                                        /                   \          
                                                       /                      \        
                                                     /   /               \       \     
                                                    |    |                 \       |   
                                                   |    //                  |\       | 
                                                  /    / |                  |  \      \
                                                  \    \ \                  |   |     /
                                                   |    | |                 |   |     |
                                                   |    \ |                  \  /     /
                                                   \    | |                  | /     | 
                                                    \ ___\/                  \/____ /  
                                                     /   \                    /    \   
                                                     \___/                    \____/   
                                                        /        _-^-_          \      
                                                      /         /     |         |      
                                                     /         /       |         |     
                                                    /         /         |        |     
                                                    \        \           \        |    
                                                    |        |            |       \    
                                                    \        |            |        |   
                                                    |        |            |        |   
                                                    \         |           /        |   
                                                     |        |           |       /    
                                                     |        |           |       |    
                                                     |        /           |       |    
*/
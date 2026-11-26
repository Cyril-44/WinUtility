#include<bits/stdc++.h>
#define for1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define for2(i,a,b) for(int i=(a);(i)>=(b);(i)--)
#define pedl cout<<"\n";
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define of pop_front
#define ob pop_back
#define ls (p<<1)
#define rs (p<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
using namespace std;
template<typename T> void cmax(T &x,T y){if(x<y) x=y;}
template<typename T> void cmin(T &x,T y){if(x>y) x=y;}
typedef pair<int,int> P;
typedef long long LL;
#define int long long
typedef double db;
typedef long double ldb;
const int base = 13331;
const int N = 10005;
const int M = 1e5 + 5;
const int mod = 998244353;

LL n,m,qwq;
LL a[N];//value;
LL w[N];//weight
LL f[N];
LL qpow(LL x,LL y){
    if(y==0) return x;
    LL xx=1ll*x; y--;
    for(;y;y>>=1,x=(x*x)%mod)
        if(y&1) xx=(xx*x)%mod;
    return xx;
}
struct node{
    int bb,aa,id,mon;
    bool operator <(const node &tmp)const{
        return (bb==tmp.bb?(aa==tmp.aa?(id<tmp.id):(aa>tmp.aa)):bb>tmp.bb);
    }
}b[N];
void solve(){
    cin>>n>>m;
    for1(i,1,n) cin>>a[i],a[i]*=2;
    int S=(1<<n)-1;
    qwq=0;
    for1(s,0,S){
        if(s==0||s==S) {
            qwq++;
            continue;
        }
        for1(i,1,n){
            if(s&(1<<(i-1))){
                b[i]=node{a[i]/2,a[i],i,2};
                w[i]=2;
            }else b[i]={a[i],a[i],i,1},w[i]=1;
        }
        for1(i,1,m) f[i]=-1e18;
        f[0]=0;
        for1(i,1,n){
            for2(j,m,w[i])
                cmax(f[j],f[j-w[i]]+a[i]);
        }
        sort(b+1,b+1+n);
        LL mm=m,cnt=0;
        for1(i,1,n){
            if(mm>=b[i].mon){
                mm-=b[i].mon;
                cnt+=b[i].aa;
            }
        }
        if(cnt==f[m]) qwq++;
    }
    cout<<qwq<<"\n";
    return ;
}

signed main(){
   freopen("sale.in","r",stdin);
   freopen("sale.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int ccc,Testcase=1;
cin>>ccc>>Testcase;
while(Testcase--){
    solve();
}
    return 0;
}
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
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
const int base = 13331;
const int N = 5005;
const int M = 1e5 + 5;
const __int128 mod = ((__int128)1<<64);
const LL LINF = 1e18;

LL n,q;
LL a[N],sum[N];
LL f[N][N];
__int128 mad(int x,LL y){
    __int128 qwq=1ll*x*y;
    if(qwq<0){
        qwq+=((-qwq)/mod+1)*mod;
    }
    return (qwq%mod);
}
void solve(){
    cin>>n;
    for1(i,1,n) cin>>a[i]; 
    for1(i,1,n) sum[i]=sum[i-1]+a[i];
    for1(i,1,n){
        for1(len,1,n){
            f[i][len]=-LINF;
            for1(r,max(i,len),min(n,i+len-1ll)){
                cmax(f[i][len],sum[r]-sum[r-len]);
            }
        }
    }
    cin>>q;
    for1(qwqwq,1,q){
        int L,R;
        ULL ans=0;
        cin>>L>>R;
        for1(i,1,n){
            LL k=-LINF;
            for1(j,L,R){
                cmax(k,f[i][j]);
            }
            ans^=(mad(i,k));
        }
        cout<<ans<<"\n";
    }
    return ;
}

signed main(){
   freopen("query.in","r",stdin);
   freopen("query.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int Testcase=1;
// cin>>Testcase;
while(Testcase--){
    solve();
}
    return 0;
}

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
typedef double db;
typedef long double ldb;
const int base = 13331;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
const int mod = 10007;

int n;
LL m;
LL a[2][N],b[N];
LL sum,cnt,ans;
void solve(){
    cin>>n>>m;
    for1(i,1,n){
        cin>>a[0][i]>>a[1][i];
        b[i]=a[0][i]+a[1][i];
    }
    sort(b+1,b+1+n);
    sort(a[0]+1,a[0]+1+n);
    ans=(m/b[1])*2;
    for1(i,1,n){
        if(m>=a[0][i]) {
            m-=a[0][i],cnt++;
            cmax(ans,cnt+(m/b[1])*2);
        }else break;
    }
    cout<<ans;
    return ;
}

signed main(){
   freopen("candy.in","r",stdin);
   freopen("candy.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int Testcase=1;
// cin>>Testcase;
while(Testcase--){
    solve();
}
    return 0;
}

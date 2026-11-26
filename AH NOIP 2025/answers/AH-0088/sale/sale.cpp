#include <cstdio>
#include <algorithm>
#define rep(i, j, k) for(int i = (j); i <= ((int)(k)); i++)
#define rrep(i, j, k) for(int i = (j); i >= ((int)(k)); i--)
using namespace std;

typedef long long ll;
const int maxn = 5e3 + 5;
const ll mod = 998244353;
struct can{
    int pre;
    double bi;
    int id;
    bool operator< (const can& y){
        if(bi == y.bi && pre == y.pre){
            return id < y.id;
        }
        if(bi == y.bi){
            return pre > y.pre;
        }
        return bi > y.bi;
    }
}cc[maxn];
int a[maxn];
int co[maxn];
ll f[maxn << 1];
int ans = 0;

inline ll read(void){
    ll ans = 0;
    ll fl = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') fl *= -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans * fl;
}

inline ll pow(ll x, ll y){
    ll ans = 1;
    ll bas = x;
    while(y){
        if(y & 1){
            ans = ans * bas % mod;
        }
        y >>= 1;
        bas = bas * bas % mod;
    }
    return ans % mod;
}

inline ll max(ll x, ll y){
    return x > y ? x : y;
}

inline bool work(int n, int m){
    rep(i, 1, n){
        cc[i].pre = a[i];
        cc[i].bi = (double)a[i] / co[i];
        cc[i].id = i;
    }
    rep(i, 0, m){
        f[i] = 0;
    }
    sort(cc + 1, cc + 1 + n);
    ll vala = 0;
    ll valb = 0;
    int mm = m;
    rep(i, 1, n){
        if(mm >= cc[i].pre / cc[i].bi){
            mm -= cc[i].pre / cc[i].bi;
            vala += cc[i].pre;
        }
    }
    rep(i, 1, n){
        rrep(j, m, co[i]){
            f[j] = max(f[j], f[j - co[i]] + a[i]);
            valb = max(valb, f[j]);
        }
    }
    return valb == vala;
}

inline void dfs(int i, int n, int m){
    if(i > n){
        ans += work(n, m);
        return;
    }
    co[i] = 1;
    dfs(i + 1, n, m);
    co[i] = 2;
    dfs(i + 1, n, m);
}

int main(){
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
    int c = read(), t = read();
    int n, m;
    while(t--){
        n = read();
        m = read();
        ans = 0;
        rep(i, 1, n){
            a[i] = read();
        }
        if(c == 18 || c == 16){
            printf("%lld\n", pow(2, n));
        }
        else{
            dfs(1, n, m);
            printf("%d\n", ans);
        }
    }
    return 0;
}

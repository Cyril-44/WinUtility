#include <cstdio>
#include <algorithm>
#define rep(i, j, k) for(int i = (j); i <= ((int)(k)); i++)
#define rrep(i, j, k) for(int i = (j); i >= ((int)(k)); i--)
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
struct node{
    int id;
    ll val;
    inline bool operator< (const node& y)const{
        return val < y.val;
    }
}co[maxn];
ll cost[maxn][2];
ll coo[maxn];

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

int main(){
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
    int n = read();
    ll m = read();
    bool fl = 0;
    rep(i, 1, n){
        cost[i][0] = read();
        cost[i][1] = read();
        co[i].id = i;
        co[i].val = cost[i][0];
    }
    ll te = cost[1][0] + cost[1][1];
    int po = 1;
    rep(i, 2, n){
        if(te > cost[i][0] + cost[i][1] || (te == cost[i][0] + cost[i][1] && cost[i][0] < cost[po][0])){
            po = i;
            te = cost[i][0] + cost[i][1];
        }
    }
    sort(co + 1, co + 1 + n);
    int pp;
    ll ans = 0;
    ll anst = 0;
    for(pp = 2; pp <= n; pp += 2){
        if(co[pp].val + co[pp - 1].val < te && m >= co[pp].val + co[pp - 1].val){
            m = m - co[pp].val - co[pp - 1].val;
            ans += 2;
            if(co[pp].id == po || co[pp - 1].id == po){
                fl = 1;
            }
        }
        else{
			break;
		}
    }
    if(fl){
        if(m >= cost[po][1]){
            m -= cost[po][1];
            anst++;
        }
	}
    anst = anst + m / te * 2;
    m = m % te;
    pp -= 1;
    if(fl){
        if(m >= cost[po][0]){
            m -= cost[po][0];
            ans++;
        }
    }
    if(m >= co[pp].val && pp <= n){
        m -= co[pp].val;
        ans++;
    }
    if(!fl){
        if(m >= cost[po][0]){
            m -= cost[po][0];
            ans++;
        }
    }
    printf("%lld\n", ans + anst);
    return 0;
}

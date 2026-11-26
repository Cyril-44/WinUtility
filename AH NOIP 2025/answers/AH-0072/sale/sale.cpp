#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

const int N = 5e3 + 10,mod = 998244353;

int n,m,fac[N],invfac[N],c[N],f[40][100];


struct node{
    int id,v,c;
}a[N];

bool cmp(node n1,node n2){
    if(n1.v * n2.c != n2.v *n1.c) return n1.v * n2.c > n2.v * n1.c;
    if(n1.v != n2.v) return n1.v > n2.v;
    return n1.id < n2.id;
}

int fpow(int x,int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;y >>= 1;
    }return ans;
}

int A(int x,int y){
    if(x < 0 || y < 0 || x < y) return 0;
    return fac[x] * invfac[x - y] % mod;
}

void solve1(){
    int sum = 0;
    for(int s = 0;s < (1 << n);s ++){
        for(int i = 1;i <= n;i ++){
			 a[i].c = ((s >> (i - 1)) & 1) + 1;
			 //cout << a[i].c << ' ';
		 }//cout << '\n';
        sort(a + 1,a + n + 1,cmp);
       // for(int i = 1;i <= n;i ++) cout << a[i].v << ' ';cout << '\n';
        int ans1 = 0,ans2 = 0,x = m;
        for(int i = 1;i <= n;i ++){
            if(a[i].c <= x) {x -= a[i].c,ans1 += a[i].v;}
        }
        f[0][0] = 0;
        for(int i = 1;i <= n;i ++){
            for(int j = 0;j <= m;j ++){
                f[i][j] = f[i - 1][j];
                if(j >= a[i].c) f[i][j] = max(f[i][j],f[i - 1][j - a[i].c] + a[i].v);
                ans2 = max(ans2,f[i][j]);
            }
        }
        //cout << ans1 << ' ' << ans2 << '\n';
        //ans2 = f[n][m];
        if(ans1 == ans2) sum ++;
        sort(a + 1,a + n + 1,[](node n1,node n2){return n1.id < n2.id;});
    }cout << sum << '\n';
}

void solve2(){
    sort(a + 1,a + n + 1,[](node n1,node n2){
        if(n1.v != n2.v) return n1.v < n2.v;
        return n1.id > n2.id;
    });
    int sum = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = i + 1;j <= n;j ++){
            sum += A(j - i - 1,m - n + j - 2);
            sum %= mod;
        }
    }
    cout << sum << '\n';
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    fac[0] = invfac[0] = 1;
    for(int i = 1;i <= 5000;i ++) fac[i] = fac[i - 1] * i % mod,invfac[i] = fpow(fac[i],mod - 2);
    //cout << A(6,3) << '\n';
    int c,T;
    cin >> c >> T;
    while(T --){
            memset(f,0,sizeof(f));
        cin >> n >> m;
        for(int i = 1;i <= n;i ++){
            cin >> a[i].v;a[i].id = i;
        }
        if(n <= 10) solve1();
        //else if((c >= 10 && c <= 12) || c == 19 || c == 20) solve2();
        else cout << fpow(2,n) << '\n';
        //cout << fpow(2,n) << '\n';
        //sort(a + 1,a + n + 1,cmp);
        /*int ans = 0;
        for(int i = 1;i <= n;i ++){
            for(int j = i + 1;j <= n;j ++){
                node tmp = {a[i].v * 2,a[i].id};
                if(cmp(tmp,a[j])) continue;
                int sum = 1,cnt0 = 0,cnt1 = 0,cnt2 = 0;
                for(int k = 1;k <= n;k ++){
                        node tmp2 = {a[k].v *2,a[k].id};
                    if(cmp(tmp2,a[j])) cnt0 ++;
                    else break;
                }
                cnt1 = j - i - 1;
                for(int k = j + 1;k <= n;k ++){
                    if(cmp(tmp,a[k])) cnt2 ++;
                }
                int x = m - 2 - cnt1 - cnt2,cnt = 0;
                for(int c1 = 0;c1 <= cnt1;c1 ++){
                    int c2 = x + c1;
                    if(c2 < 0 || c2 > cnt2) continue;
                    else cnt = (cnt + A(cnt1,c1) * A(cnt2,c2)) % mod;
                }
                ans = (ans + cnt * fpow(2,cnt0)) % mod;
            }
        }*/
        //cout << fpow(2,n) << '\n';
    }


    return 0;
}

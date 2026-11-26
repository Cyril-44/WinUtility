#include <bits/stdc++.h>

#define mp make_pair
#define pii pair <int, int>
using ll = long long;

using namespace std;

const ll p = 998244353;
const int N = 5010;

ll fac[N << 1], ifac[N << 1];

ll qpow (ll base, int k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * base % p;
        base = base * base % p;
        k >>= 1;
    }
    return ret;
}

ll comb (int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % p * ifac[n - m];
}

int n, m;
int a[N];


void work () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf ("%d", a + i);
    sort (a + 1, a + n + 1); ll ans = 0;
    // for (int i = 1; i <= n; i ++) {
    //     int p2 = lower_bound (a + 1, a + n + 1, a[i] * 2) - a;
    //     int c2 = n - p2 + 1;
    //     int c1 = n - c2 - i;
    //     if (a[i] == a[i - 1]) continue;

    //     for (int j = 0; j <= c2; j ++) { // j = [w_k=2 && a_k >= 2a_i]
    //         if (j * 2 + (c2 - j) > m - 2) break ; // 前面要选 m-2 个 
    //         int left = (m - 2) - ();
    //     }
    // }

    printf ("%lld\n", ans);
}

namespace n3 {
void work () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf ("%d", a + i); ++ n;
    sort (a + 1, a + n + 1); ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == a[i - 1]) continue;
        int p2 = lower_bound (a + 1, a + n + 1, a[i] * 2) - a;
        int c2 = n - p2 + 1;
        int c1 = n - c2 - i;
        int infr = upper_bound (a + 1, a + n + 1, a[i] + a[i - 1]) - a; // 在其之后的首个元素
        int c3 = p2 - infr;
        fprintf (stderr, "for a=%d, c1 = %d, c2 = %d, c3 = %d\n", a[i], c1, c2, c3);
        if (c3 <= 0) continue;
        for (int j = 0; j <= c2; j ++) { // j = [w_k=2 && a_k >= 2a_i]
            if (j * 2 + (c2 - j) > m - 2) break ;
            int left = m - 2 - j * 2 - (c2 - j);
            for (int q = 1; q <= c3; q ++)
                (ans += comb (c2, j) * comb (c1 - (q - 1), c1 - c2 - i - q + 1)) %= p;
        }
    }

    ll tot = qpow (2, n - 1);
    fprintf (stderr, "tot = %lld\n", tot);
    printf ("%lld\n", (tot - ans + p) % p);
}
};  

namespace bf {

struct node {
    int a, w, id;  
};

bool comp (node x, node y) {
    if (x.a * 1ll * y.w != y.a * 1ll * x.w) return x.a * 1ll * y.w > y.a * 1ll * x.w;
    if (x.a != y.a) return x.a > y.a;
    return x.id < y.id;
}

void work () {
    scanf ("%d%d", &n, &m);
    vector <node> a(n);
    for (int i = 0; i < n; i ++) {
        scanf ("%d", &a[i].a);
        a[i].id = i;
    } int ans = 0;
    for (int msk = 0; msk < (1 << n); msk ++) {
        vector <node> b (n);
        for (int i = 0; i < n; i ++) {
            b[i] = a[i];
            if (msk >> i & 1) b[i].w = 2;
            else              b[i].w = 1;
        }
        sort (b.begin (), b.end (), comp);
        int tmp = m, lst1 = 1e9, lst2 = 1e9, l2 = 0;
        for (const auto& [x, y, id] : b) {
            if (!tmp) break ;
            if (y == 1) lst2 = lst1, lst1 = x;
            if (tmp == 1 && y == 2) l2 = max (l2, x);
            if (tmp >= y) tmp -= y;
        }
        if (tmp == 1 && l2 > lst1) continue;
        if (tmp == 0 && l2 > lst1 + lst2) continue;
        // fprintf (stderr, "msk = %d, l1 = %d, l2 = %d, ll2 = %d\n", msk, lst1, lst2, l2);
        ++ ans;
    }
    printf ("%d\n", ans);
}
}

namespace suba {
void work () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf ("%d", a + i);
    printf ("%lld\n", qpow (2, n));
}
}

namespace e2 {
void work () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf ("%d", a + i);
    sort (a + 1, a + n + 1);
    ll ans = qpow (2, n);
    for (int i = 1; i <= n; i ++) {
        if (a[n] >= a[i] * 2) continue;
        for (int j = i - 1; j >= 1; j --) 
            if (a[j] + a[i] < a[n]) (ans += p - qpow (2, j - 1)) %= p;
        
        if (a[i] < a[n]) (ans += p - 1) %= p;
    }
    printf ("%lld\n", ans);
}
}

namespace sub16 {
void work () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf ("%d", a + i);
    printf ("%lld\n", qpow (2, n));
}
}

namespace sub17 {
void work () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf ("%d", a + i);
    ll ans = qpow (2, n);
    for (int i = 1; i <= n; i ++) {
        ll mn = 1e18;
        for (int j = 1; j <= n; j ++) {
            if (i != j && a[j] < a[i] * 2) mn = min (a[j] * 1ll, mn); 
        }
        if (mn > a[i] && mn != 1e18) ans --;
    }
    printf ("%lld\n", (ans + p) % p);
}
}

namespace subb {
void work () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf ("%d", a + i);
    sort (a + 1, a + n + 1);
    ll ans = qpow (2, n);
    // for (int i = 1; i <= n; i ++) {
    //     int left = i - 1;
    //     ll coef = comb (left, m - 2);
    //     if (coef == 0) continue;
    //     ll sub = 0;
    //     for (int j = i - 1; j >= 1; j --) 
    //         if (a[i] + a[j] < )
        
    //     if (a[i] < a[n]) (ans += p - 1) %= p;
    // }
    printf ("%lld\n", ans);
}
}

int main (void) {

    // ios :: sync_with_stdio (false);
    // cin.tie (nullptr), cout.tie (nullptr);
    freopen ("sale.in", "r", stdin);
    freopen ("sale.out", "w", stdout);
    // auto st = clock ();

    int upld = 10000;
    fac[0] = 1; for (int i = 1; i <= upld; i ++) fac[i] = fac[i - 1] * i % p;
    ifac[upld] = qpow (fac[upld], p - 2); for (int i = upld - 1; ~i; i --) ifac[i] = ifac[i + 1] * (i + 1) % p;

    int testcase, t;
    scanf ("%d%d", &testcase, &t);
    if (testcase == 18) while (t --) suba :: work ();
    else if (testcase == 16) while (t --) sub16 :: work ();
    else if (testcase == 17) while (t --) sub17 :: work ();
    else if (testcase <= 5) while (t --) bf :: work ();
    else if (testcase == 7 || testcase == 8 || testcase == 9 || testcase == 14 || testcase == 15) while (t --) e2 :: work ();
    else if (testcase == 10 || testcase == 11 || testcase == 12 || testcase == 19 || testcase == 20) while (t --) subb :: work ();
    else if (testcase <= 13) while (t --) bf :: work ();
    else while (t --) work ();

    // fprintf (stderr, "Totally used %.4f ms.\n", (clock () - st) * 1000.0 / CLOCKS_PER_SEC);

    return 0;
}
#include <bits/stdc++.h>

#define mp make_pair
#define pii pair <int, int>
using ll = long long;
using ull = unsigned long long;

using namespace std;

const int N = 5e4 + 10;

int n;
int a[N];
ll s[N];

struct BIT {
    vector <ll> t;
    int n;
    void init (int x) { n = x + 5; t.assign (n + 5, 0); }
    void add (int x, ll k) { for (; x <= n; x += x & -x) t[x] += k; }
    ll qry (int x) { ll ret = 0; for (; x; x -= x & -x) ret += t[x]; return ret; }
} t;

int main (void) {

    // ios :: sync_with_stdio (false);
    // cin.tie (nullptr), cout.tie (nullptr);
    freopen ("query.in", "r", stdin);
    freopen ("query.out", "w", stdout);
    // auto st = clock ();

    scanf ("%d", &n); t.init (n)
    for (int i = 1; i <= n; i ++) scanf ("%d", a + i), s[i] = s[i - 1] + a[i];
    int q;
    while (q --) {
        int l, r; scanf ("%d%d", &l, &r);
        for (int len = l; len <= r; len ++) {
            for (int i = 1; i <= n; i ++) {
                int j = i + len - 1;
                if (j > n) break ;
                t.add (i, s[j] - s[i - 1]);
                t.add (j + 1, s[i - 1] - s[j]);
            }
        }
        ull ans = 0;
        for (int i = 1; i <= n; i ++)   
    }

    // fprintf (stderr, "Totally used %.4f ms.\n", (clock () - st) * 1000.0 / CLOCKS_PER_SEC);

    return 0;
}
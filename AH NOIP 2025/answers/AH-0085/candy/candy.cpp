#include <bits/stdc++.h>

#define mp make_pair
#define pii pair <int, int>
#define pll pair <long long, long long>
#define fi first
#define se second
using ll = long long;

using namespace std;

int n;
ll m;
vector <pll> typ;

bool comp (pll x, pll y) {
    return x.se == y.se ? x.fi * y.se < y.fi * x.se : x.se > y.se;
}

bool cmp2 (pll x, pll y) {
    return x.fi * y.se == y.fi * x.se ? x.se > y.se : x.fi * y.se < y.fi * x.se;
}

int main (void) {

    // ios :: sync_with_stdio (false);
    // cin.tie (nullptr), cout.tie (nullptr);
    freopen ("candy.in", "r", stdin);
    freopen ("candy.out", "w", stdout);
    // auto st = clock ();

    scanf ("%d%lld", &n, &m); ll t2 = 1e18;
    vector <ll> tmp, tt;
    for (int i = 1; i <= n; i ++) {
        ll x, y; scanf ("%lld%lld", &x, &y);
        if (x <= y) tmp.push_back (x);
        t2 = min (t2, (x * 1ll + y));
    }

    sort (tmp.begin (), tmp.end (), [&](auto x, auto y) { return x > y; }); 
    ll ans = 0; 
    while (tmp.size () && m >= tmp.back () && tmp.back () * 2 <= t2) ++ ans, m -= tmp.back (), typ.emplace_back (t2 - tmp.back (), 1), tmp.pop_back ();
    ans += (m / t2) * 2;
    m %= t2;
    sort (typ.begin (), typ.end ());
    for (const auto& [x, y] : typ) {
        if (m < x) break ;
        ans ++;
        m -= x;
    }

    printf ("%lld\n", ans);

    // fprintf (stderr, "Totally used %.4f ms.\n", (clock () - st) * 1000.0 / CLOCKS_PER_SEC);

    return 0;
}

//!noip@Nov29,2025:dream
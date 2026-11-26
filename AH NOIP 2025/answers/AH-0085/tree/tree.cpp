#include <bits/stdc++.h>

#define mp make_pair
#define pii pair <int, int>
using ll = long long;

using namespace std;

const int N = 8010;

int n, m;
int fa[N];
vector <int> g[N];

namespace bf {
int num[10], in[10][10];
ll ans = 0, tmp = 0;
    
void getval (int u) {
    in[u][num[u]] ++;
    for (const auto& v : g[u]) {
        getval (v);
        for (int i = 0; i <= n; i ++) in[u][i] += in[v][i];
    }
    for (int i = 0; i <= n; i ++) if (!in[u][i]) {
        tmp += i;
        break;
    }
};

void dfs (int u) {
    if (u == 8) {
        memset (in, 0, sizeof in);
        tmp = 0;
        getval (1);
        ans = max (ans, tmp);
        return ;
    }  
    for (int i = 0; i <= n; i ++) {
        num[u] = i;
        dfs (u + 1);
    }
};
void bf () {
    dfs (1);
    printf ("%lld\n", ans);
}
}

void work () {
    for (int i = 1; i <= n; i ++) fa[i] = 0, g[i].clear ();
    scanf ("%d%d", &n, &m);
    for (int i = 2; i <= n; i ++) scanf ("%d", fa + i), g[fa[i]].push_back (i);
    if (n <= 7) return bf :: bf ();
}

int main (void) {

    // ios :: sync_with_stdio (false);
    // cin.tie (nullptr), cout.tie (nullptr);
    freopen ("tree.in", "r", stdin);
    freopen ("tree.out", "w", stdout);
    // auto st = clock ();

    int t; scanf ("%d", &t);
    while (t --) work ();

    // fprintf (stderr, "Totally used %.4f ms.\n", (clock () - st) * 1000.0 / CLOCKS_PER_SEC);

    return 0;
}
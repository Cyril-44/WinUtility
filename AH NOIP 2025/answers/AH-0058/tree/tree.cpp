#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define umax(x, y) ((x) = std::max((x), (y)))
constexpr int N = 8005;
std::vector<int> g[N];
inline void read(int &n, int &M) {
    scanf("%d%d", &n, &M);
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 2, fa; i <= n; i++) {
        scanf("%d", &fa);
        g[fa].push_back(i);
    }
}
struct BF1 {
constexpr static int N = 365;
int f[N][N][N];
int n, M;
void dfs(int u) {
    int fu[N][N]{}, ftp[N][N];
    memset(fu, -0x3f, sizeof fu);
    memset(ftp, -0x3f,sizeof ftp);
    for (int i = 0; i <= n; i++) fu[i][i] = 0;
    fu[0][0] = 1;
    bool flg = true;
    for (int v : g[u]) {
        dfs(v);
        if (flg) {
            flg = false;
            memcpy(fu, f[v], sizeof(int) * N * N);
            continue;
        }
        for (int ui = 0; ui <= n; ui++)
            for (int uj = ui; uj <= n; uj++)
                for (int vi = 0; vi <= n; vi++)
                    for (int vj = vi; vj <= n; vj++) {
                        if (uj < vi-1 || vj < ui-1) continue;
                        umax(ftp[std::min(ui, vi)][std::max(uj, vj)], fu[ui][uj] + f[v][vi][vj]);
                    }
        memcpy(fu, ftp, sizeof(int) * N * N);
    }
    if (!flg)
    for (int i = 0; i <= n; i++)
        for (int j = i; j <= n; j++) {
            f[u][i][j] = std::max(
                fu[i][j],
                i != j ? std::max(
                    fu[i+1][j] + (i ? 0 : j + 1), 
                    fu[i][j-1] + (i ? 0 : j + 1)
                ) : -0x7fffffff
            );
            if (f[u][i][j] > 0) fprintf(stderr, "%d: [%d, %d] = %d\n", u, i, j, f[u][i][j]);
        }
    else memcpy(f[u], fu, sizeof(int) * N * N);
}

inline void solve() {
    read(n, M);
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = j; k <= n; k++)
                umax(ans, f[i][j][k]);
    printf("%d\n", ans);
}
};
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        (new BF1) -> solve();
    }
    return 0;
}
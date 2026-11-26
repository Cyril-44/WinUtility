#include <bits/stdc++.h>
using namespace std;

#define filename "tree"
#define multicases

#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

template<class T> bool vmax(T &a, T b) { return b > a ? (a = b, 1) : 0; }
template<class T> bool vmin(T &a, T b) { return b < a ? (a = b, 1) : 0; }

const int N = 8002;

int n, m;
vector<int> G[N];

namespace sub1 {
    const int MAXS = (1 << 18 | 2);
    int f[20][MAXS], g[MAXS];
    int mex(int S) {
        upw(i, 0, n-1) if(!(S & (1 << i))) return i;
        return n;
    }
    void DFS(int u, int fa) {
        upw(i, 1, (1 << n) - 1) f[u][i] = -inf;
        f[u][0] = 0;
        for(auto v : G[u]) if(v != fa) {
            DFS(v, u);
            upw(i, 0, (1 << n) - 1) g[i] = f[u][i], f[u][i] = -inf;
            upw(S, 0, (1 << n) - 1) if(g[S] >= 0) {
                upw(T, 0, (1 << n) - 1) if(f[v][T] >= 0) {
                    vmax(f[u][S | T], g[S] + f[v][T]);
                    //cerr << S << ' ' << T << " -> " << (S | T) << '\n';
                }
            }
        }
        upw(i, 0, (1 << n) - 1) g[i] = f[u][i], f[u][i] = -inf;
        //cerr << u << ": ";
        //upw(i, 0, (1 << n) - 1) cerr << (g[i] < 0 ? -1 : g[i]) << ' ';
        //cerr << '\n';
        upw(S, 0, (1 << n) - 1) if(g[S] >= 0) {
            upw(i, 0, n-1) vmax(f[u][S | (1 << i)], g[S] + mex(S | (1 << i)));
        }
    }
    void main() {
        DFS(1, 0);
        int ans = 0;
        upw(S, 0, (1 << n) - 1) vmax(ans, f[1][S]);
        cout << ans << '\n';
        //(i, 1, n) {
        //    upw(S, 0, (1 << n) - 1) cerr << (f[i][S] < 0 ? -1 : f[i][S]) << ' ';
        //    cerr << '\n';
        //}
    }
}

void WaterM() {
    cin >> n >> m;
    upw(i, 1, n) G[i].clear();
    upw(i, 2, n) {
        int p;
        cin >> p;
        G[p].push_back(i);
    }
    if(n <= 18) return sub1::main();
}

signed main() {
#ifdef filename
    freopen(filename".in", "r", stdin), freopen(filename".out", "w", stdout);
#endif

    signed _ = 1;
#ifdef multicases
    scanf("%d", &_);
#endif // multicases

    while(_--) WaterM();
    return 0;
}
/*
MHFGA
*/

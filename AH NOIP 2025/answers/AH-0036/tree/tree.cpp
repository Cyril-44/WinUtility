#include <bits/stdc++.h>

#define N 10010

using namespace std;

int T;
int n, m;
int fa[N];
int tag[N];
int sizz[N];
int d[N];
int dep[N];
int nxt[N << 1], head[N << 1], to[N << 1], e = 0;
int cc[N];
int ans = 0;
// bool vis[N];
int siz[N];
int c[N];
int maxx = -1, nowid;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();

    while(ch < '0' || ch > '9') {
        if(ch = '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

inline void add_edge(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

inline void dfs(int p, int pre) {
    dep[p] = dep[pre] + 1;
    if(d[p] == 1 && p != 1) { // leaf
        // q[1].push_back(p);
        c[p] = 1;
        cc[p] = 1;
        // sizz[p] = 1;
        return;
    }
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfs(v, p);
            sizz[p] += sizz[v];
            c[p] = max(c[p], c[v] + 1);
            cc[p] = min(cc[p], cc[v] + 1);
        }
    }
}

inline void dfs2(int p, int pre) {
    if(d[p] == 1 && p != 1) {
        siz[p] = 1;
        return;
    }
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfs2(v, p);
            if(c[p] == 2 && c[v] == 1)
                siz[p] += 1;
            else
                siz[p] = max(siz[p], siz[v] + 1);
        }
    }
}

inline void dfss(int p, int pre) {
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfss(v, p);
            if(cc[p] == 2 && c[p] != 2 && d[v] == 1) {
                ++ans;
            }
        }
    }
}

inline void solve() {
    memset(d, 0, sizeof(d));
    memset(fa, 0, sizeof(fa));
    memset(c, 0, sizeof(c));
    memset(siz, 0, sizeof(siz));
    memset(nxt, 0, sizeof(nxt));
    memset(head, 0, sizeof(head));
    memset(to, 0, sizeof(to));
    // vector<int> q[1010];
    e = 0;
    n = read();
    m = read();

     for(int i = 1; i <= n; ++i) {
        // vis[i] = false;
        sizz[i] = 1;
        cc[i] = 100000;
     }

    for(int i = 2; i <= n; ++i) {
        fa[i] = read();

        add_edge(i, fa[i]);
        add_edge(fa[i], i);
        ++d[i];
        ++d[fa[i]];
    }
    dep[1] = 1;
    ans = 0;
    dfs(1, 0);
    dfs2(1, 0);
    //for(int i = 1; i <= n; ++i) {
      //  writeln(dep[i]);
    //}
    dfss(1, 0);
    for(int i = 1; i <= n; ++i) {
        if(cc[i] == 2 && c[i] == 2) {
            ++ans;
        }
        if(d[i] != 1 || i == 1) {
            ans += siz[i] + 1;
        }
    }
    writeln(ans);
    return;
}

int main() {

    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    T = read();

    while(T--) {
        solve();
    }

    return 0;
}

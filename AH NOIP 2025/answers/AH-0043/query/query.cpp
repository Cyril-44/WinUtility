//exam: query
#include <iostream>
#include <cstdio>
#define int long long
#define OI "query"
using namespace std;
const int MAXN = 5e4+5;
const __int128 P = (__int128(1) << 64);
void print(__int128);
__int128 f[MAXN];
int a[MAXN];
int n, q;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        __int128 res = 0;
        for(int i = 1; i <= n; i++) {
            __int128 maxn = -1e5;
            for(int lft = 1; lft <= i; lft++) {
                for(int len = l; len <= r; len++) {
                    int rht = lft + len - 1;
                    if(rht >= i) {
                        maxn = max(maxn, f[rht] - f[lft - 1]);
                    }
                }
            }
            res ^= (i * maxn + P) % P;
        }

        print(res);
    }
    return 0;
}
void print(__int128 x) {
    if(x == 0) {
        cout << 0 << endl;
        return ;
    }
    string s = "";
    if(x < 0) {
        cout << '-';
        x *= -1;
    }
    while(x) {
        s = char(x % 10 + '0') + s;
        x /= 10;
    }
    cout <<s << endl;
}
/*
解题报告：
T1
一上来感觉像是背包，但是时间复杂度 O(nm)，空间复杂度 O(m), 都炸了，不过从部分分来看，65 分是可以到手的。
背包的话思路就是一个关键点：只拿一个是下策，一定是最后才使用的办法，首先我们考虑两个两个拿。
那么我们就可以用一个多重背包和一个 01 背包解决问题了。
大样例除了最后一个都是正确的，先拿个 65 分到手。

 code:

//exam: candy
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
//#define OI "candy"
using namespace std;
struct node {
    int x, y, z;
};
const int MAXN = 1e5+5;
vector<int> f, g;
node a[MAXN];
int n, m;
int res;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].z = a[i].x + a[i].y;
    }

    f.resize(m + 1), g.resize(m + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = a[i].z; j <= m; j++) {
            f[j] = max(f[j], f[j - a[i].z] + 2);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= a[i].x; j--) {
            g[j] = max(g[j], g[j - a[i].x] + 1);
        }
    }

    for(int i = 1; i <= m; i++) {
        f[i] = max(f[i], f[i - 1]);
        g[i] = max(g[i], g[i - 1]);
    }
    for(int i = 0; i <= m; i++) {
        res = max(res, f[i] + g[m - i]);
    }

    cout << res;
    return 0;
}

那么，如果不是 DP，我们考虑贪心。
如何贪心？也许我们可以延续之前的思路，只取一个是下策，能取两个就取两个，然后都尽量取代价较小的，以求能多取一点，但是这样就是错的。

code :

//exam: candy
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define OI "candy"
using namespace std;
struct node {
    int x, y;
    bool operator < (const node &nxt) const {
        return x < nxt.x;
    }
};
const int MAXN = 1e5+5;
node a[MAXN];
int p[MAXN];
int n, m;
int res;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    //freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        p[i] = a[i].x + a[i].y;
    }

    sort(p + 1, p + 1 + n);
    for(int i = 1; i <= n; i++) {
        res += (m / p[i]) * 2;
        m %= p[i];
    }

    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        if(a[i].x <= m) {
            res++;
            m -= a[i].x;
        }
    }

    cout << res;
    return 0;
}

但是，我灵机一动，在推反例的时候觉得这个贪心思路非常的合理，因为我肯定会选择去购买价值比较小的物品，而不是选择更加昂贵的物品，很显然，买便宜的大概率能多买一点，如果把一个便宜的换成一个昂贵的，我捞不到一点好处。
同样是优先两个两个购买，但是我只买 x + y 最便宜的那种，枚举我能买多少个，剩下的直接二分查找买多少个一个的就好了。

//exam: candy
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define OI "candy"
using namespace std;
struct node {
    int x, y;
    bool operator < (const node &nxt) const {
        return x < nxt.x;
    }
};
const int MAXN = 1e5+5;
node a[MAXN];
int p[MAXN], f[MAXN];
int n, m, x;
int res;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    //freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> n >> m; x = m + 1;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        p[i] = a[i].x + a[i].y;
        x = min(p[i], x);
    }

    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i].x;
        //cout << f[i] << " ";
    }
    //cout << endl;

    for(int i = 0; i * x <= m; i++) {
        res = max(res, i * 2 + (upper_bound(f, f + 1 + n, m - i * x) - f - 1));
        //cout << i << " " << (upper_bound(f, f + 1 + n, m - i * x) - f - 1) << endl;
    }

    cout << res;
    return 0;
}

不过，假如 x = 2，m = 1e18 呢？那么这个算法的时间复杂度就是 O(m)，过不了。不过很简单，我们只需要把枚举买两个的个数变成直接枚举哪些东西买一个就好了。

code :

//exam: candy
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define OI "candy"
using namespace std;
struct node {
    int x, y;
    bool operator < (const node &nxt) const {
        return x < nxt.x;
    }
};
const int MAXN = 1e5+5;
node a[MAXN];
int p[MAXN], f[MAXN];
int n, m, x;
int res;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    //freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> n >> m; x = m + 1;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        p[i] = a[i].x + a[i].y;
        x = min(p[i], x);
    }

    sort(a + 1, a + 1 + n);
    res = m / x * 2;
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i].x;
        res = max(res, i + (m - f[i]) / x * 2);
    }

    cout << res;
    return 0;
}

现在有一个需要解决的问题：为什么靠前的东西我一定要买呢？这很显然了，因为我希望的是买尽可能多的，不关心具体买什么，或者说所有的代价付出得到的回报都是 1，那么假如我买了一个更大的而不买小的，那么就会导致代价减少！
那么，我们故切认为这道题我们的做法是正确的。

T2
计数题，但是我的计数题出奇地差。
首先值得注意的是 case A：所有的 ai 相等，那么表明我无论如何赋值都能得到最优解，答案显而易见。

code :

//exam: sale
#include <iostream>
#include <cstdio>
#define int long long
//#define OI "sale"
using namespace std;
const int MAXN = 5005, P = 998244353;
int qpow(int, int);
int a[MAXN];
int c, t, n, m;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> c >> t;
    while(t--) {
        cin >> n >> m;

        bool flagA = true; // for case A;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(i > 1 && a[i] != a[i - 1]) {
                flagA = false;
            }
        }
        if(flagA) {
            cout << qpow(2, n) << endl;
            continue;
        }
    }
    return 0;
}
int qpow(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) {
            res = res * x % P;
        }
        x = x * x % P;
        y >>= 1;
    }
    return res;
}

那么，我们尝试用暴力解决问题，先按照要求计算答案，接着用背包算出真实答案，比较一下就好了，预期得分 20 pts。
吐槽一下，今天怎么全在用背包骗分？

code :
//exam: sale
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define OI "sale"
using namespace std;
const int MAXN = 5005, P = 998244353;
int qpow(int, int);
bool cmp(int, int);
int a[MAXN], w[MAXN], id[MAXN];
int c, t, n, m;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> c >> t;
    while(t--) {
        cin >> n >> m;

        bool flagA = true; // for case A;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(i > 1 && a[i] != a[i - 1]) {
                flagA = false;
            }
        }
        if(flagA) {
            cout << qpow(2, n) << endl;
            continue;
        }

        int cnt = 0;

        for(int S = 0; S < (1 << n); S++) {
            for(int i = 1; i <= n; i++) {
                w[i] = ((S >> (i - 1)) & 1) + 1;
                id[i] = i;
            }

            sort(id + 1, id + 1 + n, cmp);

            int val = 0, rest = m;
            for(int i = 1; i <= n; i++) {
                if(rest >= w[id[i]]) {
                    rest -= w[id[i]];
                    val += a[id[i]];
                }
            }

            vector<int> f(m + 1);
            int maxn = 0;
            for(int i = 1, flag = true; i <= n && flag; i++) {
                for(int j = m; j >= w[i]; j--) {
                    f[j] = max(f[j], f[j - w[i]] + a[i]);
                    maxn = max(maxn, f[j]);
                    if(maxn > val) {
                        flag = false;
                        break;
                    }
                }
            }

            if(val == maxn) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
int qpow(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) {
            res = res * x % P;
        }
        x = x * x % P;
        y >>= 1;
    }
    return res;
}
bool cmp(int x, int y) {
    if(a[x] * w[y] != a[y] * w[x]) {
        return a[x] * w[y] > a[y] * w[x];
    } else if(a[x] != a[y]) {
        return a[x] > a[y];
    } else {
        return x < y;
    }
}

T3
考虑到一个点的 mex 恰好表示这棵树上有 0 ~ mex - 1 的所有点权，所以贪心，但是贪错了。

code :
//exam: tree
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define int long long
#define OI "tree"
using namespace std;
const int MAXN = 8005;
void dfs(int);
vector< vector<int> > g;
int mex[MAXN], a[MAXN];
int t, n, m;
signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    //freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> t;
    while(t--) {
        memset(mex, 0, sizeof(mex));
        memset(a, 0, sizeof(a));

        cin >> n >> m;

        g.clear();
        g.resize(n + 1);

        for(int u = 2, fa; u <= n; u++) {
            cin >> fa;
            g[fa].push_back(u);
        }

        dfs(1);

        int res = 0;
        for(int i = 1; i <= n; i++) {
            //cout << i << ":" << a[i] << " " << mex[i] << endl;
            res += mex[i];
        }

        cout << res << endl;
    }
    return 0;
}
void dfs(int u) {
    int maxn = 1;
    for(auto v : g[u]) {
        dfs(v);
        maxn = max(maxn, mex[v]);
    }

    int t = maxn - 1;
    bool flag = false;
    for(auto v : g[u]) {
        if(flag || mex[v] != maxn) {
            a[v] = ++t;
            mex[v]--;
        } else {
            flag = true;
        }
    }

    a[u] = maxn - 1 + g[u].size();
    mex[u] = a[u] + 1;
}
*/

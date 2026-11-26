#include <bits/stdc++.h>
using namespace std;

#define filename "query"
//#define multicases

#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

template<class T> bool vmax(T &a, T b) { return b > a ? (a = b, 1) : 0; }
template<class T> bool vmin(T &a, T b) { return b < a ? (a = b, 1) : 0; }

const int N = 5e4+2;

#define int long long

int n, a[N], q;

namespace sub1 {
    int sum[N];
    int st[N], top;
    int ans[N];
    void main() {
        upw(i, 1, n) sum[i] = sum[i-1] + a[i];
        //upw(i, 1, n) cerr <<sum[i] << ' ';
        //cerr << '\n';
        upw(round, 1, q) {
            int L, R;
            cin >> L >> R;
            upw(i, 1, n) ans[i] = -Linf;
            upw(i, 1, n) {
                top = 0;
                st[0] = i-1;
                upw(j, i+L-1, min(n, i+R-1)) {
                    while(top && sum[j] >= sum[st[top]]) --top;
                    st[++top] = j;
                }
                upw(j, 1, top) upw(k, st[j-1] + 1, st[j]) vmax(ans[k], sum[st[j]] - sum[i-1]);
                //upw(j, 1, top) cerr << st[j] << ' ';
                //cerr << '\n';
            }
            //upw(i, 1, n) cerr <<ans[i] << ' ';
            //cerr << '\n';
            //cerr << '\n';
            unsigned long long res = 0;
            upw(i, 1, n) res ^= (unsigned long long)(i) * ans[i];
            cout << res << '\n';
        }
    }
}

void WaterM() {
    cin >> n;
    upw(i, 1, n) cin >> a[i];
    cin >> q;
    sub1::main();
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

#include <bits/stdc++.h>
using namespace std;

#define filename "candy"
//#define multicases

#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

template<class T> bool vmax(T &a, T b) { return b > a ? (a = b, 1) : 0; }
template<class T> bool vmin(T &a, T b) { return b < a ? (a = b, 1) : 0; }

const int N = 1e5+2;

#define int __int128

long long n, m;
long long x[N], y[N];

void WaterM() {
    cin >> n >> m;
    upw(i, 1, n) scanf("%lld%lld", &x[i], &y[i]);

    int cand = Linf;
    upw(i, 1, n) vmin(cand, (__int128)x[i] + y[i]);
    vector<int> va, vb;
    upw(i, 1, n) {
        if(x[i] <= (cand >> 1)) va.push_back(x[i]);
        else vb.push_back(x[i]);
    }
    sort(all(va)), sort(all(vb));

    auto calc = [&] (int cnt)->int {
        int tot = 0;
        if(cnt <= (int)va.size()) {
            upw(i, 0, cnt - 1) tot += va[i];
            return tot;
        }
        upw(i, 0, (int)va.size() - 1) tot += va[i];
        int rem = cnt - (int)va.size();
        if(rem % 2 == 0) {
            return tot + rem / 2 * cand;
        }
        //cerr << tot << '\n';
        tot += (rem + 1) / 2 * cand;
        int val1 = va.empty() ? Linf : -va.back();
        int val2 = vb.empty() ? Linf : vb[0] - cand;
        tot += min(val1, val2);
        return tot;
    };
    //cerr << calc(4) << '\n' << calc(5) << '\n';
    //return;

    int L = 0, R = 1e18;
    R += 2;
    while(L < R) {
        int mid = L + R + 1 >> 1;
        //cerr << L << ' ' << R << '\n';
        if(calc(mid) <= m) L = mid;
        else R = mid - 1;
        //cerr << calc(mid) << '\n';
    }
    cout << (long long)L << '\n';
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

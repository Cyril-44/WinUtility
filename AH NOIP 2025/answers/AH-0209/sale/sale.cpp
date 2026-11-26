#include <bits/stdc++.h>
#define int long long
using namespace std;
const int LEN = 5000 + 5, mod = 998244353;
int n, m, a[LEN], w[LEN], ans = 0;
double d[LEN];
void solve_A()
{
    ans = 1;
    for (int i = 1; i <= n; i++)
        ans = ans * 2 % mod;
}
// void make_max(int money, int p, int v)
// {
//     if (p == n + 1)
//     {

//     }
//     else if (money >= w[p])
//         return max(make_max(money - w[p], p + 1, v + a[p]),make_max(money, p + 1, v));
//     else
//         return make_max(money, p + 1, v);
// }
// void solve(int p)
// {
//     if (p == n + 1)
//     {
//         for (int i = 1; i <= n; i++)
//             d[i] = 1.0 * a[i] / w[i];
//         while (1)
//         {
//             for
//         }
//         make_max(m, 1, 0);
//     }
//     else
//     {
//         w[p] = 1;
//         solve(p + 1);
//         w[p] = 2;
//         solve(p + 1);
//     }
// }
signed main()
{
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        ans = 0;
        cin >> n >> m;
        int sub_A = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i > 1 && a[i] != a[i - 1])
                sub_A = 0;
        }
        // if (sub_A)
            // solve_A();
        // else
            // solve(1);
        solve_A();
        cout << ans << "\n";
    }
    return 0;
}
// 12:11 看 t2（其实已经看过一边然后回 t1 了
// 12:14 新机器可以跑 1s 2^{5 \times 10^4} 吗 awa
// 自带输入法真难用
// 12:20 意思就是先取所有 w=1 确定选定买哪些糖果？
// 哦确定的是原价总和
// 12:24 诶不对啊 看不懂样例解释
// 哦当前价格下的最大。
// 12:27 等下，T 没范围
// 前面的测试点都是 N <= 5,000？？？
// ber 那 2^n 暴力没分了啊
// 哦是 100 \times 2^5，有分的
//
// 12:38 性质 A 随便蒙了一个结论，希望是对的
// 12:58 暴力打不完了，摆了
//
// 关注洛谷 uid:1058565 Wxygen 喵
// Luogu，享受 Coding 的快乐
//
// CCCCCCCC   CCCCCCCC   FFFFFFFF
// CC         CC         FF
// CC         CC         FF
// CC         CC         FFFFFFFF
// CC         CC         FF
// CC         CC         FF
// CCCCCCCC   CCCCCCCC   FF
//
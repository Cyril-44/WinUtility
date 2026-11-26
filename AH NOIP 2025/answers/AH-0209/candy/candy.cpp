#include <bits/stdc++.h>
using namespace std;
#define int long long
const int LEN = 1e5 + 5;
int n, m, ans = 0, v[LEN];
struct kkk
{
    int x, y, sum;
    bool operator<(const kkk &node) { return sum < node.sum; }
} a[LEN];
signed main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        v[i] = a[i].x;
        a[i].sum = a[i].x + a[i].y;
    }
    sort(a + 1, a + n + 1);
    sort(v + 1, v + n + 1);
    // cout << "== a start ==\n";
    // for (int i = 1; i <= n; i++)
    //     printf("i:%3lld x:%3lld y:%3lld sum:%3lld\n", i, a[i].x, a[i].y, a[i].sum);
    // cout << "== a end ==\n\n";
    // cout << "== v start ==\n";
    // for (int i = 1; i <= n; i++)
    //     cout << v[i] << "\n";
    // cout << "== v end ==\n";
    int p = 1;
    while (p <= n && m >= v[p] && v[p] < min(a[1].x, a[1].y))
    {
        m -= v[p];
        ans++;
        p++;
    }
    // cout << m << " " << ans << "\n";
    ans += m / a[1].sum * 2;
    m = m % a[1].sum;
    // cout << m << " " << ans << "\n";
    while (p <= n && m >= v[p])
    {
        m -= v[p];
        ans++;
        p++;
    }
    int temp = ans;
    while (p <= n && v[p] <= max(a[1].x, a[1].y))
    {
        m += a[1].sum;
        temp -= 2;
        while (m >= v[p] && p <= n)
        {
            m -= v[p];
            p++;
            temp++;
        }
        ans = max(ans, temp);
    }
    cout << ans << "\n";
    return 0;
}
// 9:24 发现做法有点小问题，好像比 a[1].y 小的优先取，下面好像是假的，样例 4 过不了，感谢大样例
/*
for (int i = 1; i <= n; i++)
{
    cin >> a[i].x >> a[i].y;
    v[i] = a[i].x;
    a[i].sum = a[i].x + a[i].y;
}
sort(a + 1, a + n + 1);
sort(v + 1, v + n + 1);
ans = m / a[1].sum * 2;
m = m % a[1].sum;
int p = 1;
while (m >= v[p])
{
    m -= v[p];
    ans++;
    p++;
}
*/
//
// 9:31 调完的还是假的，样例 6 输出 81
/*
for (int i = 1; i <= n; i++)
{
    cin >> a[i].x >> a[i].y;
    v[i] = a[i].x;
    a[i].sum = a[i].x + a[i].y;
}
sort(a + 1, a + n + 1);
v[n + 1] = a[1].y;
sort(v + 1, v + n + 2);
// cout << "== a start ==\n";
// for (int i = 1; i <= n; i++)
//     printf("i:%3lld x:%3lld y:%3lld sum:%3lld\n", i, a[i].x, a[i].y, a[i].sum);
// cout << "== a end ==\n\n";
// cout << "== v start ==\n";
// for (int i = 1; i <= n; i++)
//     cout << v[i] << "\n";
// cout << "== v end ==\n";
ans = m / a[1].sum * 2 - 1;
m = m % a[1].sum + a[1].y;
int p = 1;
while (m >= v[p])
{
    m -= v[p];
    ans++;
    p++;
}
cout << ans;
return 0;
*/
// 9:54 我会用 linux 命令了！样例1 7有问题
/*
system("cp ~/桌面/candy/candy1.in ~/AH-0209/candy");
system("cp ~/桌面/candy/candy1.ans ~/AH-0209/candy");

system("rm candy.in");
system("rm candy.ans");
system("mv candy1.in candy.in");
system("mv candy1.ans candy.ans");
system("./candy.exe");
system("diff candy.out candy.ans");
cout << "样例1比较完毕\n";
*/
// 奇怪样例1没问题阿
/*
样例1比较完毕
1c1
< 100014
---
> 8
样例2比较完毕
样例3比较完毕
样例4比较完毕
样例5比较完毕
样例6比较完毕
1c1
< 1606
---
> 1620
样例7比较完毕
*/
// 10:02 哦是不是取过 a[1].y 一次后可以再取一次 a[1].x
// 不对啊怎么差了 14 来着
// 10:08 要是 y < x 是不是 x 没取就取 y 了
// 10:21 原来是因为样例 1 RE 了，现在只有 7 不过了。。。AFO
// 坏了没有特殊性质 B 样例，B 性质的好像为都过不了
// 原来样例 1 之前能过是因为错错得对了
// 10:42 放弃了，样例 6 7 不过
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
// freopen("candy.in", "r", stdin);
// freopen("candy.out", "w", stdout);
//
// =================================================
//
// 11:34 是的我又回来了 qwq
// 后面看着没啥思路
// 存个档
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int LEN = 1e5 + 5;
int n, m, ans = 0, v[LEN];
struct kkk
{
    int x, y, sum;
    bool operator<(const kkk &node) { return sum < node.sum; }
} a[LEN];
signed main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        v[i] = a[i].x;
        a[i].sum = a[i].x + a[i].y;
    }
    sort(a + 1, a + n + 1);
    // v[n + 1] = a[1].y;
    // sort(v + 1, v + n + 2);
    sort(v + 1, v + n + 1);
    // cout << "== a start ==\n";
    // for (int i = 1; i <= n; i++)
    //     printf("i:%10lld x:%10lld y:%10lld sum:%10lld\n", i, a[i].x, a[i].y, a[i].sum);
    // cout << "== a end ==\n\n";
    // cout << "== v start ==\n";
    // for (int i = 1; i <= n; i++)
    //     cout << v[i] << "\n";
    // cout << "== v end ==\n";
    if (m < v[1])
    {
        cout << 0;
        return 0;
    }
    int p = 1;
    if (m < a[1].sum)
    {
        while (m >= v[p] && p <= n)
        {
            m -= v[p];
            ans++;
            p++;
        }
        cout << ans << "\n";
        return 0;
    }
    if (a[1].x < a[1].y)
    {
        ans = m / a[1].sum * 2 - 2;
        m = m % a[1].sum + a[1].sum;
        int flag_x = 0, flag_y = 0;
        while (m >= v[p] && p <= n)
        {
            m -= v[p];
            if (flag_x == 0 && v[p] == a[1].x)
            {
                n++;
                v[n] = a[1].y;
                sort(v + p + 2, v + n + 1);
                flag_x = 1;
            }
            else if (flag_x == 1 && flag_y == 0 && v[p] == a[1].y)
            {
                n++;
                v[n] = a[1].x;
                sort(v + p + 2, v + n + 1);
                flag_y = 1;
            }
            ans++;
            p++;
        }
    }
    else
    {
        ans = m / a[1].sum * 2;
        m = m % a[1].sum;
        while (m >= v[p] && p <= n)
        {
            m -= v[p];
            ans++;
            p++;
        }
    }
    cout << ans << "\n";
    return 0;
}
*/
// 11:42 稍微打了一点 样例 1 2 3 过了
// 11:49 调了一下，只剩 6
/*
1c1
< 81
---
> 83
样例6比较完毕
*/
// 11:55 en?为什么 6 手算是对的
// 11:57 手算错了。。。
/*
int p = 1;
while (m >= v[p] && v[p] < min(a[1].x, a[1].y) && p <= n)
{
    m -= v[p];
    ans++;
    p++;
}
cout << m << " " << ans << "\n";
ans += m / a[1].sum * 2;
m = m % a[1].sum;
cout << m << " " << ans << "\n";
while (m >= v[p] && p <= n)
{
    m -= v[p];
    ans++;
    p++;
}
cout << ans << "\n";
*/
// 11：59 有思路了
// 12:05 样例全过祭
/*
noi@noi-Veriton-D430:~/AH-0209/candy$ ./t.exe
样例1比较完毕
样例2比较完毕
样例3比较完毕
样例4比较完毕
样例5比较完毕
样例6比较完毕
样例7比较完毕
*/
// 纪念一下，然后放一下 test.cpp
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    system("cp ~/桌面/candy/candy1.in ~/AH-0209/candy");
    system("cp ~/桌面/candy/candy1.ans ~/AH-0209/candy");
    
    system("rm candy.in");
    system("rm candy.out");
    system("rm candy.ans");
    system("mv candy1.in candy.in");
    system("mv candy1.ans candy.ans");
    system("./candy.exe");
    system("diff candy.out candy.ans");
    cout << "样例1比较完毕\n";

    system("cp ~/桌面/candy/candy2.in ~/AH-0209/candy");
    system("cp ~/桌面/candy/candy2.ans ~/AH-0209/candy");
    
    system("rm candy.in");
    system("rm candy.ans");
    system("mv candy2.in candy.in");
    system("mv candy2.ans candy.ans");
    system("./candy.exe");
    system("diff candy.out candy.ans");
    cout << "样例2比较完毕\n";

    system("cp ~/桌面/candy/candy3.in ~/AH-0209/candy");
    system("cp ~/桌面/candy/candy3.ans ~/AH-0209/candy");
    
    system("rm candy.in");
    system("rm candy.ans");
    system("mv candy3.in candy.in");
    system("mv candy3.ans candy.ans");
    system("./candy.exe");
    system("diff candy.out candy.ans");
    cout << "样例3比较完毕\n";

    system("cp ~/桌面/candy/candy4.in ~/AH-0209/candy");
    system("cp ~/桌面/candy/candy4.ans ~/AH-0209/candy");
    
    system("rm candy.in");
    system("rm candy.ans");
    system("mv candy4.in candy.in");
    system("mv candy4.ans candy.ans");
    system("./candy.exe");
    system("diff candy.out candy.ans");
    cout << "样例4比较完毕\n";

    system("cp ~/桌面/candy/candy5.in ~/AH-0209/candy");
    system("cp ~/桌面/candy/candy5.ans ~/AH-0209/candy");
    
    system("rm candy.in");
    system("rm candy.ans");
    system("mv candy5.in candy.in");
    system("mv candy5.ans candy.ans");
    system("./candy.exe");
    system("diff candy.out candy.ans");
    cout << "样例5比较完毕\n";

    system("cp ~/桌面/candy/candy6.in ~/AH-0209/candy");
    system("cp ~/桌面/candy/candy6.ans ~/AH-0209/candy");
    
    system("rm candy.in");
    system("rm candy.ans");
    system("mv candy6.in candy.in");
    system("mv candy6.ans candy.ans");
    system("./candy.exe");
    system("diff candy.out candy.ans");
    cout << "样例6比较完毕\n";

    system("cp ~/桌面/candy/candy7.in ~/AH-0209/candy");
    system("cp ~/桌面/candy/candy7.ans ~/AH-0209/candy");
    
    system("rm candy.in");
    system("rm candy.ans");
    system("mv candy7.in candy.in");
    system("mv candy7.ans candy.ans");
    system("./candy.exe");
    system("diff candy.out candy.ans");
    cout << "样例7比较完毕\n";
    return 0;
}
*/
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
// freopen("candy.in", "r", stdin);
// freopen("candy.out", "w", stdout);
//
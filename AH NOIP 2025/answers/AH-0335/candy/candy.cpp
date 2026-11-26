#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;
typedef long long ll;
int n, ct, mn = 2000000005;
ll m, cnt;
struct node{
    int p1, p2, sum;
}a[MAXN];
struct node2{
    int tmp, id;
}b[MAXN];
bool cmp(node2 x, node2 y) {
    return x.tmp<y.tmp;
}
bool cmp2(node x, node y) {
    return x.p1<y.p1;
}
int main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i].p1 >> a[i].p2;
        b[i].tmp = a[i].p1;
        b[i].id = i;
        a[i].sum = a[i].p1+a[i].p2;
        mn = min(mn, a[i].sum);
    }
    sort(b+1, b+1+n, cmp);
    for(int i=1; i<=n; i++) {
        if(b[i].tmp+b[i+1].tmp<mn) {
            if(m>=b[i].tmp) {
                m -= b[i].tmp;
                cnt ++;
                swap(a[b[i].id].p1, a[b[i].id].p2);
            }
        } else {
            break;
        }
    }
    ll num = m/mn;
    cnt += 2*num;
    m -= num*mn;
    sort(a+1, a+1+n, cmp2);
    for(int i=1; i<=n; i++) {
        if(m>=a[i].p1) {
            m -= a[i].p1;
            cnt ++;
        } else {
            break;
        }
    }
    cout << cnt;
    return 0;
}

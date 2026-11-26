#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 8005;
int T;
int n, m;
struct node{
    int pa;
    vector<int> ch;
    ll maxv;
    int num;
    int depth;
    int num2;
    ll maxv2;
} t[N];
void init(){
    for (int i = 0; i < N; i++) t[i].ch.clear();
}
void input(){
    cin >> n >> m;
    t[1].depth = 1;
    for (int i = 2; i <= n; ++i){
        int p;
        cin >> p;
        t[i].pa = p; t[p].ch.push_back(i);
        t[i].depth = t[p].depth+1;
    }
}
void dfs(int u){
    if (t[u].ch.empty()){
        t[u].maxv2 = t[u].maxv = t[u].num2 = t[u].num = 1; return;
    }
    t[u].num = 1;
    t[u].num2 = 1;
    t[u].maxv2 = 0;
    ll cnt = 0; int depth = t[u].depth;
    // int maxnum = -1; ll val = 0;
    // int num = 0;
    // int valnum = 0;
    // int maxnum2 = 0;
    // int valt = -1;

    ll maxv = 0, maxv2 = 0;
    int maxvi = -1, maxv2i = -1;
    for (int v: t[u].ch){
        dfs(v);
        t[u].maxv2 = max(t[u].maxv2, t[v].maxv2);
        t[u].num += t[v].num;
        if (t[v].maxv + (t[v].num2)*depth > maxv){
            maxv = t[v].maxv + (t[v].num2)*depth;
            maxvi = v;
        }
        if (t[v].maxv2 + (t[v].num) * depth > maxv2){
            maxv2 = t[v].maxv2 + (t[v].num) * depth;
            maxv2i = v;
        }
        // maxnum = max(maxnum, t[v].num);
        // if (t[v].maxv >= (t[v].num + 1) * depth){
        //     cnt += t[v].maxv;
        //     maxnum2 = max(maxnum2, t[v].num2);
        // } else {
        //     // if (t[v].maxv - (t[v].num - t[v].num2)*depth > val){
        //     //     val = t[v].maxv;
        //     //     valnum = t[v].num - t[v].num2;
        //     // }
        //     if (t[v].maxv - (t[v].num - t[v].num2)*depth > val){
        //         valt = 1;
        //         val = t[v].maxv - (t[v].num - t[v].num2)*depth;
        //         valnum = t[v].num - t[v].num2;
        //     }
        //     if (t[v].maxv2 > val){
        //         valt = 0;
        //         val = t[v].maxv2; valnum = 0;
        //     }
        //     num += t[v].num;
        // }
    }
    int ign = 0,maxnum2 = 0;
    if (maxv > maxv2){
        cnt += t[maxvi].maxv;
        ign = maxvi;
        maxnum2 = t[maxvi].num2;
    } else {
        cnt += t[maxv2i].maxv2;
        ign = maxv2i;
        maxnum2 = t[maxv2i].num;
    }
    for (int v: t[u].ch){
        if (v == ign) continue;
        if (t[v].maxv > (t[v].num)*depth){
            cnt += t[v].maxv;
            if (t[v].num2 > maxnum2) maxnum2 = t[v].num2;
        } else {
            t[u].num2 += t[v].num;
        }
    }
    t[u].num2 += maxnum2;
    // if (num == 0) num = maxnum2;
    // else if (maxnum2 == 0){
        // cnt += val;}
    // else num += maxnum2;
    t[u].maxv2 += t[u].num;
    // t[u].num2 = num + 1;
    // if (valt==1&& maxnum2==0) t[u].num2 -= valnum;
    t[u].maxv = cnt + t[u].num2;
    // if (t[u].maxv != t[u].maxv2) cerr << 1;
    // printf("#%d %lld %d %d %d\n", u, t[u].maxv, t[u].num, t[u].maxv2, t[u].num2);
}
void solve(){
    dfs(1);
    cout << t[1].maxv << '\n';
}
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> T;
    for (int i = 0; i < T; i++){
        init();
        input();
        solve();
    }
    return 0;
}
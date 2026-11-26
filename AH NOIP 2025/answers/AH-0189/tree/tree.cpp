#include<bits/stdc++.h>

using namespace std;

struct node{
    int p, d, num, id;
    int son[8005], cnt;
}a[8005], c[8005];

int t, n, m;
int b[8005];
long long ans = -0x3f3f3f3f;

void dfs(int idx){
    b[a[idx].num]++;

    for(int i=1; i<=a[idx].cnt; i++){
        dfs(a[idx].son[i]);
    }

    return ;
}

long long Sson(int idx){
    memset(b, 0, sizeof(b));

    dfs(idx);

    for(int i=0; i<=n; i++){
        if(b[i] == 0){
            return i;
        }
    }
}

long long answer(){
    long long sum = 0;
    for(int i=1; i<=n; i++){
        sum += Sson(i);
    }
    return sum;
}

void f(int idx){
    if(idx > n){
        for(int i=1; i<=n; i++){
            a[i].num = c[i].num;
        }
        ans = max(ans, answer());
        return ;
    }

    for(int i=0; i<=n; i++){
        c[idx].num = i;
        f(idx+1);
    }
    return ;
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=2; i<=n; i++){
            cin >> a[i].p;
            a[i].id = i;
            a[a[i].p].son[++a[a[i].p].cnt] = i;
        }
        f(1);
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

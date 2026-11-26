#include<bits/stdc++.h>

using namespace std;

struct ca{
    int w, s, id;
}a[5005], d[5005];

int c, t, n, m, cnt;
bool flag;
int x[5005], y[5005];
int check = -1;

void g(int idx){
    if(idx > n){
        for(int i=1; i<=n; i++){
            x[i] = y[i];
        }
        bool fla = false;
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                if(y[j] == y[i]){
                    fla = true;
                }
            }
        }
        if(!fla){
            int sum = 0;
            for(int i=1; i<=n; i++){
                int j = x[i];
                if(m >= a[j].w){
                    sum += a[j].s;
                    sum %= 998244353;
                }
            }
            check = max(check, sum);
        }
        return ;
    }

    for(int i=1; i<=n; i++){
        y[idx] = i;
        g(idx+1);
    }
    return ;
}

bool cmp(ca x, ca y){
    if((double)(x.s)/(double)(x.w) != (double)(y.s)/(double)(y.w)){
        return (double)(x.s)/(double)(x.w) > (double)(y.s)/(double)(y.w);
    }
    if(x.s != y.s){
        return x.s > y.s;
    }
    return x.id < y.id;
}

long long answer(){
    long long sum = 0;
    sort(a+1, a+n+1, cmp);
    for(int i=1; i<=n; i++){
        if(m >= a[i].w){
            sum += a[i].s;
            sum %= 998244353;
        }
    }
    return sum;
}

void f(int idx){
    if(idx > n){
        for(int i=1; i<=n; i++){
            a[i].w = d[i].w;
        }
        g(1);
        if(answer() == check){
            cnt ++;
        }
        return ;
    }

    for(int i=1; i<=2; i++){
        d[idx].w = i;
        f(idx+1);
    }
    return ;
}

int main(){
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> m;
        flag = false;
        for(int i=1; i<=n; i++){
            cin >> a[i].s;
            if(a[i].s != a[1].s){
                flag = true;
            }
        }
        if(!flag){
            long long ans = 1;
            for(int i=1; i<=n; i++){
                ans *= 2;
                ans %= 998244353;
            }
            cout << ans;
        }else{
            f(1);
            cout << cnt;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

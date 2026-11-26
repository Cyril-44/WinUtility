#include<bits/stdc++.h>

using namespace std;

struct ca{
    int c, d;
}a[100005];

int n, m, x[100005], y[100005];//x 奇数，y 偶数
long long f[1005][10005];
long long g[100000005];
bool flag;

bool cmp(ca x, ca y){
    if(x.c != y.c)
        return x.c < y.c;
    return x.d < y.d;
}

int main(){
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    cin >> n >> m;
    flag = false;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
        a[i].c = x[i], a[i].d = y[i];
        if(x[i] != y[i]){
            flag = true;
        }
    }
    if(!flag){//A
        for(int i=1; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(j >= x[i]){
                    g[j] = max(g[j], g[j-x[i]]+1);
                }
            }
        }
        cout << g[m];
    }else{
        sort(a+1, a+n+1, cmp);
        for(int i=1; i<=n; i++){
            x[i] = a[i].c;
            y[i] = a[i].d;
        }
        for(int i=1; i<=n; i++){
            int cnt = 1;
            int o = x[i];
            for(int j=o; j<=m; j+=o){
                f[i][j] = max(f[i-1][j], max(f[i-1][j-o]+1, f[i][j-o]+1));
                cnt++;
                if(cnt %2 == 1){
                    o = x[i];
                }else{
                    o = y[i];
                }
            }
            for(int j=x[i]; j<=m; j++){
                if(f[i][j] == 0){
                    f[i][j] = max(f[i-1][j], max(f[i-1][j-o]+1, f[i][j-1]));
                }
            }
        }
        //for(int i=0; i<=n; i++){
        //    for(int j=0; j<=m; j++){
         //       cout << f[i][j] << " ";
        //    }
         //   cout << endl;
        //}
        cout << f[n][m];
        /*for(int i=1; i<=n; i++){
            for(int j=0; j<=m; j++){
                b[i][j] = b[i][j-1];
                if((b[i][j]+1) %2 == 1){
                    if(j >= x[i]){
                        if(f[j] < f[j-x[i]]+1){
                            f[j] = f[j-x[i]]+1;
                            b[i][j] ++;
                        }
                    }
                }else{
                    if(j >= y[i]){
                        if(f[j] < f[j-y[i]]+1){
                            f[j] = f[j-y[i]]+1;
                            b[i][j] ++;
                        }
                    }
                }
                cout << i << " " << j << " " << f[j] << " " << b[i][j] << endl;
            }
            cout << endl;
        }
        cout << f[m];*/
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

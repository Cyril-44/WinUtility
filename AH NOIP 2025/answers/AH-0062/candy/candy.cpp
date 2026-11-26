#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll n, m, minn = 0x3f3f3f3f, cnt, c[N], loc[N], num;
struct Candy{
    ll x, y;
}a[N];
inline ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
bool cmp(Candy a, Candy b){
    return a.x < b.x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    n = read(), m = read();
    for(int i=1;i<=n;i++){
        a[i].x = read(), a[i].y = read();
        minn = min(minn, a[i].x + a[i].y);
    }
    sort(a+1, a+n+1, cmp);
//    cout << "\n ----------------- \n";
//    cout << minn << endl;
//    for(int i=1;i<=n;i++){
//        cout << a[i].x << ' ' << a[i].y << endl;
//    }
//    cout << "\n ----------------- \n";
    for(int i=1;i<=n;i++){
        if(a[i].x <= minn/2.0){
            m -= a[i].x;
            c[++num] = a[i].x;
            loc[num] = i;
            swap(a[i].x, a[i].y);
            cnt++;
//            cout << "$ " << a[i].y << endl;
        }
    }
//    cout << "M " << m <<endl;
    ll t = m/minn;
    m -= t*minn;
    cnt += 2*t;
//    cout << "ONE " << t << ' '<< m << ' ' << cnt << endl;
    for(int i=num;i>=1;i--){
        if(m + c[i] >= minn){
            m = c[i] + m - minn;
            cnt++;
            swap(a[loc[i]].x, a[loc[i]].y);
        }
    }
    sort(a+1,a+n+1,cmp);
//    cout << "\n ----------------- \n";
//    for(int i=1;i<=n;i++){
//        cout << a[i].x << ' ' << a[i].y << endl;
//    }
//    cout << "\n ----------------- \n";
    for(int i=1;i<=n;i++){
        if(a[i].x <= m){
            m -= a[i].x;
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}

// 9:20 accept

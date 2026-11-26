#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4+5, M = 998244353;
int n, q, a[N];
long long p[N], ans[N];
struct segment{
    int l, r;
    long long x;
}t[N];
inline ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    n = read();
    for(int i=1;i<=n;i++)a[i]=read();
    q = read();
    while(q--){
        int L = read(), R = read();
        if(L == R){
            int l = 1, r = L;
            ll sum = 0;
            for(int i=l;i<=r;i++)sum += a[i];
            p[1] = sum;
            int num = n - L + 1;
            for(int i=2;i<=num;i++){
                l++;
                r++;
                sum += a[r] - a[l-1];
                p[i] = sum;
            }
//            cout << "#\n";
//            for(int i=1;i<=num;i++)cout << i << ' ' << i + L - 1 << ' ' << p[i] << endl;
//            cout << "# \n";
            int tl = 1, tr = 0;
            unsigned long long ANS = 0;
            for(int i=1;i<=n;i++){
                if(i <= num)t[++tr] = segment{i, i + L - 1, p[i]};
                while(tr > tl && t[tr].x > t[tr-1].x){
                    t[tr-1] = t[tr];
                    tr--;
                }
                if(t[tl].r < i)tl++;
                ans[i] = t[tl].x * i;
                ANS ^= ans[i];
//                cout << "# " << t[tl].x * i << endl;
            }
            cout << ANS << endl;
        }
    }
    return 0;
}
/*
4
2 4 -5 1
3
1 1
2 2
3 3

12:10 10tps
*/

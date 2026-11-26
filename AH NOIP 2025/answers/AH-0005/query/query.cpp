#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pr;

const int N=5e4+5;
int n,q;
ll a[N],pre[N];
int ql[N],qr[N];

namespace sub0 {
    ll w[3005][3005];
    
    void solve() {
        for(int i=1;i<=q;++i) {
            int L,R; cin >> L >> R;
            memset(w,0xe0,sizeof w);
            for(int j=1;j<=n;++j) for(int k=j+L-1;k<=j+R-1 && k<=n;++k) w[j][k]=pre[k]-pre[j-1];
            for(int j=1;j<=n;++j) for(int k=n;k>=1;--k) w[j][k]=max(w[j][k],max(w[j-1][k],w[j][k+1]));
            ull ans=0;
            for(int j=1;j<=n;++j) ans=ans^((ull)(w[j][j])*j);//,cerr << w[j][j] << ' '; cerr << endl;
            cout << ans << "\n";
        }
    }
};

namespace sub1 {
    deque<int> qq; 
    ll w[N],a[N][35],now[N];
    ull ans[35][35];

    void solve() {
        for(int i=1;i<=32 && i<=n;++i) {
            for(int j=1;j<=n;++j) {
                if(j+i-1>n) w[j]=-1e18;
                else w[j]=pre[j+i-1]-pre[j-1];
            }
            for(;!qq.empty();qq.pop_back()) ;
            for(int j=1;j<=n;++j) {
                for(;!qq.empty() && qq.front()+i-1<j;qq.pop_front()) ;
                for(;!qq.empty() && w[qq.back()]<=w[j];qq.pop_back()) ;
                qq.push_back(j); a[j][i]=w[qq.front()];
            }
        } 
        for(int i=1;i<=32;++i) {
            for(int j=1;j<=n;++j) now[j]=a[j][i];
            for(int j=i;j<=32;++j) {
                for(int k=1;k<=n;++k) now[k]=max(now[k],a[k][j]);
                for(int k=1;k<=n;++k) ans[i][j]=ans[i][j]^(((ull)now[k])*k);
            }
        }
        for(int i=1;i<=q;++i) cout << ans[ql[i]][qr[i]] << "\n";
    }
};

namespace sub2 {
    deque<int> qq; 
    ll w[N],now[N];

    bool chk() {
        for(int i=1;i<=q;++i) if(ql[i]!=qr[i]) return false;
        return true;
    }

    void solve() {
        for(int i=1;i<=q;++i) {
            int x=ql[i];
            for(int j=1;j<=n;++j) {
                if(j+x-1>n) w[j]=-1e18;
                else w[j]=pre[j+x-1]-pre[j-1];
            }
            for(;!qq.empty();qq.pop_back()) ;
            for(int j=1;j<=n;++j) {
                for(;!qq.empty() && qq.front()+x-1<j;qq.pop_front()) ;
                for(;!qq.empty() && w[qq.back()]<=w[j];qq.pop_back()) ;
                qq.push_back(j); now[j]=w[qq.front()];
            }
            ull ans=0;
            for(int j=1;j<=n;++j) ans=ans^(((ull)now[j])*j);
            cout << ans << "\n";
        } 
    }
};

namespace sub3 {
    pr st[20][N]; set<int> se;
    ll now[N]; int ord[N];

    void build() {
        for(int i=0;i<=n;++i) st[0][i]=(pr){-pre[i],i};
        for(int d=1;d<=19;++d) for(int i=0;i+(1<<d)<=n;++i) st[d][i]=max(st[d-1][i],st[d-1][i+(1<<(d-1))]);
    }

    pr qry(int l,int r) {
        int d=__lg(r-l+1);
        return max(st[d][l],st[d][r-(1<<d)+1]);
    }

    priority_queue<ll> qq;
    int le[N],ri[N]; pr tt;

    ll calc(int x) {
        auto it=se.upper_bound(x); int w=ri[x];
        if(it!=se.begin()) {
            --it;
            if(*it<le[x]) return -1ll<<60;
            w=min((int)*it,ri[x]);
        }
        else return -1ll<<60;
        tt=qry(max(le[x],1)-1,w-1); ord[x]=tt.second+1;
        return pre[x]+tt.first;
    }

    bool chk(int x) {
        auto it=se.lower_bound(le[x]);
        if(it==se.end() || *it>x) return false;
        return true;
    }

    void solve() {
        build();
        for(int i=1;i<=q;++i) {
            for(;!qq.empty();qq.pop()) ;
            for(int j=1;j<=n;++j) {
                le[j]=j-qr[i]+1;
                ri[j]=j-ql[i]+1;
            } 
            for(int j=1;j<=n;++j) se.insert(j);
            for(int j=1;j<=n;++j) if(ri[j]>=1) qq.push((calc(j)<<20)+j);
            ll cnt=0,oo,val; int o; set<int>::iterator it;
            for(int tp;!qq.empty();qq.pop()) { 
                tp=qq.top()&((1<<20)-1); val=qq.top()>>20;
                if(!chk(tp)) continue; oo=calc(tp);
                if(oo!=val) {
                    if(oo!=-1ll<<60) qq.push((oo<<20)+tp); 
                    continue;
                } 
                o=ord[tp];
                for(it=se.lower_bound(o);it!=se.end() && *it<=tp;it=se.erase(it)) now[*it]=val;
                oo=calc(tp);
                if(oo!=-1ll<<60) qq.push((oo<<20)+tp);
            } 
            ull ans=0;
            for(int j=1;j<=n;++j) ans=ans^(((ull)(now[j]))*j);
            cout << ans << "\n";
        } 
    }
};

void wk() {
    cin >> n; for(int i=1;i<=n;++i) cin >> a[i];
    cin >> q;
    for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
    if(n<=3000 && q<=50) { sub0::solve(); return ; }
    for(int i=1;i<=q;++i) cin >> ql[i] >> qr[i];
    if(*max_element(qr+1,qr+q+1)<=32) { sub1::solve(); return ; }
    if(sub2::chk()) { sub2::solve(); return ; }
    sub3::solve(); 
}

signed main() {
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);

    ios::sync_with_stdio(false);

    wk();

    return 0;
}
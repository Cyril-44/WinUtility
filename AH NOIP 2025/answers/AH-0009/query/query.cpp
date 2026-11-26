#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
bool st;
const int N=5e4+5;
const ll inf=1e16;
int n,Q;
ll a[N],sum[N];

struct data1{
    ll mn;int pos;
    bool operator<(data1 g)const{
        if (mn!=g.mn) return mn<g.mn;
        else return pos<g.pos;
    }
}minn[N][25];

struct data2{
    ll mx;int pos;
    bool operator<(data2 g)const{
        if (mx!=g.mx) return mx<g.mx;
        else return pos<g.pos;
    }
}maxx[N][25];

int lg[N];
void prest(){
    up(i,2,n) lg[i]=lg[i>>1]+1;
    up(i,1,n) minn[i][0]={sum[i-1],i},maxx[i][0]={sum[i],i};
    up(i,1,20) up(j,1,n){
        if (j+(1<<i)-1>n) break;
        minn[j][i]=min(minn[j][i-1],minn[j+(1<<i-1)][i-1]);
        maxx[j][i]=max(maxx[j][i-1],maxx[j+(1<<i-1)][i-1]);
    }
}
data1 qmin(int l,int r){
    int t=lg[r-l+1];
    return min(minn[l][t],minn[r-(1<<t)+1][t]);
}
data2 qmax(int l,int r){
    int t=lg[r-l+1];
    return max(maxx[l][t],maxx[r-(1<<t)+1][t]);
}

struct segmenttree{
    ll tr[N<<2];
    #define ls (p<<1)
    #define rs (p<<1|1)
    #define mid (l+r>>1)
    void clear(int p,int l,int r){
        tr[p]=-inf;
        if (l!=r) clear(ls,l,mid),clear(rs,mid+1,r);
    }
    void upd(int p,int l,int r,int L,int R,ll x){
        if (l>R||r<L) return;
        if (l>=L&&r<=R){
            tr[p]=max(tr[p],x);
            return;
        }
        upd(ls,l,mid,L,R,x),upd(rs,mid+1,r,L,R,x);
    }
    ll qmax(int p,int l,int r,int dot){
        if (l==r) return tr[p];
        ll rt=tr[p];
        if (mid>=dot) return max(rt,qmax(ls,l,mid,dot));
        else return max(rt,qmax(rs,mid+1,r,dot));
    }
}T;

ull ans[N];
namespace solve1{
    bool st;
    const int inff=1e9;
    ull anss[3005][3005];

    struct segtree{
        struct node{
            int maxx,lazy;
            void tag(int x){
                maxx=max(maxx,x);
                lazy=max(lazy,x);
            }
        }tr[3005*4];
        void clear(int p,int l,int r){
            tr[p]={-inff,-inff};
            if (l!=r) clear(ls,l,mid),clear(rs,mid+1,r);
        }
        void pushup(int p){
            tr[p].maxx=max(tr[ls].maxx,tr[rs].maxx);
        }
        void pushdown(int p){
            int &t=tr[p].lazy;
            if (t!=-inff){
                tr[ls].tag(t),tr[rs].tag(t);
                t=-inff;
            }
        }
        void upd(int p,int l,int r,int L,int R,ll x){
            if (l>R||r<L) return;
            if (l>=L&&r<=R){
                tr[p].tag(x);
                return;
            }
            pushdown(p);
            upd(ls,l,mid,L,R,x),upd(rs,mid+1,r,L,R,x);
            pushup(p);
        }
        int qmax(int p,int l,int r,int L,int R){
            if (l>R||r<L) return -inf;
            if (l>=L&&r<=R) return tr[p].maxx;
            pushdown(p);
            return max(qmax(ls,l,mid,L,R),qmax(rs,mid+1,r,L,R));
        }
    }T1[3005];

    bool ed;
    void solve(){
//        cerr<<(&ed-&st)/1024.0/1024.0<<'\n';
        up(i,1,n) T1[i].clear(1,1,n);
        up(i,1,n) up(j,1,i){
            T1[i-j+1].upd(1,1,n,j,i,sum[i]-sum[j-1]);
        }
        up(i,1,n) up(len,1,n){
            anss[i][len]=T1[len].qmax(1,1,n,i,i);
        }
        up(i,1,n) T1[i].clear(1,1,n);
        up(i,1,n) up(len,1,n) T1[i].upd(1,1,n,len,len,anss[i][len]);

        cin>>Q;
        while (Q--){
            int L,R;cin>>L>>R;
            up(i,1,n) ans[i]=T1[i].qmax(1,1,n,L,R);
            ull ot=0;
            up(i,1,n) ot=ot^(ans[i]*i);
            cout<<ot<<'\n';
        }
    }
}

bool ed;
int main(){
//    cerr<<(&ed-&st)/1024.0/1024.0<<'\n';
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    up(i,1,n) cin>>a[i],sum[i]=sum[i-1]+a[i];
    if (n<=3000){
        solve1::solve();
        return 0;
    }
    prest();
    cin>>Q;
    while (Q--){
        T.clear(1,1,n);
        int L,R;cin>>L>>R;

        up(i,L,n) T.upd(1,1,n,i-L+1,i,sum[i]-sum[i-L]);
        up(i,R,n) T.upd(1,1,n,i-R+1,i,sum[i]-sum[i-R]);
        up(i,L,n){
            int lef=max(1,i-R+1),rig=i-L+1;
            data1 k=qmin(lef,rig);
            T.upd(1,1,n,k.pos,i,sum[i]-k.mn);
        }

        down(i,n-L+1,1){
            int lef=i+L-1,rig=min(n,i+R-1);
            data2 k=qmax(lef,rig);
            T.upd(1,1,n,i,k.pos,k.mx-sum[i-1]);
        }

        up(i,1,n) ans[i]=T.qmax(1,1,n,i);
        ull ot=0;
        up(i,1,n) ot=ot^(ans[i]*i);
        cout<<ot<<'\n';
    }
    return 0;
}

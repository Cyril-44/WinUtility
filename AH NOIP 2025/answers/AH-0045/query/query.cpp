#include <bits/stdc++.h>
using namespace std;
#define int long long
#define len 101000
#define lc id<<1
#define rc id<<1|1
#define inf 0x3f3f3f3f
int n, q, a[len], seg[len*4], tag[len*4], l, r;
int tq[len], id[len], tl, tr, tans[len];
void build(int l, int r, int id) {
    seg[id]=tag[id]=-inf;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l, mid, lc), build(mid+1, r, rc);
    return;
}
void chgtag(int id) {
    seg[lc]=max(seg[lc], tag[id]);
    seg[rc]=max(seg[rc], tag[id]);
    tag[lc]=max(tag[lc], tag[id]);
    tag[rc]=max(tag[rc], tag[id]);
    return;
}
void chg(int l, int r, int fl, int fr, int id, int t) {
    if(l<=fl&&fr<=r) {seg[id]=max(seg[id], t), tag[id]=max(tag[id], t); return;}
    int mid=(fl+fr)>>1;
    chgtag(id);
    if(l<=mid) chg(l, r, fl, mid, lc, t);
    if(mid<r) chg(l, r, mid+1, fr, rc, t);
    seg[id]=max(seg[lc], seg[rc]);
    return;
}
int get(int x, int fl, int fr, int id) {
    if(fl==fr) return seg[id];
    int mid=(fl+fr)>>1;
    chgtag(id);
    if(x<=mid) return get(x, fl, mid, lc);
    if(x>mid) return get(x, mid+1, fr, rc);
}
signed main() {
//    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>q;
    if(q==1) {
        build(1, n, 1);
        for(int i=1;i<=n;i++) {
            if(i+l-1>n) continue;
            int ts=0;
            for(int j=i;j<i+l-1;j++) ts+=a[j];
            for(int j=i+l-1;j<=n&&j<=i+r-1;j++) ts+=a[j], chg(i, j, 1, n, 1, ts);
        }
        unsigned long long ans=0;
        for(int i=1;i<=n;i++) ans=ans^(unsigned long long)(get(i, 1, n, 1)*i);
        cout<<ans;
    }
    else {
        int qz[len];
        qz[0]=0;
        for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
        while(q--) {
            unsigned long long ans=0;
            cin>>l>>r;
            for(int i=1;i<=n;i++) tans[i]=-inf;
            for(int ti=l;ti<=r;ti++) {
                tl=1, tr=1, tq[1]=qz[ti], id[1]=1;
                for(int i=1;i<=n;i++) {
                    while(i-ti+1>id[tl]) tl++;
                    if(i+ti-1<=n) {
                        int tmp=qz[i+ti-1]-qz[i-1];
                        while(tr>=tl&&tq[tr]<=tmp) tr--;
                        tq[++tr]=tmp, id[tr]=i;
                    }
                    tans[i]=max(tans[i], tq[tl]);
                }
            }
            for(int i=1;i<=n;i++) ans=ans^((unsigned long long)tans[i]*i);
            cout<<ans<<endl;
        }
    }
    return 0;
}

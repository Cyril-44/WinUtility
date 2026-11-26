#include<bits/stdc++.h>
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)

using namespace std;
const int N=1e5+5;
int n,m;
int c ,t;
int a[1145141];
bool cmp(int x,int y) {
    return x>y;
}
int xjb[1145141];
int w[1145141];
struct node{
    int xjb,a;
    int w;
}sp[1145141];
bool cmp2(node x,node y) {
    if(x.xjb!=y.xjb) return x.xjb>y.xjb;
    return x.a>y.a;
}
int fll[22];

signed main() {
   freopen("sale.in","r",stdin);                                                
   freopen("sale.out","w",stdout);   
    
    cin>>c>>t;
    while(t--) {
        cin>>n>>m;
        int ans=0;
        rep(i,1,n) {
            cin>>a[i];
        }
        // sort(a+1,a+n+1,cmp);
        // for(int s=0;s<(1ll<<n);s++) {
            rep(s,0,(1ll<<n)-1){
            memset(fll,0,sizeof(fll));
            //0 w=1 1 w=2
            rep(j,1,n) {
                if(s&(1ll<<j-1)) {
                    xjb[j]=a[j];
                    w[j]=2;
                } else xjb[j]=a[j]*2,w[j]=1;

                    sp[j]={xjb[j],a[j],w[j]};
            }

            sort(sp+1,sp+n+1,cmp2);

            // rep(j,1,n) {
            //     cout<<sp[j].xjb<<' '<<sp[j].a<<' '<<sp[j].w<<endl;;
            // }
            // cout<<endl<<endl;
            int nid=0;
            int nowm=m;
            vector<int>qwq;
            int qian=(1ll<<44);
            int em=(1ll<<44),ym=(1ll<<44);
            int tem=(1ll<<44);
            rep(j,1,n){
                if(nowm>=sp[j].w) {
                    nowm-=sp[j].w; 
                    if(sp[j].w==1)
                        ym=min(ym,sp[j].a),qwq.push_back(sp[j].a);
                    else 
                       em=min(em,sp[j].a);

                    fll[j]=1;
                }
            } 

            // cout<<ym<<' '<<em<<endl;
            if(qwq.size()>=2) {

                sort(qwq.begin(),qwq.end());
                tem=qwq[0]+qwq[1];
                em=min(em,tem);
                // cout<<"???";
            }
            if(nowm)
            em=min(em,ym);
            int fl=1;
            rep(j,1,n) {
                if(fll[j]==0) {
                    if(sp[j].w==1) {
                        if(sp[j].a>ym) fl=0;
                    } else {
                        if(sp[j].a>em) fl=0;
                    }
                }
            }

            
            // int fl=1;
            // rep(j,nid+1,n) {
            //     if(xjb[j]>qian&&a[j]<a[nid]&&w[j]<=w[nid]) {
            //         fl=0;
            //     }
            // }
            if(fl==1) ans++;
            // else cout<<s<<endl;
            // cout<<fl<<' ';
            // rep(j,1,n) {
            //     cout<<w[j]<<' ';
            // }
            // cout<<ym<<' '<<em<<endl;
            // rep(j,1,n) {
            //     cout<<fll[j]<<' ';
            // }
            // cout<<endl;
            // cout<<endl;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
考虑什么时候不合法
假如现在钦定了 1 2 ，我们按照性价比从小到大排序

你发现 ，购买的物品一定是 [1,x] 可能带一个 y
dui

县考虑不带 y 的情况
你发现 如果存在 j>x a[j]>min(a[1-x]) 就死了
所以他得是一个前一半大于后一半的东西

、其实并不一定 等价条件到底是沙？

*/

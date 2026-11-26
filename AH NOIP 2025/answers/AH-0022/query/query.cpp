#include<bits/stdc++.h>
// #define int unsigned int
#define max(x,y) ((x)>(y)?(x):(y))
#define rep(i,x,y) for(int i=x;i<=y;i++)

using namespace std;
const int N=1e5+5;
int n,m;
int c ,t;
int a[5050];
int q;
// int K[1]
int qzh[5050];
int b[5050];
int lg[5050];
struct ST{
    int v[13][3010];
    void init() {
       // memset(v,-0x3f,sizeof(v));
        for(int i=1;i<=n;i++) v[0][i]=b[i];
        // rep(i,1,n) {
        //     cout<<b[i]<<' ';
        // }
        // cout<<endl;
        for(int j=1;j<=12;j++) {
            for(int i=1;i+(1ll<<j)-1<=n;i++) {
                v[j][i]=max(v[j-1][i],v[j-1][i+(1ll<<j-1)]);
            }
        }
    }
    int qry(int l,int r) { 
        if(l>r) return -(1ll<<30);
        int x=lg[r-l+1];
        return max(v[x][l],v[x][r-(1ll<<x)+1]);
    }
}ST[3005];

signed main() {
   freopen("query.in","r",stdin);                                                
   freopen("query.out","w",stdout); 
   lg[1]=0;  
    rep(i,2,3030) {
        lg[i]=lg[i/2]+1;
    }
    cin>>n;
    rep(i,1,n) {
        cin>>a[i];
        qzh[i]=qzh[i-1]+a[i];
    }

    rep(i,1,n) {
        memset(b,-0x3f,sizeof(b));
        for(int len=1;len<=n-i+1;len++) {
            b[i+len-1]=qzh[len+i-1]-qzh[i-1];
        }
        ST[i].init();
    }
    cin>>q;
    while(q--) {
        int L,R;
        cin>>L>>R;
        unsigned long long yh=0;
        if(n<=1000) {
            rep(i,1,n) {
                int ans=-(1ll<<30);

                for(int l=1;l<=i;l++) {
                    for(int r=i;r<=n;r++){
                        if(L<=r-l+1&&r-l+1<=R) {
                            ans=max(ans,qzh[r]-qzh[l-1]);
                        }
                    }
                }
                // cout<<ans<<' ';
                unsigned long long nw=i*ans+(1ll<<62);
                nw+=(1ull<<62);
                nw+=(1ull<<62);
                nw+=(1ull<<62);
                yh^=nw;
            } 
            cout<<yh<<'\n';
        } else {
            

                for(int i=1;i<=n;i++) {
                    long long ans=-(1ll<<50);
                        for(int l=1;l<=i;l++) {
                            int mnr=max(l+L-1,i);
                            int mxr=min(n,R+l-1);
                            mxr=max(i,mxr); 
                            if((L<=mnr-l+1&&mnr-l+1<=R&&L<=mxr-l+1&&mxr-l+1<=R)){

                              ans=max(ans,ST[l].qry(mnr,mxr));
                            //   if(i==3)
                            //  cout<<"?"<<' '<<l<<' '<<mnr<<' '<<mxr<<endl<<ST[l].qry(mnr,mxr)<<endl;
                            // cout<<"for"<<i<<' '<<"we cal"<<l<<' '<<mnr<<' '<<mxr<<endl;
                            }
                        }
                    unsigned long long nw=i*ans+(1ll<<62);
                    nw+=(1ull<<62);
                    nw+=(1ull<<62);
                    nw+=(1ull<<62);
                    yh^=nw;
                    // cout<<ans<<' ';
                }
                // cout<<endl;
                cout<<yh<<'\n';
        }
    }
    return 0;
} 
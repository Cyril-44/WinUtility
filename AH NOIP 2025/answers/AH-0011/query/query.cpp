#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pr pair<int,int>
#define mk make_pair
#define getchar getchar_unlocked
using namespace std;
template<typename T>void in(T &x){
    char c=getchar();int f=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-'){c=getchar();f=-1;}
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    x*=f;
}
template<typename T>T mn(T a,T b){return a<b?a:b;}
template<typename T>T mx(T a,T b){return a>b?a:b;}
const int N=5e4+5,B=99;
const ll inf=1e18+7;
int n,Q,a[N];
int lg[N];
ll st[17][N],st2[17][N];
ll r[B+1][N],rr[15][N];
ll s[N],ss[N],ans[N],ch[N];
int q[N];
ll qm1(int l,int r){
    int k=lg[r-l+1];
    return mn(st[k][l],st[k][r-(1<<k)+1]);
}
ll qm2(int l,int r){
    int k=lg[r-l+1];
    return mn(st2[k][l],st2[k][r-(1<<k)+1]);
}
void wk(int L,int R){
    int hd=1,tl=0;
    for(int j=1;j<=n;++j){
        if(hd<=tl&&q[hd]<j) hd++;
        int t=j+L-1;
        if(t<=n){
            ch[t]=mx(s[t]-qm1(mx(t-R,0),t-L),ss[t-L+1]-qm2(t+1,mn(n+1,t-L+1+R)));
            while(hd<=tl&&ch[q[tl]]<=ch[t]) tl--;
            q[++tl]=t;
        }
        ans[j]=mx(ans[j],ch[q[hd]]);
    }
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    in(n);
    for(int i=2;i<=n+1;++i) lg[i]=lg[i/2]+1;
    for(int i=1;i<=n;++i) in(a[i]),s[i]=s[i-1]+a[i],st[0][i]=s[i];
    for(int i=1;i<=16;++i) for(int j=0;j+(1<<i)-1<=n;++j) st[i][j]=mn(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    for(int i=n;i>=1;i--) ss[i]=ss[i+1]+a[i],st2[0][i]=ss[i];
    for(int i=1;i<=16;++i) for(int j=1;j+(1<<i)-1<=n+1;++j) st2[i][j]=mn(st2[i-1][j],st2[i-1][j+(1<<(i-1))]);
    if(n>=B){
        for(int j=1;j<=n;++j) ans[j]=-inf;
        for(int j=B;j>=1;j--){
            wk(j,j);
            for(int k=1;k<=n;++k) r[j][k]=ans[k];
        }
        for(int j=1;j<=n;++j) ans[j]=-inf;
        for(int j=B*2,c=2;j<=n;j*=2,c++){
            wk(j/2+1,j);
            for(int k=1;k<=n;++k) rr[c][k]=ans[k];
        }
    }
    in(Q);
    for(int i=1,x,y;i<=Q;++i){
        in(x),in(y);
        if(y<B||x>B) for(int j=1;j<=n;++j) ans[j]=-inf;
        else{for(int j=1;j<=n;++j) ans[j]=r[x][j];x=B+1;}
        if(x==B+1){
            int ma=1,now=B*2;
            for(;now<=y;now*=2) ma++;
            if(ma>1){
                for(int j=1;j<=n;++j) ans[j]=mx(ans[j],rr[ma][j]);
                x=now/2;
            }
        }
        while(x<=y){
            if(x*2>=y){wk(x,y);break;}
            else wk(x,2*x),x=x*2;
        }
        ull an=0;
        for(int j=1;j<=n;++j) an^=1ull*j*ans[j];
        printf("%llu\n",an);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int read(){
    int xx=0,ff=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') ff=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        xx=xx*10+(ch-'0');
        ch=getchar();
    }
    return xx*ff;
}
void write(ull xx){
    if(xx>=10) write(xx/10);
    putchar(((int)(xx%10))+'0');
}
const int N=5e4;
const long long oo=1e18;
int n,q,a[N+5],lg[N+5];
long long st[22][N+5],s[N+5],w[N+5];
long long que(int l,int r){
    int gg=lg[r-l+1];
    return max(st[gg][l],st[gg][r-(1<<gg)+1]);
}
int main() {
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        s[i]=s[i-1]+a[i];
        st[0][i]=s[i];
    }
    for(int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
    for(int i=1;i<=lg[n];++i){
        for(int j=1;j+(1<<i)-1<=n;++j){
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    q=read();
    while(q--){
        int L=read(); int R=read();
        ull ans=0;
        if(L==R){
            for(int i=1;i<=n;++i){
                if(i+L-1<=n) w[i]=s[i+L-1]-s[i-1];
                else w[i]=-oo;
            }
            deque<int> dq;
            for(int i=1;i<=n;++i){
                while(!dq.empty() && dq.front()+L-1<i) dq.pop_front();
                while(!dq.empty() && w[i]>=w[dq.back()]) dq.pop_back();
                dq.push_back(i);
                ans^=(ull)(w[dq.front()]*i);
            }
            write(ans);
            putchar('\n');
            continue;
        }
        for(int i=1;i<=n;++i){
            long long res=-oo;
            for(int l=max(1,i-R+1);l<=min(i,n-L+1);++l){
                int x=max(i,L+l-1), y=min(n,R+l-1);
                res=max(res,que(x,y)-s[l-1]);
            }
            ans^=(ull)(res*i);
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}
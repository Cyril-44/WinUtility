#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL read(){
    LL xx=0,ff=1;
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
void write(LL xx){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10) write(xx/10);
    putchar(xx%10+'0');
}
const int N=1e5,oo=2e9;
int n;
LL m,a[N+5];
int main() {
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    n=read(); m=read();
    LL w=oo;
    for(int i=1;i<=n;++i){
        int x=read(); int y=read();
        w=min(w,(LL)x+y);
        a[i]=x;
    }
    sort(a+1,a+n+1);
    LL ans=0;
    for(int i=2;i<=n;++i) a[i]+=a[i-1];
    for(int i=0;i<=n;++i){
        if(a[i]>m) break;
        ans=max(ans,i+((m-a[i])/w)*2);
    }
    write(ans);
    putchar('\n');
    return 0;
}
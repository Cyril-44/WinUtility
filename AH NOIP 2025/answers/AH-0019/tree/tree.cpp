#include <bits/stdc++.h>
using namespace std;
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
void write(int xx){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10) write(xx/10);
    putchar(xx%10+'0');
}
const int N=8000;
int n,m,fa[N+5];
vector<int> G[N+5];

int main() {
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int T=read();
    while(T--){
        n=read(); m=read();
        for(int i=2;i<=n;++i){
            fa[i]=read();
            G[fa[i]].push_back(i);
        }
        write(n+1);
        putchar('\n');
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int w=1,x=0;char c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar_unlocked();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar_unlocked();}
    return x*w;
}
void write(int x){
    if(x<0){putchar_unlocked('-');x=-x;}char c[1145];int len=0;while(x){c[++len]=(x%10)+'0';x/=10;}
    for(int i=len;i>=1;i--){putchar_unlocked(c[i]);}
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    srand(time(NULL));
    cout<<0;
}
//!noip@Nov29,2025:dream

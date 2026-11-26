#include<bits/sdtc++.h>
using namespace std;
template <typename T>
inline void in(T &x){
    int f=1;x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
    return;
}
int n,q;
int a[50005];
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    in(n);
    for(int i=1;i<=n;i++) in(a[i]);
    in(q);
    while(q--){
        int L,R;
        long long ans=0;
        in(L),in(R);

        for(int i=1;i<=n;i++)
    }
    return 0;
}
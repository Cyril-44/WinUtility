#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
int f=1,x=0;
char a;
a=getchar();
while(a>'9' || a<'0'){
if(a=='-')f=-1;
a=getchar();
}
while(a<='9' && a>='0'){
x=(x<<1)+(x<<3)+a-'0';
a=getchar();
}
return x*f;
}
int n,m,ans=-1;
int x[100010],y,sum[100010];
int ymi=(1<<30);
signed main(){
freopen("candy.in","r",stdin);
freopen("candy.out","w",stdout);
n=read();
m=read();
for(int i=1;i<=n;i++){
    x[i]=read();
    y=read();
    y+=x[i];
    if(y<ymi){
    ymi=y;
    }
}
sort(x+1,x+1+n);
for(int i=1;i<=n;i++){
    sum[i]=sum[i-1]+x[i];
}

for(int i=1;i<=n;i++){
    ans=max(ans,(m-sum[i])/ymi*2+i);
}
cout<<ans;
return 0;
}
//!noip@Nov29,2025:dream

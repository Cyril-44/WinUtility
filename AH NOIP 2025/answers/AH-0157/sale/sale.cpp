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
int c,t;
int n,m;
int a[6000];
int mod=998244353;
signed main(){
freopen("sale.in","r",stdin);
freopen("sale.out","w",stdout);
c=read();
t=read();
while(t--){
n=read();
m=read();
for(int i=1;i<=n;i++){
a[i]=read();
a[i]=a[i]*2;
}
cout<<pow(2,n)-2;


}

return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define sp putchar(' ')
#define el putchar('\n')
using ll=__int128;
ll read(){
    char cc=getchar();
    int f=1,x=0;
    while(!isdigit(cc)){
        if(cc=='-'){
            f=-f;
        }
        cc=getchar();
    }
    do{
        x=(x<<1)+(x<<3)+(cc^'0');
        cc=getchar();
    }while(isdigit(cc));
    return f*x;
}
void print(ll x){
    if(x<0){
        putchar('-');
        print(-x);
    }else if(x<10){
        putchar(x^'0');
    }else{
        print(x/10);
        putchar(x%10^'0');
    }
}
const int N=1005,M=10005;
int n,m,w1,w2,f[2][M];
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        w1=read();
        w2=read();
        for(int j=0;j<=m;++j){
            if(j+w1<=m){
                f[0][j+w1]=max(f[0][j+w1],f[1][j]+1);
            }
            if(j+w2<=m){
                f[1][j+w2]=max(f[1][j+w2],f[0][j]+1);
            }
        }
    }
    print(max(f[1][m],f[0][m]));
    el;
    return 0;
}

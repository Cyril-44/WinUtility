#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+int(c-'0');
        c=getchar();
    }
    return x*f;
}
void put_int(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    char c=(x%10)+'0';
    if(x>9){
        put_int(x/10);
    }
    putchar(c);
    return ;

}

int n,m,c,t;
int ans;
int a[5010];
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    c=read();
    t=read();
    while(t--){//998244353
        ans=0;
        n=read();
        m=read();

        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        int texta=a[1];
        for(int i=1;i<=n;i++){
            if(texta!=a[i]){
                texta=-1;
                break;
            }
        }
        if(texta!=-1){
            if(m<n){
                double c2=1;
                for(int i=1;i<=m;i++){
                    c2=c2*(n-i+1)/i;
                }
                int t=int(c2)%998244353;
                put_int(t);
                putchar('\n');
            }
            else if(m>=n){
                int h=2*n-m;
                double c2=1;
                for(int i=1;i<=h;i++){
                    c2=c2*(n-i+1)/i;
                }
                int t=int(c2)%998244353;
                put_int(t);
                putchar('\n');
            }
        }
    }


    return 0;
}

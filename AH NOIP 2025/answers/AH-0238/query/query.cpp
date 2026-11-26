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
void put_ll(long long x){

    if(x<0){
        putchar('-');
        x=-x;
    }
    char c=(x%10)+'0';
    if(x>9){
        put_ll(x/10);
    }
    putchar(c);
    return ;

}
int a[100010];
int n,m,q;
long long ans=0;
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);

    n=read();

    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    q=read();

    for(int i=1;i<=q;i++){
        int li,ri;
        li=read(); ri=read();
        if(li==ri){

            ans=(long long)(a[1]);
            for(int i=2;i<=n;i++){
                ans=(i*a[i])^ans;
            }
            put_ll(ans);
            putchar('\n');
        }
    }

    return 0;
}

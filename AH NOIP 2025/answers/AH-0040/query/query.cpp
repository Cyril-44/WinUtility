#include<iostream>
#include<cstdio>
using namespace std;
struct SGT{
    typedef int Tp;typedef int Tg;
    struct node{
        Tp s;
        Tg tg;
        void down(Tg t){tg=max(t,tg),s=max(s,t);}
    }t[4000000];
    Tp up(Tp a,Tp b){return max(a,b);}
    void pushup(int p){
        t[p].s=up(t[p<<1].s,t[(p<<1)|1].s);
    }
    void pushdown(int p){
            t[p<<1].down(t[p].tg);
            t[p<<1|1].down(t[p].tg);
    }
    void build(int p,int l,int r){
            t[p].s=t[p].tg=-0x3f3f3f3f;
        if(l==r){
            return;
        }
        int m=(l+r)>>1;
        build(p<<1,l,m),build(p<<1|1,m+1,r);
    }
    void update(int p,int l,int r,int L,int R,Tg tg){
        if(l>R||r<L)return;
        if(L<=l&&r<=R)return t[p].down(tg);
        int m=(l+r)>>1;
        pushdown(p);
        update(p<<1,l,m,L,R,tg),update((p<<1)|1,m+1,r,L,R,tg);
        pushup(p);
    }
    Tp query(int p,int l,int r,int L,int R){
        if(L>r||l>R)return -0x3f3f3f3f;
        if(L<=l&&r<=R)return t[p].s;
        int m=(l+r)>>1;
        pushdown(p);
        return up(query(p<<1,l,m,L,R),query((p<<1)|1,m+1,r,L,R));
    }
}T;
int s[2000000],a[2000000],n;
typedef unsigned long long ull;
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        T.build(1,1,n);
        int L,R;
        cin>>L>>R;
        for(int l=1;l<=n;l++){
            for(int r=l+L-1;r<=n&&r-l+1<=R;r++){
                T.update(1,1,n,l,r,s[r]-s[l-1]);
            }
        }
        unsigned long long ans=0;
        for(int i=1;i<=n;i++){
            ans^=(ull)T.query(1,1,n,i,i)*i;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

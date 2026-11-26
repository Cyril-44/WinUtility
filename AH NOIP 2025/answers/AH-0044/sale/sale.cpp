#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>

#define LL long long

using namespace std;

const int N=5000+10;

int c,T;
int n,m;
int cnt=0;

struct Node{

    int num;
    int p;
    int idx;

}a[N],b[N];

bool cmp(Node u,Node v){

    if(u.num*v.p!=v.num*u.p)
        return u.num*v.p>v.num*u.p;
    if(u.num!=v.num)
        return u.num>v.num;
    return u.idx<v.idx;

}

bool Check(){

    if(m==1)
        return true;
    for(int i=1;i<=n;i++)
        b[i]=a[i];
    sort(b+1,b+1+n,cmp);
    int ans=0;
    int tmp=-1;
    for(int i=1;i<=n;i++){
        if(ans+b[i].p<=m)
            ans+=b[i].p;
        else if(tmp==-1)
            tmp=i;
        if(ans==m){
            if(tmp==-1)
                return true;
            if(b[tmp-1].p==2)
                return true;
            if(b[tmp].num>b[tmp-1].num+b[i].num)
                return false;
            return true;
        }
    }
    return true;

}

void DFS(int p){

    if(p==n+1){
        if(Check())
            cnt++;
        return ;
    }
    a[p].p=1;
    DFS(p+1);
    a[p].p=2;
    DFS(p+1);
    return ;

}

void Solve(){

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].num);
        a[i].idx=i;
    }
    cnt=0;DFS(1);
    printf("%d\n",cnt);
    return ;

}

int main(){

    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);

    scanf("%d%d",&c,&T);
    while(T--)
        Solve();
    printf("\n");
    return 0;

    fclose(stdin);
    fclose(stdout);

}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')f=-1,c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-48,c=getchar();
    return f*x;
}
void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9)write(x/10);
    putchar(x%10+48);
    return ;
}
const int N=8003;
int n,h;
vector<int>son[N];
int s=0;
int dfs(int x,int cur){
    if(son[x].size()==0){
        if(!cur)s++;
        //a[x]=cur;
        return cur;
    }
    int k=0;
    for(int i=0;i<son[x].size();i++){
        if(son[son[x][i]].size()==0)cur=max(dfs(son[x][i],k++),cur);
        else cur=max(dfs(son[x][i],0),cur);
    }
    cur++;
    s+=cur+1;
    //a[x]=cur;
    return cur;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int T=read();
    while(T--){
        n=read(),h=read();
        s=0;
        for(int i=1;i<=n;i++)son[i].clear();
        for(int i=2;i<=n;i++){
            int x=read();
            son[x].push_back(i);
        }
        if(h==1){
            printf("%lld\n",n+1);
            continue;
        }
        dfs(1,0);
        //for(int i=1;i<=n;i++)printf("%lld ",a[i]);
        printf("%lld\n",s);
    }
    return 0;
}

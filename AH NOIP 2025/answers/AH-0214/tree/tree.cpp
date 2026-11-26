#include<bits/stdc++.h>
using namespace std;
struct node{
    int p,out=0;
    int son[8001];
}nod[8001];
int v[8001]={0},ans=0,n,m;
int num=0;
int dfs(int deep,int p){
    int maxx=0;
    if(deep==m||nod[p].out==0){
        return v[p]+1;
    }
    for(int i=1;i<=nod[p].out;i++){
        maxx=max(maxx,dfs(deep+1,nod[p].son[i]));
    }
    v[p]=maxx;
    return maxx+1;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ans=0;
        memset(v,0,sizeof(v));
        int sur;
        for(int i=2;i<=n;i++){
            cin>>sur;
            nod[i].p=sur;
            nod[sur].son[++nod[sur].out]=i;
        }
        for(int i=2;i<=n;i++){
            if(nod[i].out==0){
                v[i]=v[nod[i].p];
                v[nod[i].p]++;
            }
        }
        dfs(1,1);
        for(int i=1;i<=n;i++){
            if(nod[i].out==0&&v[i]!=0)ans+=0;
            else{
                ans+=v[i]+1;
            }
            //cout<<v[i]<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}




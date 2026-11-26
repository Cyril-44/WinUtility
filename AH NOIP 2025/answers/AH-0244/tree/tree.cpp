#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=8005;
int t,n,m,ans;
int father[N],countx[N],tree[N];
vector<int> son[N];
inline void Init(){
    ans=0;
    for(int i=1;i<=n;i++){
        son[i].clear();
        countx[i]=-1;
        tree[i]=0;
    }
}
inline void dfs(int i){
    if(son[i].empty()){
        tree[i]=countx[father[i]]+1;
        countx[father[i]]++;
        return;
    }
    for(int j=0;j<son[i].size();j++){
        int sonid=son[i][j];
        dfs(sonid);
        tree[i]=max(tree[sonid]+1,tree[i]);
    }
    return;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        Init();
        for(int i=2;i<=n;i++){
            scanf("%lld",&father[i]);
            son[father[i]].push_back(i);
        }
        dfs(1);
        for(int i=1;i<=n;i++){
            if(son[i].empty()&&tree[i]!=0) continue;
            ans+=tree[i]+1;

        }
        printf("%lld\n",ans);
       // for(int i=1;i<=n;i++) cout<<tree[i]<<" ";
       // cout<<endl;
    }
    return 0;
}

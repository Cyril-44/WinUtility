#include<bits/stdc++.h>
using namespace std;
int t,n,m,p,fa[8005],ans;
vector<int> son[5005];
int tong[100];
int v[100];
void dfs2(int k){
    tong[v[k]]++;
    for(int i=0;i<son[k].size();i++){
        dfs2(son[k][i]);
    }
    return;
}
void dfs(int k){
    if(k==n+1){
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                tong[j]=0;
            }
            dfs2(i);
            int num=0;
            for(int j=0;j<=n;j++){
                if(tong[j]==0){
                    num=j;
                    break;
                }
            }
            sum+=num;
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=0;i<=n;i++){
        v[k]=i;
        dfs(k+1);
    }
    return;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=2;i<=n;i++){
            cin>>p;
            son[p].push_back(i);
        }
        ans=0;
        dfs(1);
        cout<<ans<<"\n";
    }
    return 0;
}

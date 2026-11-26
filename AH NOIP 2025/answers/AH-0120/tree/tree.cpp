#include<bits/stdc++.h>
using namespace std;
int t,n,m;
struct node{
    int fa,son,h,sum;
}tree[10000];
bool cmp(node a,node b){
    return a.fa<b.fa;
}
bool cmp2(node a,node b){
    return a.h<b.h;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        long long ans=0;
        memset(tree,0,sizeof(tree));
        cin>>n>>m;
        for(int i=2;i<=n;i++){
            cin>>tree[i].fa;
            tree[tree[i].fa].son++;
        }
        sort(tree+1,tree+1+n,cmp);
        for(int i=2;i<=n;i++){
            tree[i].h=tree[tree[i].fa].h+1;
        }
        sort(tree+1,tree+1+n,cmp2);
        for(int i=n;i>1;i--){
            if(!tree[i].son){
                tree[i].sum=tree[tree[i].fa].sum;
                tree[tree[i].fa].sum++;
            }else tree[tree[i].fa].sum=max(tree[i].sum+1,tree[tree[i].fa].sum);
        }
        for(int i=1;i<=n;i++){
            if(tree[i].son)ans+=tree[i].sum+1;
            else if(!tree[i].sum)ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

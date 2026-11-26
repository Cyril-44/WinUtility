#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int b[100005];
int fa[1000005];
int t[10000001];
int fc[1000005];
int n,m;
int sum;
int p[10001];
int find(int x){
if(fa[x]==x)return x;
else {
    int tt=find(fa[x]);
    if(tt==1){
        fc[x]=fc[fa[x]]+1;
        if(t[x]==0){p[fc[x]]++;
        t[x]=1;
        }
        fa[x]=1;
            }
            return tt;
}
}
signed main(){
    freopen("tree1.in","r",stdin);
    freopen("tree.out","w",stdout);
    int kk;
    cin>>kk;
    for(int ll=1;ll<=kk;ll++){
            sum=0;
        cin>>n>>m;
            fill(fa+1,fa+1+n+10,0);
            fill(fc+1,fc+1+n+10,0);
            fill(p+1,p+19+m,0);
            fill(t+1,t+10+n,0);
            p[1]=1;
            fc[1]=1;
            fa[1]=1;
        for(int i=2;i<=n;i++){
            int k=0;
            cin>>k;
            if(fa[find(k)]=1){
            fa[i]=1;
            fc[i]=fc[k]+1;
            t[i]=1;
            p[fc[i]]++;
            }
              else {
                fa[i]=k;
              }
        }
        for(int i=1;i<=m+1;i++) {sum+=p[i]*(m+2-i);
        }
    cout<<sum<<endl;
    }
return 0;
}

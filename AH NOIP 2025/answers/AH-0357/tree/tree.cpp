#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int n,m;
int p[8010],d[8010],cnt[810],a[810][8010],pr[1000010],ans;
bool cmp(int a,int b){
    return pr[a]>=pr[b];
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        memset(p,0,sizeof(p));
        memset(pr,0,sizeof(pr));
        ans=0;
        cin>>n>>m;
        d[1]=p[1]=1;
        a[1][1]=1;
        cnt[1]=1;
        for(int i=2;i<=n;i++){
            cin>>p[i];
            d[i]=d[p[i]]+1;
            a[d[i]][++cnt[d[i]]]=i;
        }
        for(int i=800;i>=1;i--){
            for(int j=1;j<=cnt[i];j++){
                for(int k=j+1;k<=cnt[i];k++){
                    if(pr[a[i][k]]>pr[a[i][j]]) swap(pr[a[i][k]],pr[a[i][j]]);
                }
            }
            for(int j=1;j<=cnt[i];j++){
                if(pr[a[i][j]]!=0){
                    ans+=pr[a[i][j]]+1;
                    pr[p[a[i][j]]]=max(pr[p[a[i][j]]],pr[a[i][j]]+1);
                    continue;
                }
                if(pr[p[a[i][j]]]==0){
                    ans++;
                    pr[p[a[i][j]]]=1;
                } else {
                    pr[p[a[i][j]]]+=1;
                }
            }
        }
    //    for(int i=1;i<=n;i++) cout<<pr[i]<<" ";
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

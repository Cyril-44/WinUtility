#include<bits/stdc++.h>
using namespace std;
int c,u,k,n,m,ans;
struct nod{
    int id,va,p;
}a[100005];
bool cmp1(nod x,nod y){
    if(x.va/x.id!=y.va/y.id) return x.va/x.id>y.va/y.id;
    else if(x.va!=y.va) return x.va>y.va;
    else return x.p<y.p;
};
bool cmp2(nod x,nod y){
    return x.va>y.va;
};
void dfs(int t){
    if(t>n){
        sort(a+1,a+n+1,cmp1);
        int k=0,ans1=0,l=0,ans2=0;
        for(int i=1;i<=n;i++){
            if(k+a[i].id<=m){
                k+=a[i].id;
                ans1+=a[i].va;
            }
        }
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n;i++){
            if(l+a[i].id<=m){
                l+=a[i].id;
                ans2+=a[i].va;
            }
        }
        if(ans1>=ans2) ans++;
        return;
    }
    a[t].id=1;
    dfs(t+1);
    a[t].id=2;
    dfs(t+1);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>u;
    while(u--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i].va;
            a[i].p=i;
        }
        dfs(1);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

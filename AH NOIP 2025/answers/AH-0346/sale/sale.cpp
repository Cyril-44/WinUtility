#include<bits/stdc++.h>
using namespace std;
long long C,T,n,m,a[5005],w[5005],c[5005],cnt,w1[5005],w2[5005],pre1[5005],pre2[5005];
bool cmp(int x,int y){
    return (a[x]*2/w[x]!=a[y]*2/w[y])?(a[x]*2/w[x]>a[y]*2/w[y]):a[x]>a[y];
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        cnt=0;
        for(int s=0;s<(1<<n);s++){
            for(int i=0;i<n;i++){
                if(s&(1<<i)){
                    w[i+1]=1;
                }else{
                    w[i+1]=2;
                }
            }
            for(int i=1;i<=n;i++)c[i]=i;
            sort(c+1,c+n+1,cmp);
            long long sum=0,tmp=m,ans=0,cnt1=0,cnt2=0;
            for(int i=1;i<=n;i++){
                if(tmp>=w[c[i]]){
                    tmp-=w[c[i]];
                    sum+=a[c[i]];
                }
                if(w[i]==1)w1[++cnt1]=a[i];
                else w2[++cnt2]=a[i];
            }
            sort(w1+1,w1+cnt1+1);
            reverse(w1+1,w1+cnt1+1);
            sort(w2+1,w2+cnt2+1);
            reverse(w2+1,w2+cnt2+1);
            for(int i=1;i<=cnt1;i++){
                pre1[i]=pre1[i-1]+w1[i];
            }
            for(int i=1;i<=cnt2;i++){
                pre2[i]=pre2[i-1]+w2[i];
            }
            for(int i=0;i<=cnt2;i++){
                if(i*2>m)break;
                int j=m-i*2;
                ans=max(ans,pre2[i]+pre1[min((long long)j,cnt1)]);
            }
            if(sum==ans)cnt++;
        }
        //dfs(1);
        cout<<cnt<<endl;
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[3005],sum[3005],c[3005][3005],d[3005][3005],a[3005][12005],n,Q;
deque<int>q;
void pushup(int id,int now){
    a[id][now] = max(a[id][now*2],a[id][now*2+1]);
}
void build(int id,int now,int l,int r){
    if(l == r){
        a[id][now] = d[id][l];
        return;
    }
    int mid;
    mid = (l+r)/2;
    build(id,now*2,l,mid);
    build(id,now*2+1,mid+1,r);
    pushup(id,now);
}
int find(int id,int now,int l,int r,int fl,int fr){
    if(r<fl || l>fr){
        return -1e18;
    }
    if(fl<=l && r<=fr){
        return a[id][now];
    }
    int mid;
    mid = (l+r)/2;
    return max(find(id,now*2,l,mid,fl,fr),find(id,now*2+1,mid+1,r,fl,fr));
}
signed main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>b[i];
        sum[i] = sum[i-1]+b[i];
    }
    memset(c,-0x3f,sizeof(c));
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            c[i][j-i+1] = sum[j]-sum[i-1];
        }
    }
    for(int i = 1;i<=n;i++){//len
        while(!q.empty()){
            q.pop_back();
        }
        for(int j = 1;j<=n;j++){//st
            if(!q.empty() && q.front()+i-1<j){
                q.pop_front();
            }
            while(!q.empty() && c[q.back()][i]<=c[j][i]){
                q.pop_back();
            }
            q.push_back(j);
            d[j][i] = c[q.front()][i];
        }
    }
    for(int i = 1;i<=n;i++){
        build(i,1,1,n);
    }
    cin>>Q;
    while(Q--){
        int l,r;
        cin>>l>>r;
        unsigned int ans;
        ans = 0;
        for(int i = 1;i<=n;i++){
            unsigned int num;
            num = find(i,1,1,n,l,r);
            num = num*i;
            ans = ans^num;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

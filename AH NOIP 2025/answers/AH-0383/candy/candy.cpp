#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
    long long v1,v2,v,id;
}a[100005];
long long t1,t2,pos,ans;
bool cmp(node x,node y){
    if(x.v!=y.v)
        return x.v<y.v;
    return x.v1<y.v1;
}
bool cmp1(node x,node y){
    return x.v1<y.v1;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].v1>>a[i].v2;
        a[i].v=a[i].v1+a[i].v2;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    t1=a[1].v1,t2=a[1].v,pos=a[1].id;
    long long tmp=m%t2,c=0;
    if(tmp>=t1){
        c=1;
    }
    ans=m/t2*2+c;
    bool flag=0;
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++){
        if(m<a[i].v1)
            break;
        if(i==pos){
            flag=1;
            continue;
        }
        m-=a[i].v1;
        tmp=m%t2,c=0;
        if(tmp>=t1){
            c=1;
        }
        ans=max(ans,m/t2*2+c+i);
        if(flag){
            m-=t1;
            ans=max(ans,m/t2*2+i+1);
            m+=t1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

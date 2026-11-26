#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct candy{
    long long a,b;
}c[100050];
int n;
long long m,mn=0x3f3f3f3f3f3f3f3fll,sum,ans;
bool cmp(candy a,candy b){
    return a.a<b.a;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>c[i].a>>c[i].b;mn=min(mn,c[i].a+c[i].b);}
    sort(c+1,c+n+1,cmp);
    ans=m/mn*2;
    for(int i=1;i<=n;i++){
        sum+=c[i].a;
        ans=max(ans,(m-sum)/mn*2+i);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

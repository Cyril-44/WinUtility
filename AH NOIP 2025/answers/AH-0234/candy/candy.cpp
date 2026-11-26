#include<bits/stdc++.h>
using namespace std;
int n,xiao,da,mid,bb;
long long m,shu;
struct node{
    int a,b,c;
}can[114514];
bool cmp1(node x,node y){
    return x.c<y.c;
}
bool cmp2(node x,node y){
    if(x.a==y.a) return x.b<y.b;
    return x.a<y.a;
}
int main(){
freopen("candy.in","r",stdin);
freopen("candy.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>can[i].a>>can[i].b;
    can[i].c=can[i].b+can[i].a;
}
sort(can+1,can+1+n,cmp1);
xiao=can[1].a,da=can[1].b;
mid=(xiao+da)>>1;
sort(can+1,can+1+n,cmp2);
for(int i=1;i<=n;i++){
    int jian=can[i].a;
    if(jian>mid){
        bb=i-1;
        break;
    }
    if(jian<=mid){
        m-=jian;
        shu++;
    }
}
int kk=m/(xiao+da);
shu+=kk*2;
m-=kk*(xiao+da);
if(m+can[bb].a>xiao+da) shu++;
cout<<shu<<endl;
return 0;
}

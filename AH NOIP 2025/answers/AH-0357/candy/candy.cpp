#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long m;
struct node{
    long long x,y,z,id;
}a[100010],b[100010];
bool cmp(node a,node b)
{
    if(a.z!=b.z) return a.z<b.z;
    else return a.x<b.x;
}
bool cmp2(node a,node b){
    return a.x<b.x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].z=a[i].x+a[i].y;
        a[i].id=i;
        b[i]=a[i];
    }
    //cout<<minn<<" "<<maxi<<endl;
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp2);
    long long k=0,l=m,t;
    k=t=l/a[1].z*2;
    l%=a[1].z;
    int cnt=0;
    for(int i=1;i<n;i+=2){
        if(b[i].x+b[i+1].x<a[1].z){
            l=l+(a[1].z-b[i].x-b[i+1].x);
            swap(b[i].x,b[i].y);
            swap(b[i+1].x,b[i+1].y);
            cnt=i+1;
        } else {
            break;
        }
    }
    k+=l/a[1].z*2;
    l%=a[1].z;
    if(l+b[cnt].y>=a[1].z){
        l=l+b[cnt].y-a[1].z;
        k++;
    }
    sort(b+1,b+n+1,cmp2);
    for(int i=1;i<=n;i++){
        if(b[i].x<=l){
            l-=b[i].x;
            k++;
        } else {
            break;
        }
    }
    cout<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

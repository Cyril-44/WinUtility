#include<bits/stdc++.h>
using namespace std;
long long n,m,minx=10000000000,mins=100000000000,sum,num,num1,num2,ok1=1,ok2=1;
struct candy{
    long long x,y;
}a[100003];
bool cmp(candy a,candy b){
    return a.x<b.x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y,minx=min(minx,a[i].x),mins=min(mins,a[i].x+a[i].y);
            if(a[i].x!=a[i].y) ok1=0;
            if(a[i].x<a[i].y) ok2=0;
        }
    if(ok1){
        cout<<m/minx;
        return 0;
    }
    else if(ok2){
        num=num1=(m/mins)*2,m=m%mins;
        sort(a+1,a+n+1,cmp);
        while(sum<m) sum+=a[++num-num1].x;
        cout<<num-1;
        return 0;
    }
    else{
        if(n==1){
            num=(m/(a[1].x+a[1].y))*2;
            if(m%(a[1].x+a[1].y)>=a[1].x) num++;
            cout<<num;
            return 0;
        }
        else if(n==2){
            for(int i=0;i<=m;i++){
                    num1=(i/(a[1].x+a[1].y))*2;
                    if(i%(a[1].x+a[1].y)>=a[1].x) num1++;
                    num2=((m-i)/(a[2].x+a[2].y))*2;
                    if((m-i)%(a[2].x+a[2].y)>=a[2].x) num2++;
                num=max(num,num1+num2);
            }
            cout<<num;
            return 0;
        }
    }
}

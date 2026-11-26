#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')f=-1,c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-48,c=getchar();
    return f*x;
}
void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9)write(x/10);
    putchar(x%10+48);
    return ;
}
const int N=1e5+7;
int n,m;
struct node{
    int x,y,s;
};
vector<node>a;
bool cmp(node a,node b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
int ans,p;bool f;
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    n=read(),m=read();
    int j=0;
    node mi;mi.s=LLONG_MAX;
    for(int i=0;i<n;i++){
        int x=read(),y=read();
        a.push_back({x,y,x+y});
        if(a.back().s<mi.s){mi=a.back();}
        if(a.back().s==mi.s&&a.back().x<mi.x){mi=a.back();}
    }
    sort(a.begin(),a.end(),cmp);
    for(auto i:a){
        if(i.x==mi.x&&i.y==mi.y)break;
        j++;
    }
    ans=m/mi.s;
    p=m-ans*mi.s;f=1;
    ans*=2;
    if(!p){
        printf("%lld",ans);
        return 0;
    }
       // printf("min%lld:%lld %lld %lld\n",j,mi.x,mi.y,mi.s);
        //print();
    for(int i=0;i<a.size();i++){
            //printf("    %lld:%lld %lld %lld\n",i,a[i].x,a[i].y,a[i].s);
        if(a[i].x>mi.s)break;
        if(i==j){
            if(f&&a[i].x<=p){
                p-=a[i].x;
                ans++;
            }else if(!f&&a[i].y<=p){
                p-=a[i].y;
                ans++;
            }
        }else if(a[i].x<=p){
            p-=a[i].x;
            ans++;
        }else{
            if((j==i+1&&((f&&a[i].x+a[i+1].x+a[i+2].x<=p+mi.s)||(!f&&a[i].x+a[i+1].y+a[i+2].x<=p+mi.s)))||(j==i+2&&((f&&a[i].x+a[i+1].x+a[i+2].x<=p+mi.s)||(!f&&a[i].x+a[i+1].x+a[i+2].y<=p+mi.s)))||(j!=i+1&&j!=i+2&&a[i].x+a[i+1].x+a[i+2].x<=p+mi.s)){
                p=p+mi.s-a[i].x;
                ans--;
            }else if((f&&j!=i+1&&a[i].x+a[i+1].x<=p+mi.y)){
                    p=p+mi.y-a[i].x;
                    f^=1;
            }else if((!f&&j!=i+1&&a[i].x+a[i+1].x<=p+mi.x)){
                    p=p+mi.x-a[i].x;
                    f^=1;
            }
        }
            //print();
    }
    printf("%lld",ans);
    return 0;
}

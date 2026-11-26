#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
template <typename T>
inline void in(T &x){
    int f=1;x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
    return;
}
struct Candy{
    int x,y;
    bool f;
}c[N];
bool AF;
int n,id,txt;
long long m,ans=1e15,cnt;
bool cmp1(Candy a,Candy b){
    return a.x<b.x;
}
bool cmp2(Candy a,Candy b){
    return a.y<b.y;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    in(n),in(m);
    for(int i=1;i<=n;i++){
        in(c[i].x),in(c[i].y);
        if(c[i].x<c[i].y) AF=0;
        if(ans>c[i].x+c[i].y){
            ans=c[i].x+c[i].y;
            id=i;
        }
    }
    if(AF==1){
        // cout<<id<<endl;
        cnt+=(m/ans)*2,m%=ans;
        // cout<<m<<endl;
        bool vis=1;
        while(m){
            if(txt%2==0){//拿第一个糖果
                sort(c+1,c+1+n,cmp1);
                if(txt==0) for(int i=1;i<=n;i++) cout<<c[i].x<<" "<<c[i].y<<endl;
                for(int i=1;i<=n;i++){
                    if(m>=c[i].x&&c[i].f==0){
                        m-=c[i].x;
                        cnt++;
                        c[i].f=1;
                        vis=1;
                    }
                    if(m<c[i].x){
                        if(!vis) m=0;
                        else vis=0;
                        break;
                    }
                }
            }
            else{//拿第二个糖果
                sort(c+1,c+1+n,cmp2);
                for(int i=1;i<=n;i++){
                    if(m>=c[i].y&&c[i].f==1){
                        m-=c[i].y;
                        cnt++;
                        c[i].f=0;
                        vis=1;
                    }
                    if(m<c[i].y){
                        if(!vis) m=0;
                        else vis=0;
                        break;
                    }
                }
            }
            txt++;
        }
        printf("%lld\n",cnt);
        return 0;
    }
    else if(n==1){
        printf("%lld\n",m/ans*2+((m%ans)>=c[1].x?1:0));
        return 0;
    }
    else if(n==2){
        printf("%lld\n",m/ans*2+((m%ans)>=min(c[1].x,c[2].x)?1:0));
        return 0;
    }
    else{
        // cout<<id<<endl;
        cnt+=(m/ans)*2,m%=ans;
        // cout<<m<<endl;
        bool vis=1;
        while(m){
            if(txt%2==0){//拿第一个糖果
                sort(c+1,c+1+n,cmp1);
                if(txt==0) for(int i=1;i<=n;i++) cout<<c[i].x<<" "<<c[i].y<<endl;
                for(int i=1;i<=n;i++){
                    if(m>=c[i].x&&c[i].f==0){
                        m-=c[i].x;
                        cnt++;
                        c[i].f=1;
                        vis=1;
                    }
                    if(m<c[i].x){
                        if(!vis) m=0;
                        else vis=0;
                        break;
                    }
                }
            }
            else{//拿第二个糖果
                sort(c+1,c+1+n,cmp2);
                for(int i=1;i<=n;i++){
                    if(m>=c[i].y&&c[i].f==1){
                        m-=c[i].y;
                        cnt++;
                        c[i].f=0;
                        vis=1;
                    }
                    if(m<c[i].y){
                        if(!vis) m=0;
                        else vis=0;
                        break;
                    }
                }
            }
            txt++;
        }
        printf("%lld\n",cnt);
        return 0;
    }
    return 0;
}

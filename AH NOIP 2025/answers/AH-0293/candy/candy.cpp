#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int sign=1,res=0;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        res=(res<<3)+(res<<1)+c-48;
        c=getchar();
    }
    return res*sign;
}
const int MAXN=1e5+5;
typedef long long ll;
struct candy{
    int kind,val;
    bool flag;
    bool operator < (const candy&x)const{
        return x.val<val;
    }
}c1[MAXN],c2[MAXN];
priority_queue <candy> q;
signed main(){

    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    int n=read();
    ll m=read();
    ll sum=0;
    unsigned int min_sum=0x7f7f7f7f,minn;
    for(int i=1;i<=n;i++){
        int x=read(),y=read();
        c1[i].kind=i;
        c1[i].val=x;
        c1[i].flag=0;
        c2[i].kind=i;
        c2[i].val=y;
        c2[i].flag=1;
        if(min_sum>x+y){
            min_sum=x+y;
            minn=i;
        }
        q.push(c1[i]);
    }
    while(m>=q.top().val){
        candy top1=q.top();
        q.pop();
        candy top2=q.top();
        if((top1.val+top2.val)<=min_sum){
            sum++;
            m-=top1.val;
            if(top1.flag){
                q.push(c1[top1.kind]);
            }else{
                q.push(c2[top1.kind]);
            }
        }else{
            q.push(top1);
            break;
        }
    }
    if(m>=min_sum){
        sum+=(m/min_sum)<<1;
        m%=min_sum;
    }
    while(m>=q.top().val){
        sum++;
        m-=q.top().val;
        if(q.top().flag){
            candy tmp=q.top();
            q.pop();
            q.push(c1[tmp.kind]);
        }else{
            candy tmp=q.top();
            q.pop();
            q.push(c2[tmp.kind]);
        }
    }
    cout<<sum;

    return 0;
}//                                  \(Ovo)/  Oh~Yeah AC

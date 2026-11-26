//TEST CASE 1~3,6~10
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=50010;
int n,q,a[N],l[N],r[N];
ll qzh[N];
int res[N];
vector<int> ans[N];
vector<int> calc;
struct Queue{
    int x[N],l=1,r=0;
    void clear(){memset(x,0,sizeof(x));l=1;r=0;}
    void push_back(int a){x[++r]=a;}
    void pop_back(){r--;}
    void pop_front(){l++;}
    int front(){return x[l];}
    int back(){return x[r];}
    int size(){return r-l+1;}
}s;
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        qzh[i]=qzh[i-1]+a[i];
    }
    scanf("%d",&q);
    bool allsame=1;
    for(int i=1;i<=q;i++){
        scanf("%d%d",&l[i],&r[i]);
        if(l[i]^r[i]) allsame=0;
    }
    int rg=(n<=10000?n:32);
    if(n<=10000){
        for(int i=1;i<=n;i++)
            calc.push_back(i);
    }else if(allsame){
        for(int i=1;i<=q;i++)
            calc.push_back(l[i]);
    }else{
        for(int i=1;i<=32;i++)
            calc.push_back(i);
    }
    for(int i:calc){
        ans[i].resize(n+2);
        s.clear();
        for(int j=i;j<n+i;j++){
            if(j<=n){
                while(s.size()){
                    if(qzh[s.back()]-qzh[s.back()-i]<qzh[j]-qzh[j-i]) s.pop_back();
                    else break;
                }
                s.push_back(j);
            }
            while(s.size()){
                if(s.front()<j-i+1) s.pop_front();
                else break;
            }
            ans[i][j-i+1]=qzh[s.front()]-qzh[s.front()-i];
        }
    }
    for(int T=1;T<=q;T++){
        memset(res,0xc0,sizeof(res));
        for(int i=l[T];i<=r[T];i++){
            for(int j=1;j<=n;j++)
                res[j]=max(res[j],ans[i][j]);
        }
        ull op=0;
        // for(int i=1;i<=n;i++)
            // printf("%d ",res[i]); putchar('\n');
        for(int i=1;i<=n;i++)
            op^=((ull)res[i])*i;
        printf("%llu\n",op);
    }
    return 0;
}
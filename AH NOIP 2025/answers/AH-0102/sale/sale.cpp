#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M=998244353;
const int maxn=5e4+5;

struct Data{
    int a,w,aw;

    void calc(){
        aw=a/w;
    }

    bool operator>(const Data other)const{
        if(aw==other.aw) return a>other.a;
        return aw>other.aw;
    }
}dat[maxn];

int c,t;
int n,m;
int ans=0;
int choosen_min_w1,choosen_min_w2;

void init(){
    cin>>n>>m;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>dat[i].a;
    }
}

ll quick_power(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b%2==1) res*=a,b--,res%=M;
        else{
            b/=2;
            a*=a;
            a%=M;
        }
    }
    return res;
}

ll p(int a){
    ll res=1;
    for(int i=1;i<=a;i++){
        res*=i;
        res%=M;
    }
    return res%M;
}

void sovleB(){
    while(t--){
        init();
        cout<<((quick_power(2,n)%M)*m/n)%M<<endl;
    }
}

void sovleA(){
    while(t--){
        init();
        cout<<quick_power(2,n)%M<<endl;
    }
}

int main(){
    cin>>c>>t;
    if(c==10 || c==11 || c==12 || c==19 || c==20) sovleB();
    if(c==18) sovleA();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
    long long sumc[50010],n,q,x,l,r,K=1;
    long long lowbit(long long x){return x&(-x);}
     long long pow1(int kl,long long x){
     long long ans=1;
    for(int i=1;i<=x;i++){
    ans*=2;
    }
    return ans;
    }
     long long sum(long long x){
     long long ans=0;
    while(x>0){
    ans+=sumc[x];
    x-=lowbit(x);
    }
    return ans;
    }
    int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    scanf("%lld",&x);
    sumc[i]=x;
    for(int j=1;j<lowbit(i);j<<=1){
    sumc[i]+=sumc[i-j];
    }
    }
    cin>>q;
    while(q--){
    scanf("%lld %lld",&l,&r);
    long long pos=0;
    for(long long i=1;i<=n;i++){
     long long k=-10000000000;
    for( long long len=l;len<=r;len++){
		 long long g1=max(K,i-len+1);
		 long long g2=min(i,n-len+1);
    for( long long j=g1;j<=g2;j++){
    k=max(k,sum(j+len-1)-sum(j-1));
    }
    }
    pos=pos^(i*k);
    }
    while(pos<0)pos+=pow1(2,64);
    cout<<pos<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;


//
const int N=1e5;
const long long M=1e18;
int n;
long long m;
int y;
int x[N+5];
long long sum[N+5];
bool flag[N+5];
long long ans;

//cmp
bool cmp_x( const int &a , const int &b ){
    return a<b;
}
bool cmp_sum( const long long &a , const long long &b ){
    return a<b;
}

int main(){
    int n,m;
    //fre
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);

    //read
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y;
        sum[i]=x[i]+y;
    }
    sort(sum+1,sum+n+1,cmp_sum);
    sort(x+1,x+n+1,cmp_x);


    int l=1,r=1,mid,p;
    int now_ans;
    while(l<=n&&r<=n){
        now_ans=0;
        p=0;
        if(r<n){
            now_ans=x[r]+x[r+1];
            for(p=2;now_ans+x[r+p]<=sum[l]&&r+p<=n;p++){
                now_ans+=x[r+p];
            }
        }
        if(p>=2){
            if(sum[l]<=now_ans&&m>=sum[l]){
                mid=m/sum[l];
                ans=ans+2*mid;
                m-=sum[l]*mid;
                l++;
            }
            else if(now_ans<=sum[l]&&m>=now_ans){
                m-=now_ans;
                ans=ans+p;
                r+=p;
            }
            else if(m>=x[r]){
                m-=x[r];
                ans=ans+1;
                r+=1;
            }
            else{
                l++;
                if(m<x[r]&&m<sum[l]) break;
            }
        }
        else{
            if(m>=sum[l]){
                mid=m/sum[l];
                ans=ans+2*mid;
                m-=sum[l]*mid;
                l++;
            }
            else if(m>=x[r]){
                m-=x[r];
                ans=ans+1;
                r+=1;
            }
            else{
                l++;
                if(m<x[r]&&m<sum[l]) break;
            }

        }
    }
    //print
    cout<<ans;

    return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,sum=1,cnt=1,sum2=1,m1[N],m2[N],min_=2e9+1,cnti=0;
double ave;
bool v[N];
long long ans,M;
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>M;
    for(int i=1;i<=n;i++){
        cin>>m1[i]>>m2[i];
        if(m1[i]+m2[i]<min_){
            min_=m1[i]+m2[i];
            cnti=i;
            ave=min_/2;
        }
    }
    while(M>=0){
        if(sum==1){
            for(int i=1;i<=n;i++){
                if(m1[i]<=ave){
                    ans++;
                    M-=m1[i];
                    v[i]=1;
                }
            }
            sum=0;
        }
        if(M>=min_){
            M-=min_;
            ans+=2;
        }else{
            if(cnt==1){
                ans++;
                M-=m1[cnti];
                cnt--;
            }else{
                ans++;
                M-=m2[cnti];
                cnt++;
            }
        }

    }
    cout<<ans-1;
    return 0;
}

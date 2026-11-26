#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6+5;

long long n,m;
long long ans = 0;
long long x[maxn];
long long y[maxn];

int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    long long min1 = 0x7f7f7f7f;
    long long bj = 0;
    long long bj2 = 1;
    long long bj3 = 0;
    long long bj4 = 0;
    for(long long i=1;i<=n;i++){
        cin >> x[i] >> y[i];
        if(x[i]+y[i]<min1){
            min1=x[i]+y[i];
            bj=x[i];
            bj2=1;
            bj3=x[i];
            bj4=y[i];
            if(y[i]>x[i]){
                bj=y[i];
                bj2=2;
            }
        }
    }
    sort(x+1,x+n+1);
    long long s = 0x7f7f7f7f;
    if(bj2==1){
        for(long long i=1;i<=n;i++){
            if(x[i]<bj&&i%2==0){
                if(x[i-1]+x[i]>=min1){
                    if(x[i-1]<=bj4){
                        m=m-x[i-1];
                        ans++;
                    }
                    if(x[i]<=bj4){
                        m=m-x[i];
                        ans++;
                    }
                    break;
                }
                if(m-x[i-1]>=0){
                    m=m-x[i-1];
                    ans++;
                }
                if(m-x[i]>=0){
                    m=m-x[i];
                    ans++;
                }
            }
            if(x[i]>=bj){
                if(i%2==0){
                    s=x[i-1];
                }
                break;
            }
        }
    }
    if(bj2==2){
        long long b = 0;
        for(long long i=1;i<=n;i++){
            long long t = i;
            if(x[i]==bj3){
                b=1;
                if(m-x[i]>=0){
                    m=m-x[i];
                    ans++;
                }
                continue;
            }
            if(b==1)
                t--;
            if(x[i]<bj&&t%2==0){
                m=m-x[i-1];
                ans++;
                if(x[i-1]+x[i]>=min1)
                    break;
                if(m>0){
                    m=m-x[i];
                    ans++;
                }
            }
            if(x[i]>=bj){
                if(t%2==0){
                    if(m-x[i-1]>=0){
                        m=m-x[i-1];
                        ans++;
                    }
                }
                break;
            }
        }
        if(m-bj3>=0){
            m=m-bj3;
            ans++;
        }
        else{
            cout << ans;
            return 0;
        }
    }
    long long m2 = m%min1;
    long long t = m/min1*2;
    m=m2;
    ans+=t;
    if(m-s>=0){
        m=m-s;
        ans++;
    }
    if(m-bj3>=0){
        m=m-bj3;
        ans++;
    }
    // cout << ans << " " << bj2 << " " << min1 << " " << bj3;
    cout << ans;
    return 0;
}
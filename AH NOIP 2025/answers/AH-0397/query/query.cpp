#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=5e4+10;
int n,a[N],q;
ll s[N];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=a[i]+s[i-1];
	}
	cin>>q;
	while(q--){
        int l,r;
        ull ans=0;
        cin>>l>>r;
        for(int i=1;i<=n;i++){
            ll k=LONG_LONG_MIN;
            for(int li=max(1,i-r+1);li<=i;li++){
                for(int ri=max(i,li+l-1);ri<=i+r-1&&ri-li<=r-1&&ri-li>=l-1;ri++){
                    k=max(k,s[ri]-s[li-1]);
                }
            }
            ans^=i*k;
        }
        cout<<ans<<endl;
	}
	return 0;
}


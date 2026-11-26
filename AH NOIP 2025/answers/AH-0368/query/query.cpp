#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,a[N],q,l,r;
int main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	scanf("%d",&q);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
	while(q--) {
	    scanf("%d %d",&l,&r);
	    unsigned long long P=0;
		    for(int i=1;i<=n;i++) {
	            
			    ans=(unsigned long long) ans;
			    unsigned long long k=i;
			    unsigned long long p=ans*k;
			    P^=p;
		    }
		    cout<<"\n";
		    cout<<P<<"\n";
	}
    return 0;	
}

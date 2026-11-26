#include <bits/stdc++.h>
using namespace std;
int c, t, n, m, ans;
struct aa{ 
	int a;   
    int f;
    double p;
}s[5005];
bool cmp(aa o, aa i){
	if(o.p==i.p)
	    return o.a>i.a;
    return o.p>i.p;
}
void dfs(int i, int j){
	s[i].f=j;
	s[i].p=1.0*s[i].a/j;
	if(i==n){
		int kp1=0, fl=0, max1=0, max2=0, m1=m;
		sort(s+1, s+n+1, cmp);
		for(int k=1; k<=n; k++){
		    if(s[k].f<=m1){
		        m1-=s[k].f;
		        kp1+=s[k].a;
			}
		}
		printf("%d\n", kp1);
		for(int k=1; k<=n; k++){
			if(s[k].f==2 && s[k].a>kp1){
			    fl=1;
			    break;
			}
			if(s[k].f==1){
				if(s[k].f>max2)
				    max2=s[k].a;
			    if(s[k].f>max1){
			        max2=max1;
			        max1=s[k].a;
				}
			}
			if(max1+max2>kp1){
				fl=1;
				break;
			}
		}
		if(fl==1){
		    ans--;
		    ans%=998244353;
		}
		ans++;
		return ;
	}
    dfs(i+1, 1);
    dfs(i+1, 2);
}
int main(){
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while(t--){
		ans=0;
		memset(s, 0, sizeof(s));
		scanf("%d %d", &n, &m);
		int k=0;
		for(int i=1; i<=n; i++){
		    scanf("%d", &s[i].a);
		    if(s[i].a!=s[i-1].a)
		        k=1;
		}
		if(k==0){
			ans=1;
		    for(int i=1; i<=n; i++)
		        ans=ans%998244353*2;
		}
		else{
			if(m==2){
				dfs(1, 1);
		        dfs(1, 2);
			}
	    }
	    printf("%d\n", ans);
	}
    return 0;
}

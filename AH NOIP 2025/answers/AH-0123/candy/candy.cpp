#include<bits/stdc++.h>
using namespace std;
int n;
long long m,s2,ans,s1,s;
struct node{
	long long x,y;
}a[100005];
bool cmp(node a,node b){
    return a.x+a.y<=b.x+b.y;
}
bool cmmp(node a,node b){
    return a.x<=b.x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	s=a[1].x+a[1].y;
	s1=m/s;
	s2=m-s1*s;
	s1*=2;
	sort(a+1,a+n+1,cmmp);
	int i=1;
	while(i<=n){
        ans=max(ans,s1);
        if(s2>=a[i].x){
            s2-=a[i].x;
            s1++;
            i++;
        }
        else{
            if(s1<2)break;
            else{
                s1-=2;
                s2+=s;
                if(s<a[i].x)break;
            }
        }
	}
	printf("%lld \n",max(ans,s1));
    return 0;
}
/*!noip@Nov29,2025:dream*/

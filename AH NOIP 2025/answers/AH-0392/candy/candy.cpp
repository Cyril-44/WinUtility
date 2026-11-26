#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,f=0,mi=10000000000;
struct stu{
    long long a,b,c;
}s[100010];
bool  cmp(const stu &x,const stu &y){
  if(x.c!=y.c)return x.c<y.c;
  else return x.a<y.a;
}
bool  cmp1(const stu &x,const stu &y){
  return x.a<y.a;
}
    int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    long long m1=m;
    for(int i=1;i<=n;i++){
    scanf("%lld %lld",&s[i].a,&s[i].b);
    s[i].c=s[i].a+s[i].b;
    }
    sort(s+1,s+n+1,cmp);
    sort(s+2,s+n+1,cmp1);
    for(int i=2;i<=n;i++){
		if(s[i].a<s[1].c*1.0/2&&s[i].a>s[1].a&&s[1].a<=m&&f==0||s[i].a<s[1].c*1.0/2&&s[i].a==s[1].a&&s[1].a<=m&&f==0){
			cnt++;
			m-=s[1].a;
			s[1].a=s[1].b;
			f=1;
		}
    if(s[i].a<s[1].c*1.0/2&&m>=s[i].a){
		cnt++;
		m-=s[i].a;
		s[i].a=s[i].b;
	}
	else break;
    }
    cnt+=(m/s[1].c)*2;
    m%=s[1].c;
		for(int i=1;i<=n;i++){
			mi=min(mi,s[i].a);
		}
		if(m>=mi){
			cnt++;
		}
		long long cnt1=0;
		for(int i=1;i<=n;i++)s[i].a=s[i].c-s[i].b;
		cnt1+=(m1/s[1].c)*2;
    m1%=s[1].c;
    f=0;
    for(int i=2;i<=n;i++){
		if(s[i].a>s[1].a&&s[1].a<=m1&&f==0||s[i].a==s[1].a&&s[1].a<=m1&&f==0){
			cnt1++;
			m1-=s[1].a;
			s[1].a=s[1].b;
			f=1;
		}
    if(m1>=s[i].a){
		cnt1++;
		m1-=s[i].a;
		s[i].a=s[i].b;
	}
	else break;
    }
    long long pl=max(cnt,cnt1);
		cout<<pl;
    return 0;
}

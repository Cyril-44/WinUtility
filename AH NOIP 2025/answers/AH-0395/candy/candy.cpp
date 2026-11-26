#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P pair<ll, int>
int n, tmp=0;
long long m, ans, sum;
struct node{
    ll x, y, s;
    int id;
}p[100005];
bool cmp(node x, node y){
	if (x.s==y.s) return x.x<y.x;
	else return x.s<y.s;
}
bool cmp1(node x, node y){
	return x.x<y.x;
}
bool cmp2(node x, node y){
	return x.y<y.y;
}
void ts(){
	sort(p+1, p+n+1, cmp1);
    ll k=m/p[1].x, h=p[1].x;
    //cout << h << '\n';
    ans=k;
    m-=k*h;
	printf("%lld", ans);
	return;
}
//priority_queue<P, vector<P>, greater<P> > q;
/*bool operator <(const node b){
	return */
//queue <int> idq;
int main(){
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i=1; i<=n; i++){
        scanf("%lld%lld", &p[i].x, &p[i].y);
        p[i].s=p[i].x+p[i].y;
        p[i].id=i;
        if (p[i].x!=p[i].y) tmp=1;
        //sum+=p[i].x;
        //q.push(P(p[i].x, i*10+1));
        //idq.push(1);
    }
    if (!tmp){
		ts();
		return 0;
	}
    sort(p+1, p+n+1, cmp);
    //cout << p[1].x << ' ' << p[1].y << "\n\n";
    ll k=m/p[1].s-1, h=p[1].s;
    //cout << h << '\n';
    ans=2*k;
    m-=k*p[1].s;
    sort(p+1, p+n+1, cmp1);
    int i=1;
    ll sum1=0;
    while (sum1+p[i].x<=m && i<=n){
		//cout << p[i].x << ' ' << p[i].y << '\n';
		sum1+=p[i].x;
		i++;
	}
	if (i>2) ans+=i-1, m-=sum1;
	else {
		ans+=2, m-=h;
	    sort(p+1, p+n+1, cmp1);
	    i=1;
	    while (m>=p[i].x && i<=n){
		    m-=p[i].x;
		    i++;ans++;
	    }
	}
	sort(p+1, p+i, cmp2);
	i=1;
	while (m>=p[i].y && i<=n){
		m-=p[i].y;
		i++;ans++;
	}
    /*while (m>=q.top().first && !q.empty()){
        ll x=q.top().first;
        int t=q.top().second;
        q.pop();
        m-=x;
        //cout << x << ' ';
        if (t%10==1){
            q.push(P(p[t/10].y, (t/10)*10+2));
        }else q.push(P(p[t/10].x, (t/10)*10+1));
        ans++;
    }*/
    printf("%lld", ans);
    return 0;
}
//记得调。。。

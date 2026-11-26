#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MN=1e5+5;
typedef long long ll;
int n;
ll m;
typedef struct node{
  ll a,b;
  bool operator <(const node &rhs)const{
    return a<rhs.a;
  }
}node;
node num[MN];
bool plc[MN];
bool place[MN];

// void A(){
//   sort(num+1,num+n+1);

// }
typedef struct S{
  ll num;
  int p;
  bool operator <(const S &rhs)const{
    return num>rhs.num;
  }
}S;
inline ll ret(int p){
  plc[p]=!plc[p];
  return plc[p]?num[p].a:num[p].b;
}
inline ll ret2(int p){
  place[p]=!place[p];
  return place[p]?num[p].a:num[p].b;
}
int main(){
  freopen("candy.in","r",stdin);
  freopen("candy.out","w",stdout);
  bool isA=true;
  scanf("%d%lld",&n,&m);
  priority_queue<S> q;
  ll minre=(1LL<<62);
  for(int i=1;i<=n;++i){
  scanf("%lld%lld",&num[i].a,&num[i].b);
    isA=isA&&(num[i].a==num[i].b);
    q.push(S{num[i].a,i});
    plc[i]=true;
    if(num[i].a+num[i].b<minre)minre=num[i].a+num[i].b;
  }
  // if(isA){
  //   A();
  //   return 0;
  // }
  ll money=0;
  int candy=0;
  while(money<m&&(!q.empty())){
    S fir=q.top();
    q.pop();
    if(q.empty())break;
    S sec=q.top();
    q.pop();
    int add=fir.num+sec.num;
    if(money+add>m)break;
    if(add>minre){
      break;
    }
    candy+=2;
    money+=add;
    place[fir.p]=!place[fir.p];
    place[sec.p]=!place[sec.p];
    q.push(S{ret(fir.p),fir.p});
    q.push(S{ret(sec.p),sec.p});
  }
  int cnt=(m-money)/minre;
  money+=cnt*minre;
  candy+=cnt*2;
  priority_queue<S> q2;
  for(int i=1;i<=n;++i){
    q2.push(S{ret2(i),i});
  }
  while(money<m&&(!q2.empty())){
    S qtop=q2.top();
    q2.pop();
    if(money+qtop.num>m)break;
    ++candy;
    money+=qtop.num;
    q2.push({ret2(qtop.p),qtop.p});
  }
  printf("%d\n",candy);
  return 0;
}

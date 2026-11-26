
#include<bits/stdc++.h>
#define\
 ll \
long long
#define  itn  int
#define\
 gc \
getchar


#define             pc putchar
#define             scf scanf
#define             prf printf
#define             fu(v,s,e) \
   for(int v=(s);v<=(e);v++)


#define fd(v,s,e) \
for(int \
v\=(s)\
;v>=(e)\
;v--)
using  
   namespace   std;


int            _t;
int       in(){
int   x=0,f=1;
char c=gc();
while  ((c<'0'
||c>     '9')
&&         c!=
'-')        c=gc();


if(c=='-') c=gc(),
f=-1;
while
(c>='0'
&&c<=
'9') x=x*10+c-'0',


  c=gc();  return x*f;}
template
<typename
 _Tp>
void 
  out(_Tp x){   if(x>9) 


out(x/10);pc(x%10+'0');}
template
<typename
 _Tp>
void out(_Tp x,char
 c){
out(x),
pc(c);}


itn n,m;
struct edge{
    int to,next;
}e[8008];
int h[8080],tot;
#define add(u,v) e[++tot]=edge{v,h[u]},h[u]=tot
int f[8080][8080],dep[8080][808];
int sz[8080];
void dfs(int u,int dept){
    memset(f[u],0,sizeof(f[u]));
    // f[u][0]=0;
    sz[u]=1,dep[u][dept]++;
    for(int i=h[u];i;i=e[i].next){
        int v=e[i].to;
        dfs(v,dept+1);
        sz[u]+=sz[v];
        fu(i,dept+1,m) dep[u][i]+=dep[v][i];
        fu(j,0,sz[u]){
            int mxf=0;
            fu(k,0,min(j,sz[v])) mxf=max(mxf,f[v][k]);
            f[u][j]+=mxf;
        }
    }
    fu(i,0,sz[u]){
        int d=dept,s=0,c=0;
        fu(k,1,sz[u]-i){
            c++;
            if(c>dep[u][d]) c=0,d++;
            s+=d-dept;
            f[u][i+k]=max(f[u][i+k],f[u][i]-s);
        }
        f[u][i]+=i;
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    _t=in();
    while(_t--){
        n=in(),m=in();
        memset(h,0,sizeof(h));
        tot=0;
        fu(i,2,n){
            int u=in();
            add(u,i);
        }
        dfs(1,0);
        int ans=0;
        fu(i,0,n) ans=max(ans,f[1][i]);
        out(ans,'\n');
    }
    cerr<<clock()/1000.0<<'\n';
    return 0;
}
/*
操你妈140走人
蒸蒸日下了
前年314
去年272
今年他妈估计只有140
反正也AFO了，无所弔谓了
*/
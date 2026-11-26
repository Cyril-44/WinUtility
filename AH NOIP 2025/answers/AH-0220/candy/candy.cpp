#include <bits/stdc++.h>
using namespace std;

int n,m,num=0;

struct candy{
    int x,y,everage;
    bool p=false;
};
candy c[100001];

bool cmp(candy a,candy b){
    if(a.everage<b.everage){
        return true;
    }else if(a.everage==b.everage and a.x<b.x){
        return true;
    }else{
        return false;
    }
}

bool cmp1(candy a,candy b){
    return a.x<b.x;
}

int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d %d",&c[i].x,&c[i].y);
        c[i].everage=c[i].x+c[i].y;
    }
    sort(c,c+n,cmp);
    int k=c[0].x,maxc=0,minc=-1;
    sort(c+1,c+n,cmp1);
    for(int i=1;i<n;i++){
        if(c[i].x<k){
            m-=c[i].x;
            c[i].p=true;
            num++;
            maxc=max(maxc,c[i].x);
        }
        if(c[0].x<c[i].x and c[i].x<c[0].y and minc==-1){
            minc=c[i].x;
        }
    }
    num+=m/c[0].everage*2;
    m%=c[0].everage;
    if(m+maxc>=c[0].everage){
        num++;
        m=m+maxc-c[0].everage;
    }
    if(minc+maxc<c[0].everage and minc!=-1){
        m+=c[0].everage-minc-maxc;
    }
    if(m>=c[0].x){
        num++;
    }
    printf("%d",num);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

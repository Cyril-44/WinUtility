#include <bits/stdc++.h>
using namespace std;

int t,n,m;

struct tree{
    int parent,children[8000],c,h,name,q;
};
tree tt[1000],kk[1000];

bool cmp(tree x,tree y){
    return x.h>y.h;
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int num=0;
        scanf("%d %d",&n,&m);
        tt[1].parent=0;
        tt[1].c=0;
        tt[1].h=0;
        tt[1].name=1;
        tt[1].q=-1;
        memset(tt[1].children,n,0);
        kk[1]=tt[1];
        for(int i=2;i<=n;i++){
            scanf("%d",&tt[i].parent);
            memset(tt[i].children,n,0);
            tt[i].q=-1;
            tt[i].name=i;
            tt[i].c=0;
            tt[i].h=tt[tt[i].parent].h+1;
            tt[tt[i].parent].children[tt[tt[i].parent].c]=i;
            tt[tt[i].parent].c++;
            kk[i]=tt[i];
        }
        sort(kk+1,kk+n+1,cmp);
        int maxh=0;
        for(int j=1;j<=n;j++){
            int i=kk[j].name;
            if(j==1){
                maxh=tt[i].h;
            }
            if(tt[i].h==maxh){
                int p=tt[i].parent;
                if(tt[p].c==1){
                    tt[i].q=0;
                    num++;
                }else{
                    int o=0,maxm=-1;
                    bool z=false;
                    for(int s=0;s<tt[p].c;s++){
                        maxm=max(maxm,tt[tt[p].children[s]].q);

                    }
                    if(maxm==-1){
                        tt[i].q=0;
                        num++;
                    }else{
                        tt[i].q=maxm+1;
                    }
                }
            }else{
                if(tt[i].c==0){
                    tt[i].q=0;
                    num++;
                }else if(tt[i].c==1){
                    tt[i].q=tt[tt[i].children[0]].q+1;
                    num+=tt[i].q+1;
                }else{
                    int maxq=max(tt[tt[i].children[0]].q,tt[tt[i].children[1]].q);
                    for(int l=0;l<tt[i].c;l++){
                        maxq=max(maxq,tt[tt[i].children[l]].q);
                    }
                    num+=maxq+2;
                    tt[i].q=maxq+1;
                }
            }
        }
        printf("%d\n",num);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

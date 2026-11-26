#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

inline long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
void put_ll(long long x){

    if(x<0){
        putchar('-');
        x=-x;
    }
    char c=(x%10)+'0';
    if(x>9){
        put_ll(x/10);
    }
    putchar(c);
    return ;

}
struct S{
    long long x;
    long long y;
    bool cnt;
    int id;
    /*operator < (const S &w,const S &y){

    }*/
}t;
vector<S> a;
long long n,m;
//priority_queue<S> b;
bool cmp(const S &x,const S &y){
    long long  u=0,v=0;
    if(x.cnt){
        u=x.y;
    }
    else{
        u=x.x;
    }

    if(y.cnt){
        v=y.y;
    }
    else{
        v=y.x;
    }
    return u<v;
}
long long num(S x){
    if(x.cnt){
        return x.y;
    }
    else{
        return x.x;
    }
}
long long ans=0;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);

    n=read();
    m=read();
    int texta=0;
    for(int i=1;i<=n;i++){
        long long x,y;
        x=read();
        y=read();
        if(x==y){
            texta++;
        }
        S c;
        c.x=x;
        c.y=y;
        c.cnt=false;
        c.id=i;
        a.push_back(c);
    }

    sort(a.begin(),a.end(),cmp);
    if(texta==n){
        ans=(m/num(a[0]));
        put_ll(ans);
        return 0;
    }
    S ft;
    ft=a[0];
    for(int i=1;i<a.size();i++){
        if((a[i].x+a[i].y)<(ft.x+ft.y)){
            ft=a[i];
        }
    }

    while(num(a[0])<=ft.y&&a[0].id!=ft.id){
        m-=num(a[0]);
        a[0].cnt=!a[0].cnt;
        ans++;
        t=a[0];


        /*cout<<"sou;;;";
        a.erase(a.begin());
        for(int i=0;i<a.size();i++){
            if(num(t)<num(a[i])){
                a.insert(a.begin()+i,t);
            }
        }
        for(int i=0;i<a.size();i++){
            cout<<num(a[i])<<endl;

        }*/


        sort(a.begin(),a.end(),cmp);
    }
    ans+=(m/(ft.x+ft.y))*2;
    m=m%((ft.x+ft.y));
    //cout<<m<<endl;
    bool flag=false,flag2=false;
    int ct=0;
    for(int i=0;i<a.size();i++){
        if(m<num(a[i])){
            break;
        }
        m-=num(a[i]);
        ans++;
    }
    /*while(m){
        //cout<<m<<" "<<num(a[0])<<endl;
        if((!flag)&&(!flag2)){
            ft=a[0];
            flag=true;
            flag2=true;
            ct=0;
        }
        if(a[0].id==ft.id){

        }
        if(m*1.0/num(a[0])>=1){
            m-=num(a[0]);
            a[0].cnt=!a[0].cnt;
            ans++;
            ct++;
        }
        else{
            break;
        }
        sort(a.begin(),a.end(),cmp);
    }*/
    put_ll(ans);





    /*for(int i=0;i<a.size();i++){
        cout<<endl<<a[i].x<<" "<<a[i].y<<endl;

    }*/
    return 0;
}

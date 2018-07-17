#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 100003
using namespace std;
struct data{
    int sum,ls,rs,tag,ll,rr,all;
}tr[N*4];
int n,m,a[N],val[N],pos[N];
data update(data l,data r)
{
    data now; now.tag=0;
    now.ls=l.ls; now.rs=r.rs;//ls,rs表示区间左右端点的数值 
    now.ll=l.ll; now.rr=r.rr;//ll,rr表示区间左右两端单独数的个数(没有连续的相同数值) 
    if (l.all) //all表示区间中是否都是单独数 
     if (l.rs==r.ls) now.ll--;
     else now.ll+=r.ll;
    if (r.all)
     if (l.rs==r.ls) now.rr--;
     else now.rr+=l.rr;
    now.sum=l.sum+r.sum;
    if (l.all&&r.all&&l.rs!=r.ls) now.all=1;
    else now.all=0;
    if (l.all) {
        if (l.rs==r.ls) {
            if (r.all) now.sum=1;// 1 2 3 | 3 2 1
            else if (r.ll) now.sum+=(r.ll-1)/2+1; // 1 2 3 5 4 | 4 2 3 3 2 
            // (1 2) (4 7) |(12 16 20) (22 25 28)| (30)
        }
    }  
    else if (l.rr) {
        if (l.rs==r.ls){
            if (r.all) now.sum+=(l.rr-1)/2+1;// 1 2 2 3|3 2 1 3
            // (1) |(2 4 6) (9 12)| (14 15) (18)
            else if (r.ll) now.sum+=(r.ll-1)/2+(l.rr-1)/2+1; // 1 2 2 3 | 3 2 2 1
            // (1) |(2 4 6) (9) (12 14 16)| (17)
            else now.sum+=(l.rr-1)/2; //1 2 2 3 |3 3 3 1
            // (1) (2 4 6) (9 12 15 18) (19)
        }
        else if (!r.all) now.sum+=(l.rr+r.ll)/2; // 1 2 2 3 | 4 5 5 7 
        //1 |(2 4 6) (9 13) (18 23)| 30
    }
    else {
        if (l.rs==r.ls) {
            if (!r.all) {
                if (r.ll) now.sum+=(r.ll-1)/2; // 1 2 2 | 2 3 3
                // (1) (2 4 6 8) (11 14)
                else now.sum--; //1 2 2| 2 2 1
                // (1) (2 4 6 8 10) (11)
            }
        }
        else {
            if (!r.all&&r.ll) now.sum+=r.ll/2; //1 2 2| 3 2 2
            // (1) (2 4 6) (9 11 13)
        }
    }
    return now;
}
void build(int now,int l,int r)
{
    if (l==r) {
        tr[now].sum=0; tr[now].ll=tr[now].rr=tr[now].all=1;
        tr[now].ls=tr[now].rs=a[l];
        pos[l]=now;
        return;
    }
    int mid=(l+r)/2;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    tr[now]=update(tr[now<<1],tr[now<<1|1]);
}
void change(int now,int val)
{
    tr[now].ls+=val; tr[now].rs+=val;
    tr[now].tag+=val;
}
void pushdown(int now)
{
    if (tr[now].tag){
        change(now<<1,tr[now].tag);
        change(now<<1|1,tr[now].tag);
        tr[now].tag=0;
    }
}
data qjsum(int now,int l,int r,int ll,int rr)
{
    if (ll<=l&&r<=rr) return tr[now];
    int mid=(l+r)/2;
    pushdown(now); data ans; bool pd=false;
    if (ll<=mid) ans=qjsum(now<<1,l,mid,ll,rr),pd=true;
    if (rr>mid) {
        if (!pd) ans=qjsum(now<<1|1,mid+1,r,ll,rr);
        else ans=update(ans,qjsum(now<<1|1,mid+1,r,ll,rr));
    }
    return ans;
}
void pointchange(int now,int l,int r,int x,int val)
{
    if (l==r) {
        tr[now].ls=tr[now].rs+=val;
        tr[now].sum=0; tr[now].ll=tr[now].rr=tr[now].all=1;
        return;
    }
    int mid=(l+r)/2;
    pushdown(now);
    if (x<=mid) pointchange(now<<1,l,mid,x,val);
    else pointchange(now<<1|1,mid+1,r,x,val);
    tr[now]=update(tr[now<<1],tr[now<<1|1]);
}
void qjadd(int now,int l,int r,int ll,int rr,int val)
{
    if (ll>rr) return;
    if (ll<=l&&r<=rr) {
        change(now,val);
        return;
    }
    int mid=(l+r)/2;
    pushdown(now);
    if (ll<=mid) qjadd(now<<1,l,mid,ll,rr,val);
    if (rr>mid) qjadd(now<<1|1,mid+1,r,ll,rr,val);
    tr[now]=update(tr[now<<1],tr[now<<1|1]);
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("my.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&val[i]);
    for (int i=1;i<=n-1;i++) a[i]=val[i+1]-val[i];
    n--; 
    if (n) build(1,1,n);
    scanf("%d",&m);
    for (int i=1;i<=m;i++) {
        char s[10]; int x,y; scanf("%s%d%d",s+1,&x,&y);
        if (s[1]=='A') {
            int a,b; scanf("%d%d",&a,&b);
            if (x-1>=1&&x-1<=n) pointchange(1,1,n,x-1,a); 
            if (y<=n) pointchange(1,1,n,y,-((y-x)*b+a));
            qjadd(1,1,n,x,y-1,b);
        }
        if (s[1]=='B') {
           data t; 
           if (x<=y-1) t=qjsum(1,1,n,x,y-1);
           else t.sum=1;
           if (x==y) printf("%d\n",1);
           else {
             if (t.sum==0) printf("%d\n",(y-x+2)/2);
             else printf("%d\n",t.sum+(t.ll+1)/2+(t.rr+1)/2);
           }    
        }
    }
}

#include<stdio.h>
int fa[60000],r[60000]={0};//r[i]表示并查集的权值 
int n,k;
int ans=0;
int getf(int x)
{
	if(fa[x]!=x)
	{
		int f;
		f=getf(fa[x]);
		r[x]+=r[fa[x]];
		r[x]%=3;
		fa[x]=f;
	}
	return(fa[x]);
}
void bing(int x,int y,int d)
{
	int lx,ly;
	lx=getf(x);
	ly=getf(y);
	r[lx]+=r[y]+d-r[x]+3;
	r[lx]%=3;
	fa[lx]=ly;
}
int main()
{
	int i;
	scanf("%ld%ld",&n,&k);
	for(i=1;i<=n;i++)
		fa[i]=i;
	int e,a,b;
	for(i=1;i<=k;i++)
	{
		scanf("%d%ld%ld",&e,&a,&b);
		if(a>n || b>n)
		{
			ans++;
			continue;
		}
		if(e==2 && a==b)
		{
			ans++;
			continue;
		}
		int la,lb;
		la=getf(a);
		lb=getf(b);
		if(la==lb)
		{
			if(r[a]!=(r[b]+e-1)%3)
				ans++;
			continue;
		}
		bing(a,b,e-1);
	}
	printf("%ld\n",ans);
}

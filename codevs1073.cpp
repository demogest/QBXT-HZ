
#include<cstdio>

const int N = 5050;
int fa[N];
int n,m,p;

void Init()
{
	int i;
	for(i=1;i<=n;i++)
		fa[i]=i;
}

int getf(int x)
{
	while(x!=fa[x])
		x=fa[x];
	return x;
}

int combine(int x,int y)
{
	x=getf(x);
	y=getf(y);
	fa[x]=y;
}


bool query(int x,int y)
{
	x=getf(x);
	y=getf(y);
	return (x==y);
}

int main()
{
	int i,j;
	scanf("%d%d%d",&n,&m,&p);
	Init();
	for(i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		combine(a,b);
	}
	for(i=1;i<=p;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(query(a,b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}


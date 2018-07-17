#include<cstdio>
const int p = 10000007;
int val[p];
int n,m;
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		int s=t%p;
		while(val[s] && val[s]!=t)	//×¢ÒâÈ¥ÖØ 
		{
			s++;
			s%=p;
		}
		val[s]=t;
	}
	for(i=1;i<=m;i++)
	{
		int t;
		scanf("%d",&t);
		int s=t%p;
		while(val[s] && val[s]!=t)
		{
			s++;
			s%=p;
		}
		if(val[s]==t)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

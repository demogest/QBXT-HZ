#include<cstdio>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int ans=a+b;
	if(a%20==0)
		ans++;
	printf("%d\n",ans);
}

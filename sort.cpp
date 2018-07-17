#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000];
int n;
struct A
{
	int x,y;
}b[1000];
bool cmp(int x,int y)
{
	//偶数排在前面，奇数排在后面
	//偶数内部从小到大，奇数内部从大到小 
	if(x%2)
	{
		if(y%2)
			return (x>y);
		else
			return 0;
	}
	else
	{
		if(y%2)
			return 1;
		else
			return (x<y);
	}
}

bool cmpx(A s,A t)
{
	return (s.x>t.x);
}

int main()
{
	n=6;
	int i;
	for(i=1;i<=n;i++)
		a[i]=i;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	
	printf("\n\n");
	
	for(i=1;i<=n;i++)
	{
		b[i].x=100-i;
		b[i].y=i;
	}
	sort(b+1,b+n+1,cmpx);
	for(i=1;i<=n;i++)
		printf("%d %d\n",b[i].x,b[i].y);
};


#include<cstdio>
#include<iostream>
using namespace std;

int getposint()
{
	char ch=getchar();
	while(ch<'0' || ch>'9')
		ch=getchar();
	int res=0;
	while('0'<=ch && ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}

int getint()
{
	char ch=getchar();
	while(ch!='-' && (ch<'0' || ch>'9'))
		ch=getchar();
	int res=0;
	bool neg=0;
	if(ch=='-')
	{
		neg=1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	if(neg)
		res=-res;
	return res;
}

int main()
{
	//freopen("a.txt","r",stdin);
	int i;
	int a;
	while(1)
	{
		printf("%d\n",getint());
	}
	return 0;
}

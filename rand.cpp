#include<cstdio>
#include<cstdlib>
#include<ctime>
int main()
{
	srand(time(0));
	int i;
	for(i=1;i<=10;i++)
		printf("%d\n",rand());
}

#include<cstdio>
#include<cstdlib>
int main()
{
	while(1)
	{
		system("data.exe > pro.in");
		system("pro.exe < pro.in > pro.out");
		system("bs.exe < pro.in > pro.ans");
		if(system("fc pro.out pro.ans"))
			return -1;
	}
	return 0;
}

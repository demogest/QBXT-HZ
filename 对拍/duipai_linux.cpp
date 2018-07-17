#include<cstdio>
#include<cstdlib>
int main()
{
	while(1)
	{
		system("./data > pro.in");
		system("./pro < pro.in > pro.out");
		system("./bs < pro.in > pro.ans");
		if(system("diff pro.out pro.ans"))
			return -1;
	}
	return 0;
}

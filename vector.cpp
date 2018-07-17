#include<cstdio>
#include<vector>
using namespace std;
vector<int> a;
int main()
{
	a.push_back(3);
	a.push_back(5);
	a.push_back(6);
	int i;
	for(i=0;i<a.size();i++)
		printf("%d\n",a[i]);
	printf("\n");
	printf("%d\n",a.size());
	a.pop_back();
	printf("\n");
	for(i=0;i<a.size();i++)
		printf("%d\n",a[i]);
	printf("\n");
	printf("%d\n",a.size());
}

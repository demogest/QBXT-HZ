#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100500;

int heap[N];
int cc;

void Add(int x)
{
	cc++;
	heap[cc]=x;
	int now=cc;
	int nxt=now/2;
	while(now>1 && heap[now]<heap[nxt])
	{
		swap(heap[now],heap[nxt]);
		now=nxt;
		nxt=now/2;
	}
}

int Del()
{
	int res=heap[1];
	heap[1]=heap[cc];
	cc--;
	int now=1;
	int nxt=2;
	if(nxt+1<=cc && heap[nxt+1]<heap[nxt])
		nxt++;
	while(nxt<=cc && heap[nxt]<heap[now])
	{
		swap(heap[nxt],heap[now]);
		now=nxt;
		nxt=now*2;
		if(nxt+1<=cc && heap[nxt+1]<heap[nxt])
			nxt++;
	}
	return res;
}


int main()
{
	Add(3);
	Add(5);
	Add(2);
	printf("%d\n",Del());//2
	Add(1);
	printf("%d\n",Del());//1
	printf("%d\n",Del());//3
	printf("%d\n",Del());//5
}


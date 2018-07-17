
#include<cstdio>
const int N = 200500;
const int M = 600000;
struct Node
{
	int l,r,tot;//������ʾ����[l,r]�ĺ�
	int mid;//��ʾ���������ӽڵ���[l,mid]�����ӽڵ���[mid+1,r]�������ǰ����Ҷ�ڵ�midû����
	long long val;//����[l,r]�ĺ�
	long long tag;//��ʾ��� 
}tree[M];
int n,m;
int data[N];

void MakeTree(int x,int l,int r)
{
	tree[x].l=l;
	tree[x].r=r;
	tree[x].tot=r-l+1;
	if(l==r)
	{
		tree[x].val=data[l];
	}
	else
	{
		int mid=(l+r)/2;
		tree[x].mid=mid;
		MakeTree(x*2,l,mid);
		MakeTree(x*2+1,mid+1,r);
		tree[x].val=tree[x*2].val+tree[x*2+1].val;
	}
}

void AddNode(int v,long long z)
{
	tree[v].val+=z*tree[v].tot;
	tree[v].tag+=z;
}

void Clear(int v)
{
	AddNode(v*2,tree[v].tag);
	AddNode(v*2+1,tree[v].tag);
	tree[v].tag=0;
}

void Add(int v,int a,int b,int z)//��ʾ[a,b]Ҫ����z�����ڴ����v 
{
	if(tree[v].l==a && tree[v].r==b)
	{
		AddNode(v,z);
		return;
	}
	Clear(v);
	if(b<=tree[v].mid)
		Add(v*2,a,b,z);
	else if(a>tree[v].mid)
		Add(v*2+1,a,b,z);
	else
	{
		Add(v*2,a,tree[v].mid,z);
		Add(v*2+1,tree[v].mid+1,b,z);
	}
	tree[v].val=tree[v*2].val+tree[v*2+1].val;
}

long long Find(int v,int a,int b)//��ʾ��[a,b]�ĺͣ����ڴ����v 
{
	if(tree[v].l==a && tree[v].r==b)
		return tree[v].val;
	Clear(v);
	if(b<=tree[v].mid)
		return Find(v*2,a,b);
	if(a>tree[v].mid)
		return Find(v*2+1,a,b);
	return Find(v*2,a,tree[v].mid)+Find(v*2+1,tree[v].mid+1,b);
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&data[i]);
	MakeTree(1,1,n);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		int opt,a,b;
		scanf("%d%d%d",&opt,&a,&b);
		if(opt==1)
		{
			int c;
			scanf("%d",&c);
			Add(1,a,b,c);
		}
		else
			printf("%lld\n",Find(1,a,b));
	}
}




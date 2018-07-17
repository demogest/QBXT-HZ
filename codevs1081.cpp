
#include<cstdio>
const int N = 100500;
const int M = 270000;
struct Node
{
	int l,r;//������ʾ����[l,r]�ĺ�
	int mid;//��ʾ���������ӽڵ���[l,mid]�����ӽڵ���[mid+1,r]�������ǰ����Ҷ�ڵ�midû����
	int val;//����[l,r]�ĺ�
}tree[M];
int n,m;
int data[N];

void MakeTree(int x,int l,int r)
{
	tree[x].l=l;
	tree[x].r=r;
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

void Add(int v,int x,int y)//��ʾxҪ����y�����ڴ����v 
{
	tree[v].val+=y;
	if(tree[v].l==tree[v].r)
		return;
	if(x<=tree[v].mid)
		Add(v*2,x,y);
	else
		Add(v*2+1,x,y);
}

int Find(int v,int a,int b)//��ʾ��[a,b]�ĺͣ����ڴ����v 
{
	if(tree[v].l==a && tree[v].r==b)
		return tree[v].val;
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
	for(i=n;i>=1;i--)
		data[i]-=data[i-1];
	MakeTree(1,1,n);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		int opt,a,b,c;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d%d",&a,&b,&c);
			Add(1,a,c);
			if(b<n)
				Add(1,b+1,-c);
		}
		else
		{
			scanf("%d",&a);
			printf("%d\n",Find(1,1,a));
		}
	}
}




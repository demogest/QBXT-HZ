#include<cstdio>
const int N = 50050;
int m;
int fa[N],tot[N],dis[N];
void getf(int x)	//ֻ��·��ѹ�������ã���x�����ϵ����е�ĸ��ڵ㶼�ĳɸ��ڵ� 
{
	if(x==fa[x])
		return;
	getf(fa[x]);
	dis[x]+=dis[fa[x]];
	fa[x]=fa[fa[x]];
}
int main()
{
	int i;
	scanf("%d",&m);
	for(i=1;i<N;i++)	//��ʼ�����鼯 
	{
		fa[i]=i;
		tot[i]=1;
		dis[i]=0;
	}
	for(i=1;i<=m;i++)	//������� 
	{
		int s,t;
		char opt;
		scanf(" %c%d%d",&opt,&s,&t);
		if(opt=='M')
		{
			getf(s);
			getf(t);
			int a=fa[s];
			int b=fa[t];
			fa[a]=b;
			dis[a]=tot[b];	//dis[a]��ʾa��b�ľ��루a��ǰ���ٸ�ս����b�� 
			tot[b]+=tot[a];
		}
		else
		{
			getf(s);
			getf(t);
			int a=fa[s];
			int b=fa[t];
			int res;
			if(a!=b)
				res=-1;
			else
			{
				res=dis[s]-dis[t];
				if(res<0)
					res=-res;
				res--;
			}
			printf("%d\n",res);
		}
	}
	return 0;
}

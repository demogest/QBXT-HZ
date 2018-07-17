#include<cstdio>
const int N = 50050;
int m;
int fa[N],tot[N],dis[N];
void getf(int x)	//只起到路径压缩的作用：将x到根上的所有点的父节点都改成根节点 
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
	for(i=1;i<N;i++)	//初始化并查集 
	{
		fa[i]=i;
		tot[i]=1;
		dis[i]=0;
	}
	for(i=1;i<=m;i++)	//读入操作 
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
			dis[a]=tot[b];	//dis[a]表示a到b的距离（a向前多少个战舰是b） 
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

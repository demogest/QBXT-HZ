#include<cstdio>

const int P = 500;//i/p�ǿ�ı�� 
const int N = 200500;

int val[N];
long long sum[N];//sum[i]��ʾ��i���������ĺ� 
long long add[N];//add[i]��ʾ��i���������Ӧ���ټ���add[i] 
int tot[N];//��i����tot[i]���� 
int n,m;

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
		sum[i/P]+=val[i];
		tot[i/P]++;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		int opt,a,b,c;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a/P==b/P)
			{
				for(j=a;j<=b;j++)
				{
					val[j]+=c;
					sum[j/P]+=c;
				}
			}
			else
			{
				for(j=a;j/P==a/P;j++)
				{
					val[j]+=c;
					sum[j/P]+=c;
				}
				for(j=b;j/P==b/P;j--)
				{
					val[j]+=c;
					sum[j/P]+=c;
				}
				for(j=a/P+1;j<b/P;j++)
				{
					sum[j]+=(long long)(tot[j])*c;
					add[j]+=c;
				}
			}
		}
		else
		{
			long long ans=0;
			scanf("%d%d",&a,&b);
			if(a/P==b/P)
			{
				for(j=a;j<=b;j++)
					ans+=val[j]+add[j/P];
			}
			else
			{
				for(j=a;j/P==a/P;j++)
					ans+=val[j]+add[j/P];
				for(j=b;j/P==b/P;j--)
					ans+=val[j]+add[j/P];
				for(j=a/P+1;j<b/P;j++)
					ans+=sum[j];
			}
			printf("%lld\n",ans);
		}
	}
	
	
}

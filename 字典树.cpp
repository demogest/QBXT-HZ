#include<cstdio>
#include<cstring>
struct Node
{
	Node *son[26];
	bool isword;
}xu[1000005];
Node *root=xu+1;
int cc=1;

char word[1000];
int n,m;

void Add(Node *v, int now, int len)
{
	if(now==len)
	{
		v->isword=1;
		return;
	}
	char ch=word[now]-'a';
	if(!v->son[ch])
	{
		cc++;
		v->son[ch]=xu+cc;
	}
	Add(v->son[ch],now+1,len);
}

bool Find(Node *v, int now, int len)
{
	if(now==len)
		return v->isword;
	char ch=word[now]-'a';
	if(!v->son[ch])
		return 0;
	Find(v->son[ch],now+1,len);
}

int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",word);
		int len=strlen(word);
		Add(root,0,len);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%s",word);
		int len=strlen(word);
		if(Find(root,0,len))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

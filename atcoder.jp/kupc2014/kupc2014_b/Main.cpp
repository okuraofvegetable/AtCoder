#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define pb push_back
bool prime[1010];
vector<int> p;
int ans=1;
char judge[2];
void eratos()
{
	memset(prime,true,sizeof(prime));
	for(int i=2;i*i<=1000;i++)
	{
		if(prime[i])
		{
			for(int j=i*2;j<=1000;j+=i)prime[j]=false;
		}
	}
	for(int i=2;i<=1000;i++)if(prime[i])p.pb(i);
	return;
}
void query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%s",judge);
	return;
}
void enter(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	return;
}
int main()
{
	eratos();
	for(int i=0;i<p.size();i++)
	{
		if(ans*p[i]>1000)break;
		int x=p[i];
		for(;x<=1000;x*=p[i])
		{
			query(x);
			if(judge[0]=='N')break;
		}
		ans*=x/p[i];
	}
	enter(ans);
	return 0;
}

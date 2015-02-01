#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
#define MOD 1000000007ll
int A[100100],D[100100];
int imos[3010][3010];
ll inv[100100];
ll facinv[100100];
ll fac[100100];
int N,K;
void preculc()
{
	inv[0]=1;inv[1]=1;
	for(int i=2;i<=100000;i++)inv[i]=MOD-((MOD/i)*inv[MOD%i])%MOD;
	facinv[0]=1;facinv[1]=1;
	for(int i=2;i<=100000;i++)facinv[i]=(facinv[i-1]*inv[i])%MOD;
	fac[0]=0;fac[1]=1;
	for(int i=2;i<=100000;i++)fac[i]=(fac[i-1]*i)%MOD;
}
ll nCr(int n,int r)
{
	if(n<r)return 0ll;
	if(n<0||r<0)return 0ll;
	return (((fac[n]*facinv[r])%MOD)*facinv[n-r])%MOD;
}
int sum(int i,int j,int k,int l)
{
	return imos[k][l]-imos[i-1][l]-imos[k][j-1]+imos[i-1][j-1];
}
bool check(int x)
{
	for(int i=1;i<=3005-x;i++)
	{
		for(int j=1;j<=3005-x;j++)
		{
			if(sum(i,j,i+x,j+x)>=K)return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d %d",&N,&K);
	preculc();
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&A[i],&D[i]);
		imos[A[i]+1][D[i]+1]++;
	}
	for(int i=0;i<=3005;i++)
	{
		for(int j=0;j<=3005;j++)
		{
			imos[i][j+1]+=imos[i][j];
		}
	}
	for(int j=0;j<=3005;j++)
	{
		for(int i=0;i<=3005;i++)
		{
			imos[i+1][j]+=imos[i][j];
		}
	}
	if(K==1)
	{
		printf("0\n");
		printf("%d\n",N);
		return 0;
	}
	int l=-1,r=3005;
	while(r-l>1)
	{
		int mid = (l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	ll ans = 0ll;
	for(int i=1;i<=3002-r;i++)
	{
		for(int j=1;j<=3002-r;j++)
		{
			if(sum(i,j,i+r,j+r)<K)continue;
			int c = sum(i,j,i,j);
			int all = sum(i,j,i+r,j+r);
			ans = (ans + (nCr(all,K)-nCr(all-c,K)+MOD)%MOD)%MOD;
			if(r==0)continue;
			int left = sum(i+1,j,i+r,j);
			int up = sum(i,j+1,i,j+r);
			//printf("%d %d %d %d\n",c,left,up,all);
			ans = (ans+nCr(all-c,K))%MOD;
			ans = (ans+MOD-nCr(all-c-left,K))%MOD;
			ans = (ans+MOD-nCr(all-c-up,K))%MOD;
			ans = (ans+nCr(all-c-left-up,K))%MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

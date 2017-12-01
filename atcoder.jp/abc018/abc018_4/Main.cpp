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
#define rep(i,x) for(int i=0;i<x;i++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,M,P,Q,R;
int x[400],y[400],z[400];
int happy[20];
int sum[20][20];
int main()
{
	scanf("%d %d %d %d %d",&N,&M,&P,&Q,&R);
	rep(i,R)
	{
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
		x[i]--;y[i]--;
		sum[x[i]][y[i]]=z[i];
	}
	int ans = 0;
	for(int i=0;i<(1<<N);i++)
	{
		int res = 0;
		if(__builtin_popcount(i)!=P)continue;
		memset(happy,0,sizeof(happy));
		for(int j=0;j<N;j++)if((i>>j)&1)
		{
			for(int k=0;k<M;k++)
			{
				happy[k]+=sum[j][k];
			}
		}
		vector<int> vec;
		for(int j=0;j<M;j++)vec.pb(happy[j]);
		sort(all(vec),greater<int>());
		for(int j=0;j<Q;j++)res += vec[j];
		ans = max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}
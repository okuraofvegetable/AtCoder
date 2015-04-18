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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
const int SIZE = 110;
struct UnionFind
{
	int par[SIZE],rank[SIZE],flag[SIZE];
	void init(int n)
	{
		int i;
		for(i=0;i<n;i++)
		{
			par[i] = i;
			rank[i] = 0;
			flag[i]=1;
		}
	}
	int find(int x)
	{
		if(par[x] == x)
		{
			return x;
		}
		else
		{
			return par[x] = find(par[x]);
		}
	}
	void unite(int x,int y)
	{
		x = find(x);
		y = find(y);
		if(x==y)
		{
			flag[x]=0;
			return;
		}
		if(rank[x] < rank[y])
		{
			par[x] = y;
		}
		else
		{
			par[y] = x;
			if(rank[x] == rank[y])rank[x]++;
		}	
	}
	bool same(int x,int y)
	{
		return find(x) == find(y);
	}
}uf;
int main()
{
	int N,M;
	cin >> N >> M;
	uf.init(N);
	for(int i=0;i<M;i++)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		uf.unite(a,b);
	}
	int ans = 0;
	for(int i=0;i<N;i++)if(uf.par[i]==i&&uf.flag[i])ans++;
	cout << ans << endl;
	return 0;
}

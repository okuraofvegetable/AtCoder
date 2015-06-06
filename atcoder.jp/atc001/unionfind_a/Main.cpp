#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 100100;
struct UnionFind
{
	int par[SIZE],rank[SIZE];
	void init(int n)
	{
		int i;
		for(i=0;i<n;i++)
		{
			par[i] = i;
			rank[i] = 0;
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
		if(x==y)return;
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
int N,Q;
int main()
{
	cin >> N >> Q;
	uf.init(N+10);
	for(int i=0;i<Q;i++)
	{
		int p,a,b;
		cin >> p >> a >> b;
		if(p==0)uf.unite(a,b);
		else
		{
			if(uf.same(a,b))printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}

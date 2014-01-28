#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
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
#define EQ(a,b) (abs((a)-(b))<EPS)
vector<int> g[100010];
int motivation[100010];
int sum[100010];
int n,root=0;
int dfs(int v)
{
	int ret=motivation[v];
	for(int i=0;i<g[v].size();i++)
	{
		int tmp=dfs(g[v][i]);
		if(tmp>0)ret+=tmp;
	}
	return sum[v]=ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int par;
		cin >> par >> motivation[i];
		if(par)g[--par].pb(i);
	}
	dfs(root);
	int ans=-INF;
	for(int i=0;i<n;i++)ans=max(ans,sum[i]);
	//for(int i=0;i<n;i++)cout << sum[i] << endl;
	cout << ans << endl;
	return 0;
}

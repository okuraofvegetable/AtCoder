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
int N,M;
vector<int> g[100100];
bool used[100100];
void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<g[v].size();i++)if(!used[g[v][i]])dfs(g[v][i]);
	return;
}
int main()
{
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(used,false,sizeof(used));
	int cnt = 0;
	for(int i=0;i<N;i++)if(!used[i])
	{
		dfs(i);
		cnt++;
	}
	cout << cnt-1 << endl;
	return 0;
}

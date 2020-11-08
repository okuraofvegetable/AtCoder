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
#define EQ(a,b) (abs((a)-(b))<EPS)
vi lis[101];
int cnt=0;
int p=1;
bool used[101];
void dfs(int s)
{
	int i,j;
	for(i=0;i<lis[s].size();i++)
	{
		if(!(used[lis[s][i]]))
		{
			used[lis[s][i]]=true;
			p++;
			dfs(lis[s][i]);
		}
		if(p>2)cnt=max(cnt,p);
	}
	used[s]=false;
	p--;
	return ;
}
int main()
{
	int e;
	//while(1)
	{
		cnt=0;
		cin >> e;
		//if(e==0)break;
		int mv=-1;
		for(int i=0;i<101;i++)
		{
			lis[i].clear();
		}
		for(int i=0;i<e;i++)
		{
			int a,b;
			cin >> a >> b;
			mv=max(mv,max(a,b));
			lis[a].pb(b);
			lis[b].pb(a);
		}
		for(int i=1;i<=mv;i++)
		{
			p=1;
			memset(used,0,sizeof(used));
			used[i]=true;
			dfs(i);
		}	
		cout << cnt << endl;
	}
	return 0;
}

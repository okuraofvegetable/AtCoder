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
int flu[100100];
P city[100100];
int map[1005][1005];
int n,m,d,k;
int sq(int x){return x*x;}
bool can(int a,int b)
{
	return (sq(city[a].fi-city[b].fi)+sq(city[a].sec-city[b].sec))<=sq(d);
}
int main()
{
	cin >> n;
	cin >> m;
	cin >> d;
	cin >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> city[i].fi >> city[i].sec;
		map[city[i].fi][city[i].sec]=i;
	}
	fill(flu,flu+n+1,INF);
	flu[1]=0;
	queue<P> q;
	q.push(mp(1,0));
	while(!q.empty())
	{
		P a=q.front();
		q.pop();
		for(int i=max(0,city[a.fi].fi-d);i<=min(999,city[a.fi].fi+d);i++)
		{
			for(int j=max(0,city[a.fi].sec-d);j<=min(999,city[a.fi].sec+d);j++)
			{
				if(!map[i][j])continue;
				if(can(a.fi,map[i][j]))
				{
					if(flu[map[i][j]]>a.sec+1)
					{
						flu[map[i][j]]=a.sec+1;
						q.push(mp(map[i][j],flu[map[i][j]]));
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(flu[i]>k-m&&flu[i]<=k)ans++;
	cout << ans << endl;
	return 0;
}

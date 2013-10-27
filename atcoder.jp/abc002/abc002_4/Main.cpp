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
bool k[20][20];
int n,m;
bool c(vector<int> x)
{
	for(int i=0;i<x.size();i++)
	{
		for(int j=i+1;j<x.size();j++)
		{
			if(!k[x[i]][x[j]])return false;
		}
	}
	return true;
}
int main()
{
	memset(k,0,sizeof(k));
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		k[x][y]=true;
		k[y][x]=true;
	}
	int t=(1<<12)-1;
	int ans=1;
	while(t)
	{
		vector<int> p;
		for(int i=0;i<12;i++)
		{
			if((t>>i)&1)p.pb(i+1);
		}
		if(c(p))ans=max(ans,((int)p.size()));
		t--;
	}
	cout << ans << endl;
	return 0;
}

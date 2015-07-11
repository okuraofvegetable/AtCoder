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
int p[100];
int maxi[100],mini[100],ans[100];
vector<int> g[100];
void culc(int x)
{
	if(g[x].size()==0)
	{
		ans[x]=1;
		if(p[x]!=-1)
		{
			mini[p[x]]=min(mini[p[x]],1);
			maxi[p[x]]=max(maxi[p[x]],1);
		}
		return;
	}
	for(int i=0;i<g[x].size();i++)culc(g[x][i]);
	ans[x] = mini[x]+maxi[x]+1;
	if(p[x]!=-1)
	{
		mini[p[x]]=min(mini[p[x]],ans[x]);
		maxi[p[x]]=max(maxi[p[x]],ans[x]);
	}
	return;
}
int main()
{
	int n;
	cin >> n;
	p[0]=-1;
	for(int i=1;i<n;i++)
	{
		cin >> p[i];p[i]--;
		g[p[i]].pb(i);
	}
	for(int i=0;i<n;i++)
	{
		maxi[i]=-INF;
		mini[i]=INF;
	}
	culc(0);
	//for(int i=0;i<n;i++)cout << ans[i] << endl;
	cout << ans[0] << endl;
	return 0;
}

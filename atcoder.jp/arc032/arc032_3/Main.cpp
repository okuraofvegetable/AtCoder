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
typedef pair<P,int> T;
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
int N;
int last;
int a[100100],b[100100];
vector<int> vx;
vector<P> vec;
P dp[200100];
P rec(int x)
{
	if(x==last)return dp[x]=P(0,-INF);
	if(dp[x]!=P(-1,-1))return dp[x];
	P a = rec(x+1);
	int k = lower_bound(all(vec),P(x,0))-vec.begin();
	while(k<N&&vec[k].fi==x)
	{
		P f = rec(b[vec[k].sec]);
		a = max(a,P(f.fi+1,-vec[k].sec));
		k++;
	}
	return dp[x]=a;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		vx.pb(a[i]);
		vx.pb(b[i]);
	}
	sort(all(vx));
	vx.erase(unique(all(vx)),vx.end());
	for(int i=0;i<N;i++)
	{
		a[i]=lower_bound(all(vx),a[i])-vx.begin();
		b[i]=lower_bound(all(vx),b[i])-vx.begin();
		vec.pb(P(a[i],i));
	}
	sort(all(vec));
	last = (int)vx.size()-1;
	for(int i=0;i<=last;i++)dp[i]=P(-1,-1);
	for(int i=0;i<=last;i++)rec(i);
	//for(int i=0;i<=last;i++)cout << dp[i].fi << ' ' << dp[i].sec << endl;
	cout << dp[0].fi << endl;
	int now = 0;
	for(int i=0;i<dp[0].fi;i++)
	{
		if(now!=0)printf(" ");
		printf("%d",-dp[now].sec+1);
		now = b[-dp[now].sec];
	}
	printf("\n");
	return 0;
}

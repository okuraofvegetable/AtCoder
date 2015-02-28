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
int main()
{
	int N;
	scanf("%d",&N);
	vector<P> dist,ans;
	for(int i=2;i<=N;i++)
	{
		printf("? %d %d\n",1,i);
		fflush(stdout);
		int d;
		scanf("%d",&d);
		dist.pb(P(d,i));
	}
	sort(all(dist),greater<P>());
	for(int i=1;i<=N;i++)
	{
		if(i==dist[0].sec)continue;
		printf("? %d %d\n",dist[0].sec,i);
		fflush(stdout);
		int d;
		scanf("%d",&d);
		ans.pb(P(d,i));
	}
	sort(all(ans),greater<P>());
	printf("! %d\n",ans[0].fi);
	return 0;
}

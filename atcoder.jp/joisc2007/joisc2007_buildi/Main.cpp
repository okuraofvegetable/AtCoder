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
int main()
{
	int dp[1200];
	fill(dp,dp+1200,INF);
	int ans=0;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int k;
		cin >> k;
		int pos=lower_bound(dp,dp+n,k)-dp;
		dp[pos]=k;
		ans=max(pos,ans);
	}
	cout << ans+1 << endl;
	return 0;
}

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
ll N;
ll f(ll x)
{
	ll res = 0ll;
	while(x)
	{
		res += x%10ll;
		x/=10ll;
	}
	return res;
}
int main()
{
	cin >> N;
	vector<ll> ans;
	for(ll i=max(1ll,N-200ll);i<=N;i++)
	{
		if(i+f(i)==N)ans.pb(i);
	}
	cout << ans.size() << endl;
	rep(i,ans.size())printf("%lld\n",ans[i]);
	return 0;
}

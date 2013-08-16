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
typedef long long ll;
typedef pair<int,ll> P;
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
int K,N;
set<P> s;
bool used(P node)
{
	int p;
	ll q;
	p=node.fi;
	q=node.sec;
	p--;
	q=(q+1LL)/2LL;
	while(p>=0)
	{
		if(s.find(P(p,q))!=s.end())
		{
			return true;
		}
		p--;
		q=(q+1LL)/2LL;
	}
	return false;
}
int main()
{
	cin >> K;
	cin >> N;
	ll ans=(1LL<<((ll)K+1LL))-1LL;
	for(int i=0;i<N;i++)
	{
		int a;
		ll b;
		cin >> a >> b;
		s.insert(P(a,b));
	}
	set<P>::iterator it;
	for(it=s.begin();it!=s.end();++it)
	{
		if(!used(*it))ans-=(1LL<<((ll)K+1LL-(ll)(*it).fi))-1LL;
	}
	cout << ans << endl;
	return 0;
}

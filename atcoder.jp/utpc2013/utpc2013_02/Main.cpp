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
#define INF 2000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
ll sum;
bool C(ll p)
{
	//cout << (p+14ll)*(p-13ll)/2ll << endl;
	return (p+14ll)*(p-13ll)/2ll<sum;
}
int main()
{
	ll y,m;
	cin >> y >> m;
	if(y==2013&&m==12)
	{
		cout << "2013 12" << endl;
		return 0;
	}
	if(y==2014&&m==1)
	{
		cout << "2013 13" << endl;
		return 0;
	}
	sum=12ll*(y-2014ll)+m-1;
	//cout << sum << endl;
	if(sum<=14)
	{
		cout << "2014 " << sum << endl;
		return 0;
	}
	ll l=14ll,r=INF;
	while(r-l>1ll)
	{
		ll mid=(l+r)/2ll;
		if(C(mid))l=mid;
		else r=mid;
	}
	/*cout << l << ' ';
	C(l);
	cout << endl;*/
	cout << 2001ll+l << ' ' << sum-(l+14ll)*(l-13ll)/2ll << endl;
	return 0;
}

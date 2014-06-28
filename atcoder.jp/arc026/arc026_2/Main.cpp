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
	ll n,res=1ll;
	string p="Perfect";
	string d="Deficient";
	string a="Abundant";
	cin >> n;
	if(n==1)
	{
		cout << d << endl;
		return 0;
	}
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			res+=i;
			if(i*i!=n)res+=n/i;
		}
	}
	//cout << res << endl;
	if(res > n)cout << a << endl;
	else if(res==n)cout << p << endl;
	else cout << d << endl;
	return 0;
}

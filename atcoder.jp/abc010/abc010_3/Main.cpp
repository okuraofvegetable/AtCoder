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
int txa,tya,txb,tyb,t,v,n;
P girl[1010];
double p(double d){return d*d;}
bool check(int i)
{
	return sqrt(p((double)txa-girl[i].fi)+p((double)tya-girl[i].sec))+sqrt(p((double)txb-girl[i].fi)+p((double)tyb-girl[i].sec)) <= t*v;
}
int main()
{
	cin >> txa >> tya >> txb >> tyb >> t >> v;
	cin >> n;
	for(int i=0;i<n;i++)cin >> girl[i].fi >> girl[i].sec;
	for(int i=0;i<n;i++)
	{
		if(check(i))
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}

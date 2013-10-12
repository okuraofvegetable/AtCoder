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
	double m;
	cin >> m;
	m/=1000;
	if(m<0.1)
	{
		cout << "00" << endl;
		return 0;
	}
	if(0.1<=m&&m<1)
	{
		cout << 0 << m*10 << endl;
		return 0;
	}
	if(m>=1&&m<=5)
	{
		cout <<m*10 << endl;
		return 0;
	}
	if(6<=m&&m<=30)
	{
		cout << m+50 << endl;
		return 0;
	}
	if(35<=m&&m<=70)
	{
		cout <<(m-30)/5+80<<endl;
		return 0;
	}
	if(70<m)
	{
		cout << 89 << endl;
		return 0;
	}
	return 0;
}
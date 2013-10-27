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
#include <iomanip>
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
	double x[3],y[3];
	for(int i=0;i<3;i++)
	{
		cin >> x[i] >> y[i];
	}
	x[1]-=x[0];
	x[2]-=x[0];
	y[1]-=y[0];
	y[2]-=y[0];
	cout << setprecision(16)<<fabs(x[1]*y[2]-y[1]*x[2])/2.0 << endl;
	return 0;
}
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int A,B,C;
double f(double x)
{
	return (double)A*x+(double)B*sin((double)C*x*M_PI);
}
int main()
{
	cin >> A >> B >> C;
	double l = 0.0, r = 1000.0;
	for(int i=0;i<500;i++)
	{
		double mid = (l+r)/2.0;
		if(f(mid)<100.0)l=mid;
		else r = mid;
	}
	cout << setprecision(16) << r << endl;
	return 0;
}

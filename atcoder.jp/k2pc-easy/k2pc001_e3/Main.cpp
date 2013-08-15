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
#define EQ(a,b) (abs((a)-(b))<EPS)
P cal(int s)
{
	int p=1;
	while(s>p*(p+1)/2)
	{
		p++;
	}
	int k=s-(p)*(p-1)/2;
	return P(p+1-k,k);
}
int solve(int m,int n)
{
	return (m+n-1)*(m+n-2)/2+n;
}
int main()
{
	int i,j;
	cin >> i >> j;
	P a=cal(i);
	P b=cal(j);
	cout << solve(a.fi+b.fi,a.sec+b.sec) << endl;
	return 0;
}

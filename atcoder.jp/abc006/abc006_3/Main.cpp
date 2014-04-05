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
	int n,m;
	cin >> n >> m;
	if(m>n*4||m<n*2)
	{
		cout << "-1 -1 -1" << endl;
		return 0;
	}
	if(m==n*3)
	{
		printf("0 %d 0\n",n);
		return 0;
	}
	else if(m>n*3)
	{
		printf("0 %d %d\n",n-(m-n*3),(m-n*3));
		return 0;
	}
	else
	{
		printf("%d %d 0\n",n-(m-n*2),(m-n*2));
		return 0;
	}
	return 0;
}

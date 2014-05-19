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
ll days(int y,int m,int d)
{
	return 365*y+(y/4)-(y/100)+(y/400)+((306*(m+1))/10)+d-429;
}
int main()
{
	int y,m,d;
	cin >> y >> m >> d;
	if(m<=2)y--,m+=12;
	//cout << days(y,m,d) << endl;
	cout << days(2014,5,17)-days(y,m,d) << endl;
	return 0;
}

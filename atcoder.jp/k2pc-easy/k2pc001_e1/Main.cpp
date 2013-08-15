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
int main()
{
	int a,b,c;
	int n;
	cin >> a >> b >> c;
	cin >> n;
	a-=n;
	b-=2*n;
	c-=3*n;
	if(a>0)a=0;
	if(b>0)b=0;
	if(c>0)c=0;
	if(a<0)a*=-1;
	if(b<0)b*=-1;
	if(c<0)c*=-1;
	printf("%d %d %d\n",a,b,c);
	return 0;
}

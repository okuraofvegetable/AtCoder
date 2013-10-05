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
int c[6];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		double a,b;
		cin >> a >> b;
		if(a>=35)c[0]++;
		if(a>=30&&a<35)c[1]++;
		if(a>=25&&a<30)c[2]++;
		if(b>=25)c[3]++;
		if(b<0&&a>=0)c[4]++;
		if(a<0)c[5]++;
	}
	printf("%d %d %d %d %d %d\n",c[0],c[1],c[2],c[3],c[4],c[5]);
	return 0;
}

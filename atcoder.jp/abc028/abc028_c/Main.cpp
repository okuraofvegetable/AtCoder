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
int a[100];
int main()
{
	for(int i=0;i<5;i++)cin >> a[i];
	vector<int> v;
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			for(int k=j+1;k<5;k++)
			{
				v.pb(a[i]+a[j]+a[k]);
			}
		}
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	sort(all(v),greater<int>());
	cout << v[2] << endl;
	return 0;
}

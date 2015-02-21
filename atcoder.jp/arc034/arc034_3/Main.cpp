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
#define MOD 1000000007
map<int,int> m;
int main()
{
	int A,B;
	cin >> A >> B;
	vector<int> v;
	for(int i=B+1;i<=A;i++)
	{
		int k = i;
		for(int j=2;j*j<=i;j++)
		{
			if(k%j==0)
			{
				while(k%j==0)
				{
					k/=j;
					m[j]++;
				}
			}
		}
		if(k!=1)m[k]++;
	}
	ll ans = 1ll;
	map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		//cout << it->fi << ' ' << it->sec << endl;
		ans = ans*(it->sec+1)%MOD;
	}
	cout << ans << endl;
	return 0;
}

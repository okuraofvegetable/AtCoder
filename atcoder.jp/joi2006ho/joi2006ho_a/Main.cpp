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
vector<P> p;
vi num;
int main()
{
	int n,m;
	while(cin >> n >> m&&(n||m))
	{
		p.clear();
		num.clear();
		for(int i=m;i>0;i--)
		{
			p.pb(P(0,i));
			num.pb(0);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int t;
				cin >> t;
				p[j].fi+=t;
			}
		}
		sort(p.rbegin(),p.rend());
		for(int i=0;i<p.size();i++)
		{
			cout << 1+m-p[i].sec;
			if(i==p.size()-1)
			{
				cout << endl;
			}
			else
			{
				cout << ' ';
			}
		}
        return 0;
	}
	return 0;
}

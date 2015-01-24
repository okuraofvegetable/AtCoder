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
#define EQ(a,b) (abs((a)-(b))<eps)
int main()
{
	string s,t;
	cin >> s;
	ll cnt = 0;
	ll ans = 0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='2'&&s[i+1]=='5')
		{
			ans += cnt+1;
			cnt++;
			i++;
		}
		else cnt = 0;
	}
	cout << ans << endl;
	return 0;
}

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
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A')
		{
			s[i]='X';
		}
		else if(s[i]=='B')
		{
			s[i]='Y';
		}
		else if(s[i]=='C')
		{
			s[i]='Z';
		}
		else
		{
			s[i]-=3;
		}
	}
	cout << s << endl;
	return 0;
}

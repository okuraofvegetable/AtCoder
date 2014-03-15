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
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='O')s[i]='0';
		if(s[i]=='D')s[i]='0';
		if(s[i]=='I')s[i]='1';
		if(s[i]=='Z')s[i]='2';
		if(s[i]=='S')s[i]='5';
		if(s[i]=='B')s[i]='8';
	}
	cout << s << endl;
	return 0;
}
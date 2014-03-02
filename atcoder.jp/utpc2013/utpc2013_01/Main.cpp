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
string s0="CEFGHIJKLMNSTUVWXYZ";
string s1="ADOPQR";
string s2="B";
string s3="UTPC";
int check(string s)
{
	if(s0.find(s[0])!=string::npos)return 0;
	if(s1.find(s[0])!=string::npos)return 1;
	if(s2.find(s[0])!=string::npos)return 2;
	return -1;
}
int main()
{
	string ss;
	cin >> ss;
	string sa,sb;
	bool same=true;
	for(int i=0;i<ss.size();i++)
	{
		sa.clear();
		sb.clear();
		sa+=ss[i];
		sb+=s3[i];
		if(check(sa)!=check(sb))
		{
			same=false;
			break;
		}
	}
	if(same)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
	return 0;
}

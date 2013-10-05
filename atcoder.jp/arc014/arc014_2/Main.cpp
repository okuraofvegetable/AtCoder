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
	int vs=-1;
	set<string> s;
	int n;
	cin >> n;
	string tmp;
	for(int i=0;i<n;i++)
	{
		string str;
		cin >> str;
		if(s.find(str)!=s.end())
		{
			vs=i;
			break;
		}
		s.insert(str);
		if(i!=0)
		{
			if(tmp[tmp.size()-1]!=str[0])
			{
				vs=i;
				break;
			}
		}
		tmp=str;
	}
	if(vs==-1)
	{
		cout << "DRAW" << endl;
		return 0;
	}
	if(vs%2==0)
	{
		cout << "LOSE" << endl;
	}
	else
	{
		cout << "WIN" << endl;
	}
	return 0;
}

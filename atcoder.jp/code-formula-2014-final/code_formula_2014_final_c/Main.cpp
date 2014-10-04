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
vector<string> user;
int main()
{
	string s,kara;
	getline(cin,s);
	int i=0;
	for(i=0;i<s.size();i++)
	{
		string name;
		if(s[i]=='@')
		{
			while(s[++i]>='a'&&s[i]<='z')
			{
				name+=s[i];
			}
			i--;
			if(name!=kara)user.pb(name);
			//cout << "|" << name << "|" << endl;
		}
	}
	sort(user.begin(),user.end());
	user.erase(unique(user.begin(),user.end()),user.end());
	for(int i=0;i<user.size();i++)cout << user[i] << endl;
	return 0;
}

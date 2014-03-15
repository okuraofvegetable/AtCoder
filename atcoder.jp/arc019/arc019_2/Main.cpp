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
bool a[300100];
int main()
{
	int ans=0;
	string s;
	cin >> s;
	if(s.size()==1)
	{
		cout << 0 << endl;
		return 0;
	}
	ans=25*s.size();
	int cnt=0; 
	for(int i=0;i<s.size();i++)if(s[i]==s[s.size()-i-1])cnt++;
	if(cnt==s.size()&&s.size()%2==1)
	{
		cout << ans-25 << endl;
		return 0;
	}
	if(cnt==s.size()-2)
	{
		cout << ans-2 << endl;
		return 0;
	}
	else cout << ans << endl;
	return 0;
}

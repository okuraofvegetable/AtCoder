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
int ans=0;
int main()
{
	string s1,s2;
	while(cin >> s1 >> s2)
	{
		ans=0;
		for(int i=0;i<s1.size();i++)
		{
			int cnt=0;
			for(int j=0;j<min(s1.size()-i,s2.size());j++)
			{
				if(s2[j]==s1[j+i])
				{
					cnt++;
					ans=max(ans,cnt);	
				}
				else
				{
					cnt=0;
				}
			}
		}
		for(int i=0;i<s2.size();i++)
		{
			int cnt=0;
			for(int j=0;j<min(s2.size()-i,s1.size());j++)
			{
				if(s1[j]==s2[j+i])
				{
					cnt++;
					ans=max(ans,cnt);
				}
				else
				{
					cnt=0;
				}
			}
		}
		cout << ans << endl;
		s1.clear();
		s2.clear();
	}
	return 0;
}

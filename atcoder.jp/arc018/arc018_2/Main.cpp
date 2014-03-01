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
P point[105];
bool check(int a,int b,int c)
{
	ll p1=point[b].fi-point[a].fi;
	ll p2=point[b].sec-point[a].sec;
	ll q1=point[c].fi-point[a].fi;
	ll q2=point[c].sec-point[a].sec;
	ll sum=abs(p1*q2-q1*p2);
	if(sum==0||sum%2==1)return false;
	return true;
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)cin >> point[i].fi >> point[i].sec;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(check(i,j,k))ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

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
int R,C,D;
int ans=0;
int f[1010][1010];
int path[1010][1010];
int main()
{
	cin >> R >> C >> D;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin >> f[i][j];
		}
	}
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(i+1<R)path[i+1][j]=path[i][j]+1;
			if(j+1<C)path[i][j+1]=path[i][j]+1;
		}
	}
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if((i+j)%2!=D%2)continue;
			if(path[i][j]>D)continue;
			ans=max(ans,f[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}

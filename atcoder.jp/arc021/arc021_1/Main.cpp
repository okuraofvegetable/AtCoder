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
int f[6][6];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main()
{
	bool dead=true;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			cin >> f[i][j];
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			for(int k=0;k<4;k++)
			{
				int nx=i+dx[k],ny=j+dy[k];
				if(f[i][j]==f[nx][ny])
				{
					dead=false;
					goto end;
				}
			}
		}
	}
	end:;
	if(dead)cout << "GAMEOVER" << endl;
	else cout << "CONTINUE" << endl;
	return 0;
}

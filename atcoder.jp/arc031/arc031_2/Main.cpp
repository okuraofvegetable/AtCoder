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
string s[10],t[10];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void copy()
{
	for(int i=0;i<10;i++)t[i]=s[i];
	return;
}
void dfs(int x,int y)
{
	t[x][y]='x';
	for(int i=0;i<4;i++)
	{
		int nx = x+dx[i],ny = y+dy[i];
		if(nx<0||nx>=10||ny<0||ny>=10)continue;
		if(t[nx][ny]=='o')dfs(nx,ny);
	}
}
bool judge()
{
	copy();
	int sx,sy;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(s[i][j]=='o')
			{
				sx=i,sy=j;
				goto e;
			}
		}
	}
	e:;
	dfs(sx,sy);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(t[i][j]=='o')return false;
		}
	}
	return true;
}
int main()
{
	for(int i=0;i<10;i++)cin >> s[i];
	bool flag = false;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(s[i][j]!='x')continue;
			s[i][j]='o';
			flag = judge();
			s[i][j]='x';
			if(flag)goto end;
		}
	}
	end:;
	if(flag)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}